#include <stdio.h>
int main()
{
	int accnum, n;
	float startbal,price,tot,totcred,credlim,newbal;
	while (true)
	{
		tot = 0;
		newbal = 0;
		printf("Enter account number (-1 to end): ");
		scanf("%d",&accnum);
		if (accnum == -1)
		{
			break;
		}
		printf("Enter beginning balance: ");
		scanf("%f",&startbal);
		printf("How many products you would like to Enter: ");
		scanf("%d",&n);
		for (int i = 1 ; i <= n ; i++)
		{
			printf("Enter charges for item %d: ",i);
			scanf("%f",&price);
			tot = tot + price; 
		}
		printf("\nYour total: %f",tot);
		printf("\nEnter total credits: ");
		scanf("%f",&totcred);
		printf("Enter credit limit: ");
		scanf("%f",&credlim);
		
		printf("\nAccount: %d",accnum);
		printf("\nCredit limit: %f",credlim);
		newbal = startbal - tot + totcred;
		printf("\nBalance: %f\n",newbal);
		if (newbal < credlim)
		{
			printf("Credit Limit Not Exceeded.\n\n");
		}
		else
		{
			printf("Credit limit exceeded by %f.\n\n",newbal - credlim);
		}
		printf("-------------------------------------------\n\n");
	}
}

