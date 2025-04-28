#include <stdio.h>
#include <math.h>
long convertBinary(long decNo);
int main()
{
	long n;
	printf("Enter a number to convert to binary: ");
	scanf("%d",&n);
	long bin = convertBinary(n);
	printf("The Binary value is : %d",bin);
}
long convertBinary(long decNo)
{
	static int n = 0;
	static long bin = 0;
	if (decNo > 0)
	{
		bin += decNo%2 * pow(10,n);
		n++;
		convertBinary(decNo/2);
	}
	return bin;
	
}

