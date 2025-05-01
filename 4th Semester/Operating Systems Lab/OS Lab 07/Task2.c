#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *Tables(void *num)
{
	for(int i = 0 ; i <= 1000 ; i++) printf("%ld x %d = %ld\n", (long)num, i, (long)num * i);
	pthread_exit(0);
}
int main(int argc, char *argv[], char *envp[])
{
	pthread_t t[4];
	for(int i = 0 ; i <= 3 ; i++) pthread_create(&t[i], NULL, Tables, (void*)(long)(i+5));
	for(int i = 0 ; i <= 3 ; i++) pthread_join(t[i], NULL);
	return 0;
}
