#include <iostream>
using namespace std;
bool IdentityCheck(int **arr , int M , int N)
{
	if (M != N)return false;
	for(int i = 0 ; i < M ; i++)
	{
		if(arr[i][i] != 1)return false;
		for(int j = 0 ; j < N ; j++)
		{
			if (i == j) continue;
			if(arr[i][j] != 0)return false;
		}
	}
	return true;
}
int main()
{
	int M,N;
	cout << "Enter number of Rows: "; cin >> M;
	cout << "Enter number of Columns: "; cin >> N;
	int **x = new int*[M];
	for(int i = 0 ; i < M ; i++) x[i] = new int[N];
	
	for(int i = 0 ; i < M ; i++)
	{
		for(int j = 0 ; j < N ; j++)
		{
			cout << "Enter [" << i << "][" << j << "]: "; cin >> x[i][j];
		}
	}
	if(IdentityCheck(x , M , N))cout << "It is an Identity Matrix!";
	else cout << "It is not an Identity Matrix!";
	
	for (int i = 0 ; i < N ; i++) delete [] x[i];
	delete [] x;
}

