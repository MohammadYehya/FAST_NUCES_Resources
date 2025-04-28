#include <stdio.h>
void populatearray(int arr[100][100],int n);
void addarrays(int arr1[100][100],int arr2[100][100],int n);
void subarrays(int arr1[100][100],int arr2[100][100],int n);
void multarrays(int arr1[100][100],int arr2[100][100],int result[100][100],int n);
int main()
{
	int mat1[100][100],mat2[100][100],result[100][100];
	int n;
	printf("Enter how many rows and columns: ");
	scanf("%d",&n);
	populatearray(mat1,n);
	populatearray(mat2,n);
	addarrays(mat1,mat2,n);
	subarrays(mat1,mat2,n);
	multarrays(mat1,mat2,result,n);
}
void populatearray(int arr[100][100],int n)
{
	int i,j;
	for (i = 0 ; i < n ; i++)
	{
		for (j = 0 ; j < n ; j++)
		{
			printf("Enter number at a%d%d postion: ",i+1,j+1);
			scanf("%d",&arr[i][j]);
		}
	}
	printf("\n");
}
void addarrays(int arr1[100][100],int arr2[100][100],int n)
{
	int i,j;
	for (i = 0 ; i < n ; i++)
	{
		for (j = 0 ; j < n ; j++)
		{
			printf("%d\t",arr1[i][j] + arr2[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void subarrays(int arr1[100][100],int arr2[100][100],int n)
{
	int i,j;
	for (i = 0 ; i < n ; i++)
	{
		for (j = 0 ; j < n ; j++)
		{
			printf("%d\t",arr1[i][j] - arr2[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void multarrays(int arr1[100][100],int arr2[100][100],int result[100][100],int n)
{
	int i,j,k;
	for (i = 0; i < n; ++i) 
	{
    	for (j = 0; j < n; ++j)
		{
    		for (k = 0; k < n; ++k)
			{
            	result[i][j] += arr1[i][k] * arr2[k][j];
        	}
    	}
	}
	for (i = 0 ; i < n ; i++)
	{
		for (j = 0 ; j < n ; j++)
		{
			printf("%d\t",result[i][j]);
		}
		printf("\n");
	}
}
