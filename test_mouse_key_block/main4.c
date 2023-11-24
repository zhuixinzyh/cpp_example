#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>

#define MOUSE "/dev/input/event3"

static int fd;

static void sigio_handler(int sig)
{
	printf("handler go\n");
	static int loops = 5;
	char buf[100]={0};
	int ret;
	
	if(SIGIO!=sig)
	{
		return;
	}
	ret = read(fd,buf,sizeof(buf));
	if(ret>0)
	{
		printf("mouse read %d bytes\n",ret);
	}
	loops--;
	if(loops<=0)
	{
		close(fd);
		exit(0);
	}
}


int main(void)
{
	int flag;
	
	//open mouse file nonblock mode
	fd = open(MOUSE,O_RDONLY|O_NONBLOCK);
	if(-1==fd)
	{
		perror("open mouse error");
		exit(-1);
	}
	//enable async mode
	flag = fcntl(fd,F_GETFL);
	flag |=O_ASYNC;
	fcntl(fd,F_SETFL,flag);
	
	//set async io owner
	fcntl(fd,F_SETOWN,getpid());
/* 为 SIGIO 信号注册信号处理函数 */
signal(SIGIO, sigio_handler);
for ( ; ; )
sleep(1);
}










