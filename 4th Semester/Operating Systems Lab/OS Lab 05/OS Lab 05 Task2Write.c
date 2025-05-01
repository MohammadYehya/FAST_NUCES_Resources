#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>

int main(void) {
	int fd, retval;
	char buffer[] = "this is the operating system last lab before mid... mid paper will be on Saturday 30th October,2021";
	fflush(stdin);
	retval = mkfifo("/tmp/myfifo",0666);
	fd = open("/tmp/myfifo",O_WRONLY);
	for(int i = 0 ; i < 3 ; i++) write(fd,buffer,sizeof(buffer));
	close(fd);
	return 0;
}
