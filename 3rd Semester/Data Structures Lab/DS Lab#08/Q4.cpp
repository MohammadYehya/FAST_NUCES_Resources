#include <iostream>
using namespace std;
template <typename T , int size>
class Queue
{
	int front, rear;
	T arr[size];
	public:
		Queue() {front = rear = -1;}
		bool QueueCapacity()
		{
			return ((front == 0) && (rear == (size - 1)));
		}
		bool QueueEmpty()
		{
			return ((front == -1));
		}
		void AddMember(T d)
		{
			if (!QueueCapacity())
			{
				if(front == -1) front = 0;
				arr[++rear] = d;
			}
			else cout << "Queue is full!" << endl;
		}
		void RemoveMember()
		{
			if (!QueueEmpty())
			{
				if (front > rear)
				{
					front = rear = -1;
					cout << "Queue is empty!" << endl;
				}
				else front++;
			}
		}
		void DisplayQueue()
		{
			if(QueueEmpty())
			{
				cout << "Queue is Empty!" << endl;
				return;
			}
			for (int i = front ; i <= rear ; i++) cout << arr[i] << " ";
			cout << endl;
		}
};
int main()
{
	Queue<int , 2> q;
	q.AddMember(5);
	q.AddMember(3309);
	q.AddMember(1234);
	q.RemoveMember();
	q.DisplayQueue();
}

