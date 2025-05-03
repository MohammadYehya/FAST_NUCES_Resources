//K213309
#include <iostream>
#include <windows.h>
#include <time.h>
//N is the board size (NxN)
#define N 10
//NQPwithConstQ is a variable to indicate if there is already a randomly placed queen on the board
#define NQPwithConstQ 1
using namespace std;

//Handle used just to show colors
HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);

//A function to print the board
void printBoard(int board[N][N])
{
	for (int i = 0 ; i < N ; i++)
	{
		for (int j = 0 ; j < N ; j++)
		{
			if (board[i][j]) SetConsoleTextAttribute(color, 4);
			cout << board[i][j] << " ";
			SetConsoleTextAttribute(color, 15);
		}
		cout << endl;
	}
	cout << endl;
}

//A function to check if the position is a valid position to put a queen
bool CheckPos(int board[N][N] , int posX , int posY)
{
	for (int i = 0 ; i < N ; i++) {if (board[i][posY] == 1) return false;}
	for (int j = 0 ; j < N ; j++) {if (board[posX][j] == 1) return false;}
	for (int i = posX , j = posY ; i >= 0 && j >= 0 ; i-- , j--) {if (board[i][j] == 1) return false;}
	for (int i = posX , j = posY ; i < N && j >= 0 ; i++ , j--) {if (board[i][j] == 1) return false;}
	for (int i = posX , j = posY ; i >= 0 && j < N ; i-- , j++) {if (board[i][j] == 1) return false;}
	for (int i = posX , j = posY ; i < N && j < N ; i++ , j++) {if (board[i][j] == 1) return false;}
	return true;
}

//A function to 
int FindQueen(int board[N][N])
{
	for (int i = 0 ; i < N ; i++)
	{
		for (int j = 0 ; j < N ; j++)
		{
			if (board[i][j]) return j;
		}
	}
	return -1;
}

//The main recursive function to solve the problem
bool SolveNQProb(int board[N][N] , int col , int PlacedQueen)
{
	if (col == PlacedQueen)col++;
	if (col >= N) return true;
	for (int i = 0 ; i < N ; i++)
	{
		if (CheckPos(board , i , col))
		{
			board[i][col] = 1;
			if (SolveNQProb(board , col + 1 , PlacedQueen)) return true;
			else board[i][col] = 0;
		}
	}
	return false;
}

//To initialize the board to 0 and set a queen if needed
void PopulateArray(int board[N][N] , int x)
{
	for (int i = 0 ; i < N ; i++)
	{
		for (int j = 0 ; j < N ; j++) {board[i][j] = 0;}
	}
	if (x) board[rand()%N][rand()%N] = 1;
}


int main()
{
	srand(time(NULL));
	
	int board[N][N];
	PopulateArray(board , NQPwithConstQ);
	cout << "Original Board: " << endl;
	printBoard(board);
	if (SolveNQProb(board , 0 , FindQueen(board)))
	{
		cout << "Solution: " << endl;
		printBoard(board);
	}
	else cout << "No Solution!";
}
