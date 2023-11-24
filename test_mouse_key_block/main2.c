//this file show how: read mouse and keyboard in for(;;)
//this way can read both value at the same time
//but it use cpu almost 100%


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MOUSE "/dev/input/event3"

int main(void)
{
	char buf[100];
	int fd;
	int ret;
	int flag;
	
	
	fd = open(MOUSE,O_RDONLY|O_NONBLOCK);
	if(fd==-1)
	{
		perror("open error");
		exit(-1);
	}
	
	/*
	将键盘设置为非阻塞方式
	因为文件默认是阻塞方式打开，所以需要改变打开文件的方式
	采用fcntl函数即可
	*/
	
	flag = fcntl(0,F_GETFL);//标准输入设备默认的fd为0,而且不需要打开，直接使用即可。
	flag|=O_NONBLOCK;//位或的方式添加非阻塞模式
	fcntl(0,F_SETFL,flag);//重新设置flag
	int cnt=0;
	for(;;)
	{
		ret = read(fd,buf,sizeof(buf));
		if(ret > 0)
		{
			printf("mouse read %d bytes \n ",ret);
		}
		cnt++;
		printf("cnt: %d \n",cnt);
		ret = read(0,buf,sizeof(buf));
		if(ret > 0)
		{
			printf("keyboard read %d bytes \n ",ret);
		}
	}
	
	
	close(fd);
	exit(0);
	
}






