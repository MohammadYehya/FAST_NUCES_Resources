#include <stdio.h>
int main()
{
	int i,j,mat[5][9] = {0};
	for (i = 0 ; i < 5 ; i++)
	{
		printf("Enter Student ID: ");
		scanf("%d",&mat[i][0]);
		for (j = 1 ; j < 6 ; j++)
		{
			printf("Enter marks of course %d: ",j);
			scanf("%d",&mat[i][j]);
			mat[i][7] += mat[i][j];
		}
		printf("Enter total marks: ");
		scanf("%d",&mat[i][6]);
		mat[i][8] = mat[i][7]*100/mat[i][6];
	}
	for (i = 0 ; i < 5 ; i++)
	{
		for (j = 0 ; j < 9 ; j++)
		{
			printf("%d\t",mat[i][j]);
		}
		printf("\n");
	}
}

