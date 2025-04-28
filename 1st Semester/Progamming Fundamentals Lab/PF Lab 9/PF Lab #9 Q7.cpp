#include <stdio.h>
int trace(int _matrix[100][100],int _n);
int main()
{
	int matrix[100][100];
	int i,j,n;
	printf("Enter the number and rows of a matrix: ");
	scanf("%d",&n);
	
	for (i = 0 ; i < n ; i++)
	{
		for (j = 0 ; j < n ; j++)
		{
			printf("Enter the value of a%d%d : ",i+1,j+1);
			scanf("%d",&matrix[i][j]);
		}
	}
	printf("The trace is : %d",trace(matrix,n));
}
int trace(int _matrix[100][100],int _n)
{
	int sum = 0;
	for (int i = 0 ; i < _n ; i++)
	{
		sum += _matrix[i][i];
	}
	return sum;
}
