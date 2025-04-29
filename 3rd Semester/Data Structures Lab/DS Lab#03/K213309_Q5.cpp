#include<iostream>
#define n 4
using namespace std;
bool ValidPos(int arr[n][n] , int x , int y)
{
	if (arr[x][y] && x < n && y < n && x >= 0 && y >= 0) return true;
	return false;
}
void DisplayArray(int arr[n][n])
{
	for (int i = 0 ; i < n ; i++)
	{
		for (int j = 0 ; j < n ; j++) cout << arr[i][j] << ' ';
		cout << endl;
	}
}
RatInMazeSolver(int arr[n][n] , int x ,int y , int solArr[n][n])
{
	if (x == n-1 && y == n-1 && arr[x][y])
	{
		solArr[x][y] = 1;
		return true;
	}
	if (ValidPos(arr , x , y))
	{
		solArr[x][y] = 1;
		if (RatInMazeSolver(arr , x , y+1 , solArr)) return true;
		if (RatInMazeSolver(arr , x+1 , y , solArr)) return true;
		solArr[x][y] = 0;
		return false;
	}
	return false;
}
int main()
{
	int Maze[n][n] = {{1,0,0,0},
					  {1,1,0,1},
					  {0,1,0,0},
					  {1,1,1,1}};
	int Sol[n][n] = {0};
	cout << "Original Maze: " << endl; DisplayArray(Maze);
	RatInMazeSolver(Maze , 0 , 0 ,Sol);
	cout << endl << "Solved Maze: " << endl; DisplayArray(Sol);
}
