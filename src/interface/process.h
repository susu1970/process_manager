#ifndef SUSU1970_PROCESS_MANAGER_PROCESS_H_
#define SUSU1970_PROCESS_MANAGER_PROCESS_H_

#include"headers/process_type.h"
#include<iostream>
#include<string>
#include<sys/types.h>   
#include<unistd.h>
#include<list>
#include<signal.h>
#include<sstream>

namespace susu1970_process_manager{
  class Process{
    void initDescription(ProcessType pt){
      switch(pt){
      case ProcessTypeDefault:
	description_init="type: default process\n";break;
      case ProcessTypeMaster:
	description_init="type: master process\n";break;
      case ProcessTypeSub:
	description_init="type: sub process\n";break;
      default:
	description_init="type: unknown process\n";break;
      }
    }
    std::string description_init="";
    std::list<Process *>subprocessList;
  public:
    ProcessType processType;
    pid_t pid,ppid;
    int processSubscript;//process id (the subscript in its parent's subprocessList,-1 when it is a master process),not the pid,if the previous process in its parent's subprocessList has been deleted,the processSubscript will not change
    Process(pid_t ppid,int processSubscript,ProcessType pt=ProcessTypeDefault):processType(pt),ppid(ppid),processSubscript(processSubscript){
      initDescription(pt);
      //also start a process with processId
      if(pt==ProcessTypeSub){
	pid_t sub_pid=vfork();
	using std::string,std::to_string;
	if(!sub_pid){//sub-process
	  string ppid_str=to_string(ppid);
	  string processSubscript_str=to_string(processSubscript);
	  execl("./process_sub","process_sub",ppid_str.c_str(),processSubscript_str.c_str(),nullptr);
	  exit(0);
	}
	pid=sub_pid;	
      }
    }
    std::string description(){
      return description_init+"pid: "+std::to_string(pid)+"\nppid: "+std::to_string(ppid)+"\nprocessSubscript: "+std::to_string(processSubscript)+"\n";      
    }
    void addSubprocess(short count=1,ProcessType processType=ProcessTypeSub){
      for(short i=0;i<count;++i)
	subprocessList.push_back(new Process(pid,subprocessList.size(),processType));
    }
    void deleteSubprocess(short count=1,ProcessType processType=ProcessTypeSub){
      //delete at most count number subprocesses 
      if(subprocessList.empty())return;
      if(count<0){//delete all sub-processes with type processType
	count=subprocessList.size();
      }
      for(auto iter=subprocessList.begin();count>0&&iter!=subprocessList.end();--count){
	if((*iter)->processType==processType){
	  delete(*iter);//real delete operation
	  iter=subprocessList.erase(iter);
	}else
	  ++iter;
      }
    }
    std::string allSubprocessesInfo(){
      //print the description of all sub-processes in the subprocessList
      int processCount=subprocessList.size();
      using std::string,std::to_string;
      string printMessage="There are "+to_string(processCount)+" sub-process"+(processCount>1?"es":"")+"\n";
      int subprocessOrder=0;
      for(Process*process:subprocessList)
	printMessage+=("sub-process:"+to_string(subprocessOrder++)+"\n"+process->description()+"\n");
      return printMessage;
    }
    void deleteSubprocessWithSubscript(int sub){//delete sub-process by subscript 
      for(auto iter=subprocessList.begin();iter!=subprocessList.end();){
	if((*iter)->processSubscript==sub){
	  delete(*iter);//real delete operation
	  iter=subprocessList.erase(iter);
	}else
	  ++iter;
      }
    }
    ~Process(){//also close the process with pid "pid"
      if(processType==ProcessTypeSub){
	if(kill(pid,SIGINT)==-1)
	  std::cerr<<"kill "<<pid<<" error"<<std::endl;
	for(Process*process:subprocessList)
	  delete process;	
      }
    }
  };
}

#endif

















