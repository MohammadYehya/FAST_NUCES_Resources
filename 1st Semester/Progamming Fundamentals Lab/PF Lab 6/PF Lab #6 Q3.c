#include <stdio.h>
int main()
{
	//Q3
	float totcal,fatgrms,fatcal;
	do
	{
		printf("Please enter fat grams: ");
		scanf("%f",&fatgrms);
		printf("Please enter total calories: ");
		scanf("%f",&totcal);	
	}
	while (fatgrms < 0 || totcal < 0);
	
	fatcal = fatgrms * 9;
	
	if (fatcal > totcal)
	{
		printf("Invalid Input! Inputs were entered incorrectly!");
	}
	else 
	{
		printf("The percentage of calories from fat is %f", fatcal/totcal*100);
		if (fatcal/totcal*100 < 30)
		{
			printf("\nFood is low on fat.");
		}
	}
}
