#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>

int main(int argc, char** argv)
{
	syscall(449);
	//Where 449 is the position of the system call entered into the table
}
