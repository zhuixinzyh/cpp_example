//this file is show : read mouse and then read keyboard by block ways
//must read keyboard after read mouse
//cann't read key and mouse in one time

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


#define MOUSE "/dev/input/event3"

int main(void)
{
	char buf[100];
	int fd;
	int ret;
	
	// open mouse device file
	fd = open(MOUSE,O_RDONLY);
	if(fd == -1)
	{
		perror("open error\n");
		exit(-1);
	}
	
	//read mouse value
	//memset is to reset buf memory
	memset(buf,0,sizeof(buf));
	ret = read(fd,buf,sizeof(buf));
	printf("mouse read %d byte\n",ret);
	
	//read keyboard
	memset(buf,0,sizeof(buf));
	ret=read(0,buf,sizeof(buf));
	printf("keyboard read %d byte\n",ret);
	
	//close file
	close(fd);
	exit(0);
	
	
}
