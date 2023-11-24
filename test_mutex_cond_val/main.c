#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>


static pthread_mutex_t mutex;
static pthread_cond_t cond;

static int g_avail=0;

static void *consumer_thread(void *arg)
{
	for(;;)
	{
		
		pthread_mutex_lock(&mutex);
		
		while(0>=g_avail)
			pthread_cond_wait(&cond,&mutex);
		
		while(g_avail>0)
		{
			usleep(100);
			printf("consumer : g_avail is %d\n",g_avail);
			g_avail--;
		}
			
			
		pthread_mutex_unlock(&mutex);
	}
	return (void *)0;
}

int main(int argc,char *argv[])
{
	pthread_t tid;
	int ret;
	
	pthread_mutex_init(&mutex,NULL);
	pthread_cond_init(&cond,NULL);
	
	
	ret = pthread_create(&tid,NULL,consumer_thread,NULL);
	if(ret)
	{
		fprintf(stderr,"pthread_create failed:%s\n",strerror(ret));
		exit(-1);
	}
	for(;;)
	{
		pthread_mutex_lock(&mutex);
		usleep(100);
		g_avail++;
		printf("main : g_avail is %d\n",g_avail);
		pthread_mutex_unlock(&mutex);
		
		pthread_cond_signal(&cond);
	}
	exit(0);
}
