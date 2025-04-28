#include <stdio.h>
int main()
{
	int types,amount4=0,amount3=0,amount2=0,amount1=0,flag=1,total=0;
	char choice4,choice3,choice2,choice1;
	printf("\t\t\t\t\tABC Restaurant Online Order Placement\n\t\t\t\t\t\t\tWELCOME!\nPlease select from the following Menu");
	printf("\nB = Burger\t\tRs.200\nF = French Fries\tRs.50\nP = Pizza\t\tRs.500\nS = Sandwiches\t\tRs.150");
	printf("\nHow many types of snacks you need to order: ");
	scanf("%d",&types);
	switch(types) // Purposely didn't add break so that if the user enters 4 it would do 4 times and if the user enter 3 it would do 3 times and so on.
	{
		case 4:
			printf("Enter type of snack you want to order: ");
			scanf(" %c",&choice4);
			printf("Please provide quantity: ");
			scanf("%d",&amount4);
		case 3:
			printf("Enter type of snack you want to order: ");
			scanf(" %c",&choice3);
			printf("Please provide quantity: ");
			scanf("%d",&amount3);
		case 2:
			printf("Enter type of snack you want to order: ");
			scanf(" %c",&choice2);
			printf("Please provide quantity: ");
			scanf("%d",&amount2);
		case 1:
			printf("Enter type of snack you want to order: ");
			scanf(" %c",&choice1);
			printf("Please provide quantity: ");
			scanf("%d",&amount1);
			break;
		default:
			printf("You can only enter a maximum of 4 types!");
			flag = 0;
			break;
	}
	if (flag == 1)
	{
		printf("------------------------------------------\nYou have ordered!\n");
		switch (types)
		{
			case 4:
				if (choice4 == 'B')
				{
					printf("%d Burger (s) value %d PKR",amount4,amount4*200);
					total = total + amount4*200;
				}
				else if (choice4 == 'F')
				{
					printf("%d French Fries value %d PKR",amount4,amount4*50);
					total = total + amount4*50;
				}
				else if (choice4 == 'P')
				{
					printf("%d Pizza (s) value %d PKR",amount4,amount4*500);
					total = total + amount4*500;
				}
				else if (choice4 == 'S')
				{
					printf("%d SandWich (s) value %d PKR",amount4,amount4*150);
					total = total + amount4*150;
				}
			case 3:
				if (choice3 == 'B')
				{
					printf("\n%d Burger (s) value %d PKR",amount3,amount3*200);
					total = total + amount3*200;
				}
				else if (choice3 == 'F')
				{
					printf("\n%d French Fries value %d PKR",amount3,amount3*50);
					total = total + amount3*50;
				}
				else if (choice3 == 'P')
				{
					printf("\n%d Pizza (s) value %d PKR",amount3,amount3*500);
					total = total + amount3*500;
				}
				else if (choice3 == 'S')
				{
					printf("\n%d SandWich (s) value %d PKR",amount3,amount3*150);
					total = total + amount3*150;
				}
			case 2:
				if (choice2 == 'B')
				{
					printf("\n%d Burger (s) value %d PKR",amount2,amount2*200);
					total = total + amount2*200;
				}
				else if (choice2 == 'F')
				{
					printf("\n%d French Fries value %d PKR",amount2,amount2*50);
					total = total + amount2*50;
				}
				else if (choice2 == 'P')
				{
					printf("\n%d Pizza (s) value %d PKR",amount2,amount2*500);
					total = total + amount2*500;
				}
				else if (choice2 == 'S')
				{
					printf("\n%d SandWich (s) value %d PKR",amount2,amount2*150);
					total = total + amount2*150;
				}
			case 1:
				if (choice1 == 'B')
				{
					printf("\n%d Burger (s) value %d PKR",amount1,amount1*200);
					total = total + amount1*200;
				}
				else if (choice1 == 'F')
				{
					printf("\n%d French Fries value %d PKR",amount1,amount1*50);
					total = total + amount1*50;
				}
				else if (choice1 == 'P')
				{
					printf("\n%d Pizza (s) value %d PKR",amount1,amount1*500);
					total = total + amount1*500;
				}
				else if (choice1 == 'S')
				{
					printf("\n%d SandWich (s) value %d PKR",amount1,amount1*150);
					total = total + amount1*150;
				}
		}
		printf("\nTotal: %d\nThank you for your order... have a nice day.",total);
	}
}
