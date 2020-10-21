#include"interface/process.h"
#include<unistd.h>
#include<stdio.h>
#include<iostream>
#include<string>
#include<sys/types.h>

using namespace std;
using susu1970_process_manager::Process;

static Process*process = new Process(-1,-1,ProcessTypeMaster);//ppid or processSubscript == -1,represent this is a master process
static string initHintMessage="This is the master process\n\nq: quit\nh: help\np a: print all sub-processes's information\np (number): print sub-process with subscript(process id,but not pid)\na (number(the number of sub-process to create)) (type(0:ProcessTypeSub),default is 0): add number sub-processes with type\nd (number) (type,default is 0): delete number sub-processes with type\nk (number):kill sub-process with subscript \"number\"\n";

void initProcess(){
  process->pid=getpid();
  
}
string getCmdUnit(const string&cmd,size_t&start){
  size_t len=cmd.length(),sub=start,next;
  while(sub<len&&(cmd[sub]==' '||cmd[sub]=='\t'))++sub;
  if(sub>=len){
    start=sub;
    return"";//no more command unit
  }
  next=sub+1;
  while(next<len&&cmd[next]!=' '&&cmd[next]!='\t')++next;
  start=next;  
  return cmd.substr(sub,next-sub);
}

int main(int argc,char**argv){
  initProcess();
  cout<<initHintMessage<<endl;
  string cmd="";
  while(getline(cin,cmd)&&cmd!="q"){//receive the command from terminal
    size_t start=0,len=cmd.length();
    int cmdOrder=0;
    string cmdUnit="";
    string prevCmdUnit="";
    while(start<len){
      if((cmdUnit=getCmdUnit(cmd,start))=="")break;	
      if(cmdOrder==0){
	if(cmdUnit=="h"){
	  cout<<initHintMessage<<endl;
	}
      }else if(cmdOrder==1){
	if(prevCmdUnit=="p"){
	  if(cmdUnit=="a"){//print all sub-processes's information
	    cout<<process->allSubprocessesInfo()<<endl;
	  }
	}else if(prevCmdUnit=="a"){
	  int processCount=atoi(cmdUnit.c_str());
	  process->addSubprocess(processCount);
	}else if(prevCmdUnit=="d"){
	  int processCount=atoi(cmdUnit.c_str());
	  process->deleteSubprocess(processCount);
	}else if(prevCmdUnit=="k"){
	  int subscript=atoi(cmdUnit.c_str());
	  process->deleteSubprocessWithSubscript(subscript);
	}	
      }
      prevCmdUnit=cmdUnit;
      ++cmdOrder;
    }
  }
}



















