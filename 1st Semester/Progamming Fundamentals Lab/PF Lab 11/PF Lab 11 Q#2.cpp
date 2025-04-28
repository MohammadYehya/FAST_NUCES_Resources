#include <stdio.h>
void swapped(int *aPtr, int *bPtr, int *cPtr);
int main()
{
	int a,b,c;
	printf("Enter value of num1: ");
	scanf("%d",&a);
	printf("Enter value of num2: ");
	scanf("%d",&b);
	printf("Enter value of num3: ");
	scanf("%d",&c);
	printf("Before Swapping: num1 is: %d, num2 is: %d, num3 is: %d\n",a,b,c);
	swapped(&a,&b,&c);
	printf("After Swapping: num1 is: %d, num2 is: %d, num3 is: %d",a,b,c);
}
void swapped(int *aPtr, int *bPtr, int *cPtr)
{
	int temp;
	temp = *aPtr;
	*aPtr = *bPtr;
	*bPtr = *cPtr;
	*cPtr = temp;
}
