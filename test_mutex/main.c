#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

static int g_count = 0;
static pthread_mutex_t mutex;

static void *new_thread_start(void *arg)
{
	int loops = *((int *)arg);
	int l_count;
	int j;
	
	//pthread_mutex_lock is blcok
	//pthread_mutex_lock(&mutex);
	
	//pthread_mutex_trylock is unblock
	//pthread_mutex_trylock 
	
	for(j=0;j<loops;j++)
	{
		pthread_mutex_lock(&mutex);
		//while(pthread_mutex_trylock(&mutex));
		l_count=g_count;
		l_count++;
		g_count=l_count;
		pthread_mutex_unlock(&mutex);
	}
	
	
	return (void *)0;
}

static int loops;
int main(int argc,char *argv[])
{
	pthread_t tid1;
	pthread_t tid2;
	int ret;
	
	if(argc<2)
	{
		loops=10000000;
	}	
	else
	{
		loops=atoi(argv[1]);
	}
	//create two new thread
	ret = pthread_create(&tid1,NULL,new_thread_start,&loops);
	if(ret)
	{
		fprintf(stderr,"pthread_create error: %s\n",strerror(ret));
		exit(-1);
	}
	ret = pthread_create(&tid2,NULL,new_thread_start,&loops);
	if(ret)
	{
		fprintf(stderr,"pthread_create error: %s\n",strerror(ret));
		exit(-1);
	}
	
	//wait thread stop
	ret = pthread_join(tid1,NULL);
	if(ret)
	{
		fprintf(stderr,"pthread_jion error: %s\n",strerror(ret));
		exit(-1);
	}
	ret = pthread_join(tid2,NULL);
	if(ret)
	{
		fprintf(stderr,"pthread_jion error: %s\n",strerror(ret));
		exit(-1);
	}
	printf("g_count = %d\n",g_count);
	exit(0);
	
}
























