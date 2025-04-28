#include <stdio.h>
struct employee
{
	int empcode;
	char name[100];
	int doj;
};
int main()
{
	int n,curdate,i;
	printf("Enter how many employee: ");
	scanf("%d",&n);
	struct employee emp[n];
	for (i = 0 ; i < n ; i++)
	{
		printf("Enter employee %d code: ",i+1);
		scanf("%d",&emp[i].empcode);
		printf("Enter employee %d name: ",i+1);
		getchar();
		gets(emp[i].name);
		printf("Enter year of joining of employee no.%d: ",i+1);
		scanf("%d",&emp[i].doj);
	}
	printf("Enter the current year: ");
	scanf("%d",&curdate);
	printf("The employees with a tenure of 3 or greater are:\n");
	for (i = 0 ; i < n ; i++)
	{
		if ((curdate - emp[i].doj) >= 3)
		{
			printf("%s\n",emp[i].name);
		}
	}
}
