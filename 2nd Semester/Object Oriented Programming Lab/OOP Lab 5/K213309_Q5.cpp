#include <iostream>
using namespace std;
class Score
{
	private:
		int scores[10];
		static int highestScore;
	public:
		void setScore(const int arr[10])
		{for(int i = 0 ; i < 10 ; i++)scores[i] = arr[i];}
		const void *getScore()
		{return scores;}
		static int gethighestScore()
		{return highestScore;}	
		Score(int arr[10])
		{
			int i;
			for(i = 0 ; i < 10 ; i++)scores[i] = arr[i];
			for(i = 0 ; i < 10 ; i++)if (scores[i] > highestScore) highestScore = scores[i];
		}
};
int Score::highestScore = 0;
int main()
{
	int arr1[10] = {10,7,32,8,3,12,6,86,24,12};
	int arr2[10] = {34,65,23,86,23,98,12,76,1,10};
	int arr3[10] = {12,65,45,86,23,87,84,21,84,48};
	int arr4[10] = {15,15,48,51,15,84,12,15,51,74};
	int arr5[10] = {101,2,51,51,85,7,74,5,7,84};
	Score s[5] = {Score(arr1) , Score(arr2) , Score(arr3) , Score(arr4) , Score(arr5)};
	cout << "Highest Score: " << Score::gethighestScore();
}


