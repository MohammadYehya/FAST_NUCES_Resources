#include <iostream>
using namespace std;
void displayFriendTable(bool **arr)
{
	cout << "\t";
	for (int i = 0 ; i < 5 ; i++) cout << i << "\t";
	cout << endl;
	for (int i = 0 ; i < 5 ; i++) 
	{
		cout << i << "\t";
		for (int j = 0 ; j < 5 ; j++) 
		{
			if(arr[i][j]) cout << "*" << "\t"; 
			else cout << "\t";
		}
		cout << endl;
	}
}
void CommonFriend(bool **arr)
{
	for (int i = 0 ; i < 5 ; i ++)
	{
		bool check[5] = {false , false , false , false , false};
		for (int j = 0 ; j < 5 ; j ++)
		{
			if(arr[i][j] == true) check[j] = true;
		}
		for (int k = 0 ; k < 5 ; k ++)
		{
			if(k == i) continue;
			if (check[k] == true)
			{
				for (int l = 0 ; l < 5 ; l ++)
				{
					if (l == i) continue;
					if (arr[k][l] == true && check[l] == true)
					{
						cout << i << " and " << k << " have a common friend " << l << endl;
					}
				}
			}
		}
	}
}
int main()
{
	bool **arr = new bool*[5];
	arr[0] = new bool[5]{false , true , false , true , true};
	arr[1] = new bool[5]{true , false , true , false , true};
	arr[2] = new bool[5]{false , true , false , false , false};
	arr[3] = new bool[5]{true , false , false , false , true};
	arr[4] = new bool[5]{true , true , false , true , false};
	
	displayFriendTable(arr);
	CommonFriend(arr);
	
	for (int i = 0 ; i < 5 ; i++) delete [] arr[i];
	delete [] arr;
}

