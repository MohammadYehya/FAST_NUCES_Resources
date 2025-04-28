#include <stdio.h>
int main()
{
	int n;
	float marks,max=0,min=99999,sum=0;
	printf("Please enter the number of students in the class: ");
	scanf("%d",&n);
	for (int i = 1 ; i<= n ; i++)
	{
		printf("Please enter the marks for student No.%d: ",i);
		scanf("%f",&marks);
		if (marks>max)
		{
			max = marks;
		}
		if (marks<min)
		{
			min = marks;
		}
		sum = sum + marks;
	}
	printf("The highest marks in the class is %f\n",max);
	printf("The lowest marks in the class is %f\n",min);
	printf("The average of the class is %f",sum/n);
}

