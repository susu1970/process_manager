#include"interface/process.h"
#include<iostream>
#include<string>
#include<sys/types.h>
#include<unistd.h>

using namespace std;
using susu1970_process_manager::Process;

static Process*process;

int main(int argc,char**argv){
  if(argc<3)cerr<<"usage: <"<<argv[0]<<"> <ppid> <processSubscript>"<<endl,exit(1);
  pid_t ppid=atoi(argv[1]);
  int processSubscript=atoi(argv[2]);
  process=new Process(ppid,processSubscript,ProcessTypeSub);
}


















