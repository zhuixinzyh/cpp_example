#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <signal.h>
using namespace std;

//signal handler function
static void sig_handler(int sig)
{
	cout<<"recv signal is:"<<sig<<endl;
}

int main(int argc,char *argv[])
{
	cout<<"test linux signal"<<endl;
	cout<<"argc is "<<argc<<endl;
	for(int i=0;i<argc;i++)
	{
		cout<<i<<" -- ";
		cout<<argv[i]<<endl;
	}
	
	sig_t ret=NULL;
	ret=signal(SIGINT,(sig_t)sig_handler);
	if(SIG_ERR==ret)
	{
		cout<<"signal error"<<endl;
		exit(-1);
	}
	
	for(;;){};
	
	
	cout<<"main done "<<endl;
	exit(0);
}
