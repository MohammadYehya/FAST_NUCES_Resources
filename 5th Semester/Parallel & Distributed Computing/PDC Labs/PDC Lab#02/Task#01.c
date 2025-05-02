/*
	Task#1: Write a program in openMP C to find the factorial of any number less than 105 the
	program will save the answer in one shared variable and will solve it. Once
	the program will end it will ask again to find the facto rial until the user
	say no. Ea ch tim e the answer is sa ve d in an array and will calculate f or
	new values only. Previous values whi ch are stored in ar ray will directly be
	acc essed from that array.
*/

#include <stdio.h>
#include <omp.h>

#define BIGINT long long int							//Creating an alias for unsigned long long int
#define N 106									//Defining array size

BIGINT findClosest(BIGINT arr[][2], int val)					//Creating a function to find the closest calculated factorial
{
	if(val > 0 && !arr[val][1]) return findClosest(arr, val-1);		//Used recursion for the implementation
	else return arr[val][1];
}
void setClosest(BIGINT arr[][2], int val)					//Once factorial found, update the next closest calculated factorial
{
	for(int i = val; i < N && val >= arr[i][1]; i++) {arr[i][1] = val;}	//Implemented by a simple loop to update array
}

int main(int argc, char* argv[], char* envp[])
{
	BIGINT fact[N][2] = {0};						//Array to store all factorials
	fact[0][0] = 1;								//Setting the factorial of 0 as 1 for the base case
	int val, choice = 1;
	while(choice == 1)
	{
		printf("Enter number: ");
		scanf("%d",&val);
		
		BIGINT closestValue = findClosest(fact, val);			//Finding the index of the closest calculated factorial
		BIGINT temp = fact[fact[closestValue][1]][0];			//Getting value of closest calculated factorial
		
		double t1;	
		
		#pragma omp parallel num_threads(4) reduction(*:temp)		//Used pragma omp parallel in conjunction with pragma omp for to implement reduction and pragma omp single.
		{								//Reduction is used so that there is no duplication of values
			#pragma single						//Single is used so that only one thread starts the clock
			{
				t1 = omp_get_wtime();
			}
			#pragma omp for
			for(BIGINT i = closestValue + 1; i <= (BIGINT)val ; i++)
			{
				temp *= i;					//Calculates the factorial
			}
		}
		double t2 = omp_get_wtime();
		
		fact[val][0] = temp;
		setClosest(fact, val);						//Updating the closest factorial found
		
		if(temp < 0) printf("Overflow! Value now in Negative!\n");
		printf("%d! = %lld\n", val, fact[val][0]);
		printf("Time Taken to calculate factorial: %f\n",t2-t1);
		printf("Do you want to continue(1/0)? ");
		scanf("%d", &choice);
		printf("\n");
	}
}
