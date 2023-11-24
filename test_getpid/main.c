#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

extern char **environ;

static void bye(void)
{
	cout<<"good bye"<<endl;
}
int main(int argc,char *argv[])
{
	cout<<argc<<endl;
	for(int i=0;i<argc;i++)
	{
		cout<<argv[i]<<endl;
	}
	//bind function which will excute when exit this progesss
	if(atexit(bye))
	{
		cout<<"set atexit function failed"<<endl;
		return -1;
	}	
	
	//show this progress and it's father progress pid
	pid_t pid=getpid();
	cout<<"this progress pid is "<<pid<<endl;
	pid=getppid();
	cout<<"this father progres pid is "<<pid<<endl;
	
	//show this progress env
	for(int i=0;environ[i]!=NULL;i++)
	{
		//cout<<environ[i]<<endl;
	}

	//get we want env
	const char *str_val=NULL;
	str_val=getenv("PWD");
	cout<<"this progress pwd is "<<str_val<<endl;

	return 0;
}
