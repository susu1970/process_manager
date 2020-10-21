#include"interface/process.h"
#include<iostream>
#include<string>
#include<sys/types.h>
#include<unistd.h>

using namespace std;
using susu1970_process_manager::Process;

static Process*process=nullptr;
static int ppid,pid,processSubscript;

static string processMessage(){
  return "process_sub:\n(pid:"+to_string(pid)+",ppid:"+to_string(ppid)+",processSubscript:"+to_string(processSubscript)+")";
}
static void sig_int(int){
  cout<<processMessage()<<"\nexited"<<endl;
}

int main(int argc,char**argv){
  if(argc<3)cerr<<"usage: <"<<argv[0]<<"> <ppid> <processSubscript>"<<endl,exit(1);
  ppid=atoi(argv[1]);
  processSubscript=atoi(argv[2]);
  pid=getpid();
  cout<<processMessage()<<"\nstarted\n"<<endl;
  if(signal(SIGINT,sig_int)==SIG_ERR)
    cout<<processMessage()<<"\nsignal:sig_int error\n"<<endl;
  pause();
}


















