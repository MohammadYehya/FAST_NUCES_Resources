#include <stdio.h>
#include <string.h>
int main()
{
	char fname[100],lname[100];
	printf("Enter first name: ");
	gets(fname);
	printf("Enter last name: ");
	gets(lname);
	strcat(fname," ");
	strcat(fname,lname);
	printf("Your full name backwards is %s",strrev(fname));
}

