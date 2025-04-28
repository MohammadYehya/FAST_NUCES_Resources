#include <stdio.h>
struct courses
{
	char coursename[100];
	float GPA;
};
struct address
{
	char strtads[100];
	char city[100];
	char state[100];
	int zip;
};
struct stddata
{
	float CGPA;
	struct courses c;
	struct address a;
};
int main()
{
	struct stddata s[2];
	for(int i = 0 ; i < 2 ; i++)
	{
		printf("Enter the CGPA of student %d: ",i+1);
		scanf("%f",&s[i].CGPA);
		printf("Enter the course name: ");
		getchar();
		gets(s[i].c.coursename);
		printf("Enter the course GPA: ");
		scanf("%d",&s[i].c.GPA);
		printf("Enter street address: ");
		getchar();
		gets(s[i].a.strtads);
		printf("Enter city: ");
		getchar();
		gets(s[i].a.city);
		printf("Enter state: ");
		getchar();
		gets(s[i].a.state);
		printf("Enter zip: ");
		scanf("%d",&s[i].a.zip);
	}
	if (s[0].c.GPA > s[1].c.GPA)
	{
		printf("Student %d has greater GPA than Student %d in %s\n",1,2,s[0].c.coursename);
	}
	else if (s[0].c.GPA < s[1].c.GPA)
	{
		printf("Student %d has greater GPA than Student %d in %s\n",2,1,s[1].c.coursename);
	}
	if (s[0].CGPA > s[1].CGPA)
	{
		printf("Student %d has the highest CGPA of %f\n",1,s[0].CGPA);
	}
	else if (s[0].CGPA < s[1].CGPA)
	{
		printf("Student %d has the highest CGPA of %f\n",2,s[1].CGPA);
	}
	
}
