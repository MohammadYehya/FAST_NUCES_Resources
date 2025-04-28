#include <stdio.h>
struct Register
{
	int  CourseID;
	char CourseName[100];	
};
struct student
{
	int stdID;
	char FName[100];
	char LName[100];
	long cellno;
	char email[100];
	struct Register R;
};
int main()
{
	int i , n = 5;
	struct student s[5];
	for (i = 0 ; i < n ; i++)
	{
		printf("Enter the student ID of student %d: ",i+1);
		scanf("%d",&s[i].stdID);
		printf("Enter the First Name of student %d: ",i+1);
		getchar();
		gets(s[i].FName);
		printf("Enter the Last Name of student %d: ",i+1);
		gets(s[i].LName);
		printf("Enter the Cell Number of student %d: ",i+1);
		scanf("%d",&s[i].cellno);
		printf("Enter the email of student %d: ",i+1);
		getchar();
		gets(s[i].email);
		printf("Enter Course ID: ");
		scanf("%d",&s[i].R.CourseID);
		printf("Enter the Course Name: ");
		getchar();
		gets(s[i].R.CourseName);
	}
	for (i = 0 ; i < n ; i++)
	{
		printf("Student ID of Student %d : %d\n",i+1,s[i].stdID);
		printf("The First Name of Student %d : %s\n",i+1,s[i].FName);
		printf("The Last Name of Student %d : %s\n",i+1,s[i].LName);
		printf("The cell number of Student %d : %d\n",i+1,s[i].cellno);
		printf("The Email of Student %d is: %s\n",i+1,s[i].email);
		printf("The Course Id is: %d\n",s[i].R.CourseID);
		printf("The Course Name is: %s\n",s[i].R.CourseName);
	}
}

