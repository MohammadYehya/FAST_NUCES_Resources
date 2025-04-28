#include <stdio.h>
struct Students
{
	int student_id;
	int stu_age;
	char stu_name[100];
	int streetno;
	char state[100];
	char city[100];
	char country[100];
};
int main()
{
	int n;
	printf("Enter number of students: ");
	scanf("%d",&n);
	struct Students s[n];
	for (int i = 0 ; i < n ; i++)
	{
		printf("Enter student ID: ");
		scanf("%d",&s[i].student_id);
		printf("Enter student age: ");
		scanf("%d",&s[i].stu_age);
		printf("Enter student name: ");
		getchar();
		gets(s[i].stu_name);
		printf("Enter street number: ");
		scanf("%d",&s[i].streetno);
		printf("Enter state: ");
		getchar();
		gets(s[i].state);
		printf("Enter city: ");
		gets(s[i].city);
		printf("Enter country: ");
		gets(s[i].country);
		printf("\n");
	}
	for (int i = 0 ; i < n ; i++)
	{
		printf("Student ID: %d\n",s[i].student_id);
		printf("Student age: %d\n",s[i].stu_age);
		printf("Student name: %s\n",s[i].stu_name);
		printf("Street number: %d\n",s[i].streetno);
		printf("State: %s\n",s[i].state);
		printf("City: %s\n",s[i].city);
		printf("Country: %s",s[i].country);
		printf("\n");
	}
}
