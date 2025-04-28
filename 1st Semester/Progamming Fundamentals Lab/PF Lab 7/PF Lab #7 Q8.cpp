#include <stdio.h>
#include <string.h>
int main()
{
	//Miss allowed the use of string.h
	char name[5],pass[6],*p;
	char caps[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char nocaps[]="abcdefghijklmnopqrstuvwxyz";
	char spec[]=" !#$%&'()*+,-./:;<=>?@[\]^_`{|}~";
	int flag1,flag2,flag3;
	do
	{
		printf("Please enter your user name(Must be 5 alphabets): ");
		scanf("%s",&name);
	}
	while (strlen(name)!=5);
	do
	{
		flag1,flag2,flag3 =0;
		printf("Please enter your password(Must be 6 characters long with at least 1 numeric, 1 capital and 1 small letter.): ");
		scanf("%s",&pass);
		p = strpbrk(pass,caps);
		if (p!=NULL)
		{
			flag1 = 1;
		}
		p = strpbrk(pass,nocaps);
		if (p!=NULL)
		{
			flag2 = 1;
		}
		p = strpbrk(pass,spec);
		if (p!=NULL)
		{
			flag3 = 1;
		}
	}
	while (strlen(pass)!=6 && (flag1 == 0 && flag2 == 0 && flag3 == 0));
	
}

