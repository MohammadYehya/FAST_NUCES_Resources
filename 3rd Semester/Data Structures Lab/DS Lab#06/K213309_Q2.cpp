#include <iostream>
#include <conio.h>
using namespace std;
class Node
{
	private:
		int data;
		int key;
		Node* next;
	public:
		Node ()
		{
			data = 0;
			int key = 0;
			next = NULL;
		}
		Node (int k, int d)
		{
			data = d;
			key = k;
			next = NULL;
		}
		friend class CircularSinglyLinkedList;
};
class CircularSinglyLinkedList
{
	public:
		Node* head;
		CircularSinglyLinkedList()
		{
			head = NULL;
		}
		CircularSinglyLinkedList (Node* n)
		{
			head = n;
		}
		Node* nodeExists(int k)
		{
			Node* temp = head;
			if (head == NULL)
			{
				return NULL;
			}
			else
			{
				while(temp->next != head)
				{
					if (temp->key == k)
					{
						return temp;
					}
					temp = temp->next;
				}
				if(temp->key == k) return temp;
				return NULL;
			}
		}
		void Append(int k , int d)
		{
			Node* newNode = new Node(k,d);
			newNode->next = head;
			Node* temp = head;
			if(head == NULL) {head = newNode;head->next = head;}
			else if (nodeExists(k) != NULL)
			{
				cout << "Key already exists!" << endl;
				return;
			}
			else
			{
				while(temp->next != head)
				{
					temp = temp->next;
				}
				temp->next = newNode;
			}
		}
		void Prepend(int k , int d)
		{
			Node* newNode = new Node(k,d);
			Node* temp = head;
			if(head == NULL) {head = newNode; head->next = head;}
			else if (nodeExists(k) != NULL)
			{
				cout << "Key already exists!" << endl;
				return;
			}
			else
			{
				while(temp->next != head)
				{
					temp = temp->next;
				}
				temp->next = newNode;
				newNode->next = head;
				head = newNode;
			}
		}
		void InsertAfter(int k , int d , int pos)
		{
			Node* temp = head;
			Node* newNode = new Node(k,d);
			if(head == NULL) {head = newNode;head->next = head;}
			else if (nodeExists(k) != NULL)
			{
				cout << "Key already exists!" << endl;
				return;
			}
			else
			{
				do
				{
					if(pos > 0)
					{
						temp = temp->next;
						pos--;
					}
					else
					{
						newNode->next = temp->next;
						temp->next = newNode;
						return;
					}
				}
				while(temp != head);
			}
			cout << "Invalid Position!" << endl;
		}
		void DeleteNodeAtPos(int pos)
		{
			if(head == NULL) {cout << "List is already empty!" << endl;}
			else
			{
				Node* temp = head;
				Node* temp2 = head->next;
				if(pos == 0)
				{
					while(temp->next != head)
					{
						temp = temp->next;
					}
					head = head->next;
					delete temp->next;
					temp->next = head;
					return;
				}
				else
				{
					do
					{
						if(pos - 1 > 0)
						{
							temp = temp2;
							temp2 = temp2->next;
							pos--;
						}
						else
						{
							temp->next = temp2->next;
							delete temp2;
							return;
						}
					}
					while(temp2 != head);
				}
			}
			cout << "Invalid Position!" << endl;
		}
		void UpdateNode(int k)
		{
			Node* temp = nodeExists(k);
			if(head == NULL) {cout << "List is already empty!" << endl;}
			else if (temp == NULL)
			{
				cout << "Key not found!" << endl;
				return;
			}
			else
			{
				cout << "Enter new data for key value " << k << ": "; cin >> temp->data;
			}
		}
		void Print()
		{
			Node* temp = head;
			if (head == NULL){cout << "List is empty!" << endl;}
			else
			{
				while(temp->next != head)
				{
					cout << temp->key << "|" << temp->data << "->";
					temp = temp->next;
				}
				cout << temp->key << "|" << temp->data << "->HEAD" << endl;
			}
		}
};
int main()
{
	CircularSinglyLinkedList Link;
	int x = 0, data, key, pos;
	while(1)
	{
		cout << "\t\t\t\tLab 6 CircularSinglyLinkedList K213309" << endl << endl;
		cout << "1.Add a node at the end of a Circular Singly Linked List" << endl
		<<		"2.Add a node at the front of a Circular Singly Linked List (Prepend a new node)" << endl
		<<		"3.Add a node after a given position in a Circular Singly Linked List (List starts from 0)" << endl
		<<		"4.Delete a node from a Circular Singly Linked List" << endl
		<<		"5.Update a node in a Circular Singly Linked List" << endl
		<<		"6.Print List (In the format Key|Data)" << endl
		<<		"7.Exit" << endl << endl;
		cout << "Enter pick: ";
		cin >> x;
		switch(x)
		{
			case 1:
				cout << "Enter data: "; cin >> data;
				cout << "Enter key: "; cin >> key;
				Link.Append(key,data);
				break;
			case 2:
				cout << "Enter data: "; cin >> data;
				cout << "Enter key: "; cin >> key;
				Link.Prepend(key,data);
				break;
			case 3:
				cout << "Enter data: "; cin >> data;
				cout << "Enter key: "; cin >> key;
				cout << "Enter position: "; cin >> pos;
				Link.InsertAfter(key,data,pos);
				break;
			case 4:
				cout << "Enter position: "; cin >> pos;
				Link.DeleteNodeAtPos(pos);
				break;
			case 5:
				cout << "Enter key: "; cin >> key;
				Link.UpdateNode(key);
				break;
			case 6:
				Link.Print();
				break;
			case 7:
				return 0;
		}
		getch();
		system("CLS");
	}
}

