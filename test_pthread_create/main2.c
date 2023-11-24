#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

static void *new_thread_start(void *arg)
{
	sleep(1);
	printf("New thread: progress id <%d>, new thread id <%d>\n",getpid(),pthread_self());
	
	pthread_exit(NULL);
	//return (void *)0;
}

int main(void)
{
	pthread_t tid;
	int ret;
	ret = pthread_create(&tid, NULL, new_thread_start, NULL);
	if(ret)
	{
		fprintf(stderr,"ERROR:%s\n",strerror(ret));
		exit(-1);
	}
	
	printf("progress id <%d>, new thread id <%d>\n",getpid(),pthread_self());
	pthread_exit(NULL);
	exit(0);
}
