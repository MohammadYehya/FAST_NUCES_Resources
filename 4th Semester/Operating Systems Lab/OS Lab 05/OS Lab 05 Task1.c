#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include <sys/wait.h>

int main(void) {
	int pipefd[2];
	int pid;
	char buffer[30];
	pipe(pipefd);
	pid = fork();
	
/*
Changes in code:	-changed buffer size from 15->30
			-switched roles from Parent->Child to Child->Parent
*/

	if(pid > 0) {
		sleep(2);
		fflush(stdin);
		printf("unamed_pipe [INFO] Parent Process\n");
		read(pipefd[0], buffer, sizeof(buffer));
		write(1,buffer, sizeof(buffer));
		printf("\n");	
	}
	else if(pid == 0) {
		fflush(stdin);
		printf("unamed_pipe [INFO] Child Process\n");
		write(pipefd[1],"Hello, My name Mohammad Yehya!",30);
	}
	else {
		printf("unamed_pipe [ERROR] Error in creating child process\n");	
	}
	if(pid > 0) wait(NULL);
	return 0;
}
