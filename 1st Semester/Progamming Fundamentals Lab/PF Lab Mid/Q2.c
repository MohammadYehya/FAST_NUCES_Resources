#include <stdio.h>
int main()
{
	int yr, month, date, brthyr, days, CNIC;
	printf("Please enter your birth year: ");
	scanf("%d",&brthyr);
	if (2021 - brthyr > 18)
	{
		printf("Please enter CNIC number: ");
		scanf("%d",&CNIC);
		printf("Please enter the year as of today: ");
		scanf("%d",&yr);
		printf("Please enter the month(number) as of today: ");
		scanf("%d",&month);
		printf("Please enter the date as of today: ");
		scanf("%d",&date);
		switch (month)
		{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				days = 31;
				break;
			case 2:
				days = 28;
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				days = 30;
				break;
		}
		printf("\n\nThe Information of CNIC: %d  are as follows:\n\n",CNIC);
		if (date+2 > days)
		{
			if (month == 12)
			{
				month = 1;
				printf("You will recieve your acount number on %d/%d/%d",date+2-days,month,yr+1);
			}
			else
			{
				printf("You will recieve your acount number on %d/%d/%d",date+2-days,month+1,yr);
			}
		}
		else 
		{
			printf("You will recieve your acount number on %d/%d/%d",date+2,month,yr);
		}
		
		
		if (date + 7 > days)
		{
			if (month == 12)
			{
				month = 1;
				printf("\nYou will recieve your check book on %d/%d/%d",date+7-days,month,yr);
				printf("\nYou will recieve your ATM card on %d/%d/%d",date+7-days,month + 1,yr);
			}
			else 
			{
				printf("\nYou will recieve your check book on %d/%d/%d",date+7-days,month+1,yr);
				if (month == 11)
				{
					month = 1;
					printf("\nYou will recieve your ATM card on %d/%d/%d",date+7-days,month,yr);	
				}
				else
				{
					printf("\nYou will recieve your ATM card on %d/%d/%d",date+7-days,month+2,yr);
				}
			}
		}
		else 
		{
			printf("\nYou will recieve your check book on %d/%d/%d",date+7,month,yr);
			if (month == 12)
				{
					month = 1;
					printf("\nYou will recieve your ATM card on %d/%d/%d",date+7,month,yr);	
				}
				else
				{
					printf("\nYou will recieve your ATM card on %d/%d/%d",date+7,month+1,yr);
				}
		}
		
	}
	else 
	{
		printf("You are not eligible!");
	}
}


