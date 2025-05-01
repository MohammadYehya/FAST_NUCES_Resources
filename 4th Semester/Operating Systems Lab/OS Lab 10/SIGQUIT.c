#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sig_handler(int signo)
{
	if (signo == SIGINT)
	printf("\nreceived SIGINT\n");
	else if (signo == SIGQUIT)
	printf("\nreceived SIGQUIT\n");
}
int main(void)
{
	if (signal(SIGINT, sig_handler) == SIG_ERR)
	printf("\ncan't catch SIGINT\n");
	if (signal(SIGQUIT, sig_handler) == SIG_ERR)
	printf("\ncan't catch SIGQUIT\n");
	while(1) sleep(1);
	return 0;
}
