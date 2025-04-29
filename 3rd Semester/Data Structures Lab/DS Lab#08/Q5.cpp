#include <iostream>
using namespace std;
class Node
{
		Node* next;
		int data;
	public:
		Node()
		{
			data = 0;
			next = NULL;
		}
		Node(int d)
		{
			data = d;
			next = NULL;
		}
		friend class LinkedList;
};
class LinkedList
{
	Node* head;
	public:
		LinkedList(){head = NULL;}
		//No isFull function since we are dynamically allocating memory
		void Enqueue(int d)
		{
			Node* temp = head;
			Node* newNode = new Node(d);
			if (head == NULL)
			{
				head = newNode;
			}
			else
			{
				while(temp->next != NULL)
				{
					temp = temp->next;
				}
				temp->next = newNode;
			}
		}
		void Dequeue()
		{
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		void Display()
		{
			Node* temp = head;
			while(temp != NULL)
			{
				cout << temp->data << " ";
				temp = temp->next;
			}
		}
};
int main()
{
	LinkedList Queue;
	Queue.Enqueue(1);
	Queue.Enqueue(19);
	Queue.Enqueue(3309);
	Queue.Enqueue(1234);
	Queue.Dequeue();
	Queue.Display();
}

