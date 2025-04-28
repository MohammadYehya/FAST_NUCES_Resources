#include <stdio.h>
#include <stdbool.h>
#define n 7
int main()
{
	int i;
	int z;
	int x[n] = {5,6,2,1,3,4,0};
	int y[n] = {33,14,29,73,84,60,52};
	bool arr[n];
	for (i = 0 ; i < n ; i++)
	{
		z = (y[x[i]]);
		if (z % 4 == 0) arr[i] = true;
		else arr[i] = false;
	}
	for (i = 0 ; i < n ; i++)
	{
		if (arr[i] == true) printf("TRUE ");
		else if (arr[i] == false) printf("FALSE ");
	}
}
