#include <stdio.h>
void evenoddprint(int _start , int _end);
int main()
{
	int start,end;
	printf("Enter the start: ");
	scanf("%d",&start);
	printf("Enter the end: ");
	scanf("%d",&end);
	evenoddprint(start,end);
}
void evenoddprint(int _start , int _end)
{
	if (_end >= _start)
	{
		printf("%d\t",_start);
		evenoddprint(_start+2,_end);
	}
}
