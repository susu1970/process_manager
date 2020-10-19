#ifndef SUSU1970_PROCESS_H_
#define SUSU1970_PROCESS_H_

#include"headers/process_type.h"
#include<string>
#include<sys/types.h>   
#include<unistd.h>
#include<list>
#include<signal.h>

namespace susu1970_process_manager{
  class Process{
    std::string description;
    void initDescription(ProcessType pt){
      switch(pt){
      case ProcessTypeDefault:
	description="type: default process\n";break;
      case ProcessTypeMaster:
	description="type: master process\n";break;
      case ProcessTypeSub:
	description="type: sub process\n";break;
      default:
	description="type: unknown process\n";break;
      }
    }
  public:
    ProcessType processType;
    pid_t pid,ppid;
    list<Process *>subprocessList;
    int processSubscript;//process id (the subscript in its parent's subprocessList,-1 when it is a master process),not the pid
    std::string description(){
      return description+"pid: "+pid+"\nppid: "+ppid+"\nprocessSubscript: "+processSubscript+"\n";      
    }
    Process(pid_t ppid,ProcessType pt=ProcessTypeDefault)processType:(pt),ppid:(ppid){
      initDescription(pt);
      //also start a process with processId
      
      TODO!
    }
    void addSubprocess(short count=1,ProcessType processType=ProcessTypeSub){
      for(short i=0;i<count;++i)
	subprocessList.push_back(new Process(pid,processType));
    }
    void deleteSubprocess(short count=1,ProcessType processType=ProcessTypeSub){
      //delete at most count number subprocesses 
      if(subprocessList.empty())return;
      if(count<0){//delete all sub-processes with type processType
	count=subprocessVec.size();
      }
      for(auto iter=subprocessList.begin();count>0&&iter!=subprocessList.end();--count){
	if((*iter)->processType==processType){
	  delete(*iter);//real delete operation
	  iter=subprocessList.erase(iter);
	}else
	  ++iter;
      }
    }
    void deleteSubprocessWithSub(int sub){//delete sub-process by subscript 
      for(auto iter=subprocessList.begin();count>0&&iter!=subprocessList.end();--count){
	if((*iter)->processSubscript==sub){
	  delete(*iter);//real delete operation
	  iter=subprocessList.erase(iter);
	}else
	  ++iter;
      }
    }
    ~Process(){//also close the process with pid "pid"
      TODO!
    }
  }
}

#endif

















