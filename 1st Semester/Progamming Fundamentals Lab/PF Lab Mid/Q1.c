#include <stdio.h>
int main()
{
	int amount,total=0,check=0,buscheck=0,agecheck=0;
	printf("Enter number of people who will stay at the hotel: ");
	scanf("%d",&amount);
	switch(amount)
	{
		case 1:
			printf("Invalid Input!");
			break;
		case 2:
			total = 1000;
			printf("Hotel cost for %d people is: %d",amount,total);
			check = 1;
			break;
		case 3:
			total = 1250;
			printf("Hotel cost for %d people is: %d",amount,total);
			check = 1;
			break;
		case 4:
			total = 1450;
			printf("Hotel cost for %d people is: %d",amount,total);
			check = 1;
			break;
		default:
			total = 1450 + 100*(amount - 4);
			printf("Hotel cost for %d people is: %d",amount,total);
			check = 1;
			break;
	}
	if (check == 1)
	{
		printf("\n-------DISCOUNT--------\nPress 1 if you are staying on company business: ");
		scanf("%d",&buscheck);
		printf("Press 2 if all of you are above 60: ");
		scanf("%d",&agecheck);
		if (buscheck == 1 && agecheck != 2)
		{
			printf("You get a discount of 20 Percent \nYour discounted Hotel price is %f",total * 0.8);
		}
		else if (buscheck != 1 && agecheck == 2)
		{
			printf("You get a discount of 15 Percent \nYour discounted Hotel price is %f",total * 0.85);
		}
		else if (buscheck == 1 && agecheck == 2)
		{
			printf("Sorry, no discount");
		}
	}
	
}

