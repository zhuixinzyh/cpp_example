#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/file.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

using namespace std;


#define LOCK_FILE "./testApp.pid"


int main(int argc,char *argv[])
{
	char str[20]={};
	int fd;
	
	//open lock file
	fd=open(LOCK_FILE,O_WRONLY|O_CREAT,0666);
	if(-1==fd)
	{
		cout<<"open error"<<endl;
		exit(-1);
	}
	// get lockfile's lock
	if(-1==flock(fd,LOCK_EX|LOCK_NB))
	{
		cout<<"cann't excute again"<<endl;
		close(fd);
		exit(-1);
	}
	
	cout<<"progress excuting"<<endl;
	
	ftruncate(fd,0);
	sprintf(str,"%d\n",getpid());
	//cout<<"progress pid is "<<getpid()<<endl;
	write(fd,strlen(str));
	for(;;)
	{
		sleep(1);	
	}
	
	cout<<"done"<<endl;
	exit(0);
}
