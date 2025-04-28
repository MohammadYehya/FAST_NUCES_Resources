#include <stdio.h>
int main()
{
	//Q6
	char type;
	printf("Please enter your prefered type of coffee: ");
	scanf("%c",&type);
	switch(type)
	{
		case 'B':
			printf("Put Water\t20 mins\nSugar\t\t20 mins\nMix Well\t25 mins\nAdd Coffee\t15 mins\nAdd Milk\t   -\nMix Well\t25 well");
			break;
		case 'W':
			printf("Put Water\t15 mins\nSugar\t\t15 mins\nMix Well\t20 mins\nAdd Coffee\t2 mins\nAdd Milk\t4 mins\nMix Well\t20 mins");
			break;
		default:
			printf("Please enter either B or W");
	}
}
