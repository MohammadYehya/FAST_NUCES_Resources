#include <stdio.h>
struct phone
{
	int area;
	int ex;
	int num;
};
int main()
{
	struct phone p1 = {212 , 767 , 8900},p2;
	printf("Enter area code: ");
	scanf("%d",&p2.area);
	printf("Enter exchange: ");
	scanf("%d",&p2.ex);
	printf("Enter number: ");
	scanf("%d",&p2.num);
	printf("My number is (%d) %d-%d\n",p1.area,p1.ex,p1.num);
	printf("Your number is (%d) %d-%d",p2.area,p2.ex,p2.num);
}
