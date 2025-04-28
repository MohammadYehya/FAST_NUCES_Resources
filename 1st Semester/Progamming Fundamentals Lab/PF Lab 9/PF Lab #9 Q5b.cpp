#include <stdio.h>
int toQualityPoints(int _avg);
int main()
{
	int avg;
	printf("Enter your average: ");
	scanf("%d",&avg);
	printf("%d",toQualityPoints(avg));
	
}
int toQualityPoints(int _avg)
{
	switch(_avg)
	{
		case 90 ... 100:
			return 4;
			break;
		case 80 ... 89:
			return 3;
			break;
		case 70 ... 79:
			return 2;
			break;
		case 60 ... 69:
			return 1;
			break;
		case 0 ... 59:
			return 0;
			break;
		default:
			return -1;
			break;
	}
}

