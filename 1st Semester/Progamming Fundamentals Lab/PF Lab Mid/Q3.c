#include <stdio.h>
int main()
{
	int amount,type,hrs,items,i;
	printf("Enter the number of employees: ");
	scanf("%d",&amount);
	for (i = 1 ; i <= amount ; i++)
	{
		printf("\nEnter the code for the employee type: ");
		scanf("%d",&type);
		switch(type)
		{
			case 1:
				printf("Managers salary for the week is: %d",10500);
				break;
			case 2:
				printf("Enter hours worked: ");
				scanf("%d",&hrs);
				if (hrs > 30)
				{
					printf("Salary with overtime is: %d",3000 + 200*(hrs - 30));
				}
				else 
				{
					printf("Salary without overtime is: %d",100 * hrs);
				}
				break;
			case 3:
				printf("Commision workers salary for the week is: %f",250 * 7 + 650 * 1.05);
				break;
			case 4:
				printf("Enter the number of items produced: ");
				scanf("%d",&items);
				printf("Salary of pieceworker is %d",500*items);
				break;
			default:
				printf("Invalid Input!");
				break;
		}
	}
}

