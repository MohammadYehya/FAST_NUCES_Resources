#include <stdio.h>
#include <pthread.h>

int main(int argc, char* argv[], char* envp[])
{
	pthread_mutex_t myMutex;
	pthread_mutexattr_t myMutexAttr;
	pthread_mutexattr_init(&myMutexAttr);
	pthread_mutexattr_setpshared(&myMutexAttr, PTHREAD_PROCESS_SHARED);
	
	pthread_mutex_init(&myMutex, &myMutexAttr);
	pthread_mutex_destroy(&myMutex);
	return 0;
}
