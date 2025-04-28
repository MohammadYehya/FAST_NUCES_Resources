#include <stdio.h>
void getData();
float VolumeCalu(float a,float h);
int main()
{
	getData();
}
void getData()
{
	float a,h;
	printf("Enter height: ");
	scanf("%f",&h);
	printf("Enter base area: ");
	scanf("%f",&a);
	printf("The Volume is %.2f",VolumeCalu(a,h));
}
float VolumeCalu(float a,float h)
{
	return ((a*a)*(1.0/3.0)*h);
}
