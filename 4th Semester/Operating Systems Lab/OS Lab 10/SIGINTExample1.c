#include<stdio.h>
#include<unistd.h>
#include<wait.h>
#include<signal.h>
int state=1;
void signal_handler(int num)
{
	printf("I am here because Ctrl+c was pressed\n");
}
int main()
{
	signal(SIGINT, signal_handler);
	while(1)
	{
		sleep(1);
		printf("Process Running \n");
	}
	return 0;
}
