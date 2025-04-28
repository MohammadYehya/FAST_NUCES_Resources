#include <stdio.h>
void Salesflow(int _marks , int _exp);
int main()
{
	int marks,exp;
	printf("Enter marks: ");
	scanf("%d",&marks);
	printf("Enter experience: ");
	scanf("%d",&exp);
	Salesflow(marks,exp);
}
void Salesflow(int _marks , int _exp)
{
	if (_marks == 70 && _exp >= 2)
	{
		printf("Assigned Position: Associate Developer");
	}
	else if (_marks == 60 && _exp >= 1)
	{
		printf("Assigned Position: Assistant Developer");
	}
	else if (_marks == 50)
	{
		printf("Assigned Postion: Trainee Engineer");
	}
}
