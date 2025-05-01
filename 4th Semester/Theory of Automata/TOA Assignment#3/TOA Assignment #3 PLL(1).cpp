#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
CFG:

E -> E+T | T
T -> T*F | F
F -> (E) | a

converted to (by removing left recursion):

E -> TY
Y -> +TY | e
T -> FZ
Z -> *FZ | e
F -> (E) | a

*/
void print(char *c, int i)
{
	for(int _i = 0 ; _i <= i ; _i++) printf("%c",c[_i]);
	printf("\n");
}
const char* OldGrammar[] = {
						"E -> E+T | T",
						"T -> T*F | F",
						"F -> (E) | a"
						};
const char* NewGrammar[] = {
							"E -> TY",
							"Y -> +TY | e",
							"T -> FZ",
							"Z -> *FZ | e",
							"F -> (E) | a"
							};
const char ParseTable[5][6][4] = {
//								 +   *  (    )  a   $
								{"","","TY","","TY",""},
								{"+TY","","","e","","e"},
								{"","","FZ","","FZ",""},
								{"e","*FZ","","e","","e"},
								{"","","(E)","","a",""}
								};
int size[5][6] = {
				0,0,2,0,2,0,
				3,0,0,1,0,1,
				0,0,2,0,2,0,
				1,3,0,1,0,1,
				0,0,3,0,1,0
				};
int n;
char literal[100] = {0}, buffer[100];

int main()
{
	int i,j,k,row,col,flag = 0;
	printf("The Grammar was:\n");
	for(int i = 0 ; i < 3 ; i++) printf("%s\n",OldGrammar[i]);
	printf("After removing Left Recursion, the Grammar is:\n");
	for(int i = 0 ; i < 5 ; i++) printf("%s\n",NewGrammar[i]);
	
	printf("Enter a string: ");
	scanf("%[^\n]",literal);
	strcat(literal,"$");
	n = strlen(literal);
	buffer[0] = '$';
	buffer[1] = 'E';
	i = 1;
	j = 0;
	printf("Using LL(1) Predictive Parsing Technique\nStack:\n");
	while(1)
	{
		if(buffer[i] == literal[j])
		{
			if(buffer[i] == '$' && literal[j] == '$')
			{
				printf("Valid String\n");
				break;
			}
			else if(buffer[i] == '$' && literal[j] != '$')
			{
				printf("Invalid String!\n");
				exit(1);
			}
			i--;
			j++;
		}
		switch(buffer[i])
		{
			case 'E': row = 0; break;
			case 'Y': row = 1; break;
			case 'T': row = 2; break;
			case 'Z': row = 3; break;
			case 'F': row = 4; break;
		}
		switch(literal[j])
		{
			case '+': col = 0;break;
			case '*': col = 1;break;
			case '(': col = 2;break;
			case ')': col = 3;break;
			case 'a': col = 4;break;
			case '$': col = 5;break;
		}
		if(ParseTable[row][col][0] == '\0')
		{
			printf("Invalid String!\n");
			exit(1);
		}
		else if(ParseTable[row][col][0] == 'e')
		{
			print(buffer, i);
			i--;
		}
		else
		{
			for(k = size[row][col]-1 ; k>=0 ; k--)
			{
				buffer[i]=ParseTable[row][col][k];
				i++;
			}
			i--;
		}
		print(buffer, i);
	}
}
