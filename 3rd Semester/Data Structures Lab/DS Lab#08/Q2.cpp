#include<iostream>
using namespace std;
class Node
{
	public:
		int data;
		Node* link;
		Node()
		{
			data = 0;
			link = NULL;
		}
		Node(int d)
		{
			data = d;
			link = NULL;
		}
};
class LinkedList
{
	public:
		Node* head;
		LinkedList()
		{
			head = NULL;
		}
		void Push(int d)
		{
			Node* newNode = new Node(d);
			if (head == NULL)
			{
				head = newNode;
//				cout << "Value Pushed in Stack" << endl;
				return;
			} 
			else
			{
				Node* temp = head;
				newNode->link = head;
				head = newNode;
//				cout << "Value Pushed in Stack" << endl;
				return;
			}
			cout << "Stack Overflow" << endl;
		}
		int Pop()
		{
			if (head == NULL) 
			{
				cout << "Stack is Empty" << endl;
			}
			else
			{
				Node* temp = head;
				head = head->link;
				int x = temp->data;
				delete temp;
				return x;
			}
		}
		void PrintForwardBackward()
		{
			Node* temp = head;
			LinkedList St2;
			cout << "Forward: ";
			while(temp->link != NULL)
			{
				cout << temp->data << " ";
				St2.Push(temp->data);
				temp = temp->link;
			}
			cout << endl << "Backward: ";
			while(St2.head != NULL)
			{
				int x = St2.Pop();
				cout << x << " ";
			}
		}
};

int main()
{
	LinkedList st;
	for(int i = 0 ; i < 10 ; i++)st.Push(i);
//	for(int i = 0 ; i < 10 ; i++)st.Pop();
	st.PrintForwardBackward();
}

