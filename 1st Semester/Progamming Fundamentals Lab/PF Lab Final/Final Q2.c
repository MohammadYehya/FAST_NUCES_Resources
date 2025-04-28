#include <stdio.h>
#include <conio.h>
#include <time.h>
int m,n;

void Populate(int arr[][n])
{
	srand(time(NULL));/*For True Randomness*/
	int i, j;
	for (i = 1 ; i < m+1 ; i++)
	{
		for (j = 1 ; j < n+1 ; j++)
		{
			arr[i][j] = (rand()%226);/*To Populate*/
		}
	}
}
void Display(int arr[][n])
{
	int i, j;
	printf("\t\tDisplaying the Randomly generated GrayScale Image\n");
	for (i = 1 ; i < m+1 ; i++)
	{
		printf("\t");
		for (j = 1 ; j < n+1 ; j++)
		{
			printf("%d\t\t",arr[i][j]);
		}
		printf("\n");
	}
}
void MaxPooling(int arr[][n])
{
	int i,j;
	for (i = 1 ; i < m+1 ; i++)
	{
		for (j = 1 ; j < n+1 ; j++)
		{
		if (arr[i][j] < arr[i][j+1] ||
			arr[i][j] < arr[i][j-1] || 
			arr[i][j] < arr[i+1][j] || 
			arr[i][j] < arr[i-1][j] || 
			arr[i][j] < arr[i+1][j+1]||
			arr[i][j] < arr[i+1][j-1]||
			arr[i][j] < arr[i-1][j+1]||
			arr[i][j] < arr[i-1][j-1])/*To check all the neighbouring values*/
			{
				continue;
			}
			printf("\tValue at the Index %d,%d is Maximum among Neighbours: %d\n" ,i,j,arr[i][j]);
		}
	}
}
int main()
{
	int i , j;
	printf("Enter the number of rows: ");
	scanf("%d",&m);
	printf("Enter the number of columns: ");
	scanf("%d",&n);
	int arr[m+2][n+2];
	for (i = 0 ; i <= m+1 ; i++)
	{
		for (j = 0 ; j <= n+1 ; j++)
		{
			arr[i][j] = 0;
		}
	}
	Populate(arr);
	Display(arr);
	MaxPooling(arr);
}
