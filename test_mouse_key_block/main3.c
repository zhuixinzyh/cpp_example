//this file use IO multiplexing to read mouse and keyboard at the same time but cann't use cpu almost% 
// use select function, 


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/select.h>

#define MOUSE "/dev/input/event3"

int main(void)
{
	char buf[100];
	int fd;
	int ret=0;
	int flag;
	fd_set rdfds;
	int loops=10;
	
	//open mouse file
	fd = open(MOUSE,O_RDONLY|O_NONBLOCK);
	if(fd == -1)
	{
		perror("open mouse error\n");
		exit(-1);
	}
	
	//set keyboard nonblock mode
	flag = fcntl(0,F_GETFL);
	flag|=O_NONBLOCK;
	fcntl(0,F_SETFL,flag);
	
	//read mouse and keyboard at the same time
	while(loops--)
	{
		FD_ZERO(&rdfds);
		FD_SET(0,&rdfds);
		FD_SET(fd,&rdfds);
		ret = select(fd+1,&rdfds,NULL,NULL,NULL);
		if(ret<0)
		{
			perror("select error");
			goto out;
		}
		else if(0==ret)
		{
			fprintf(stderr,"select timeout \n");
			continue;
		}
		
		//check keyboard ready state
		if(FD_ISSET(0,&rdfds))
		{
			ret = read(0,buf,sizeof(buf));
			if(0<ret)
			{
				printf("key read %d bytes\n",ret);
			}
		}
		
		//check mouse ready state
		if(FD_ISSET(fd,&rdfds))
		{
			ret = read(fd,buf,sizeof(buf));
			if(ret>0)
			{
				printf("mouse read %d bytes\n",ret);
			}
		}

		
		
	
	}
		out:
		close(fd);
		exit(ret);	
	
}






