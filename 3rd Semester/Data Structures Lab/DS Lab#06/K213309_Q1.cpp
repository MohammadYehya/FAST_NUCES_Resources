#include<iostream>
#include<conio.h>
using namespace std;
class Node
{
	private:
		int key;
		int data;
		Node * next;
		Node * previous;
	public:
		Node()
		{
			key = 0;
			data = 0;
			next = NULL;
			previous = NULL;
		}
		Node(int k, int d)
		{
			key = k;
			data = d;
			next = NULL;
			previous = NULL;
		}
		friend class DoublyLinkedList;
};
class DoublyLinkedList
{
	public:
		Node * head;
		DoublyLinkedList() {head = NULL;}
		DoublyLinkedList(Node * n) {head = n;}
		Node* nodeExists(int k)
			{
				Node* temp = head;
				if (head == NULL)
				{
					return NULL;
				}
				else
				{
					while(temp != NULL)
					{
						if (temp->key == k)
						{
							return temp;
						}
						temp = temp->next;
					}
					return NULL;
				}
			}
		void Append(int k , int d)
		{
			Node* newNode = new Node(k,d);
			Node* temp = head;
			if(head == NULL) {head = newNode;}
			else if (nodeExists(k) != NULL)
			{
				cout << "Key already exists!" << endl;
				return;
			}
			else
			{
				while(temp->next != NULL)
				{
					temp = temp->next;
				}
				temp->next = newNode;
				newNode->previous = temp;
			}
		}
		void Prepend(int k , int d)
		{
			Node* newNode = new Node(k,d);
			Node* temp = head;
			if(head == NULL) {head = newNode;}
			else if (nodeExists(k) != NULL)
			{
				cout << "Key already exists!" << endl;
				return;
			}
			else
			{
				newNode->next = head;
				head->previous = newNode;
				head = newNode;
			}
		}
		void InsertAfter(int k , int d , int pos)
		{
			Node* temp = head;
			Node* newNode = new Node(k,d);
			if(head == NULL) {head = newNode;}
			else if (nodeExists(k) != NULL)
			{
				cout << "Key already exists!" << endl;
				return;
			}
			else
			{
				while(temp != NULL)
				{
					if(pos > 0)
					{
						temp = temp->next;
						pos--;
					}
					else
					{
						newNode->next = temp->next;
						newNode->previous = temp;
						temp->next->previous = newNode;
						temp->next = newNode;
						return;
					}
				}
			}
			cout << "Invalid Position!" << endl;
		}
		void DeleteNodeAtPos(int pos)
		{
			if(head == NULL) {cout << "List is already empty!" << endl;}
			else
			{
				Node* temp = head;
				if(pos == 0)
				{
					head = head->next;
					delete temp;
					return;
				}
				else
				{
					while(temp != NULL)
					{
						if(pos - 1 > 0)
						{
							temp = temp->next;
							pos--;
						}
						else
						{
							temp->previous->next = temp->next;
							temp->next->previous = temp->previous;
							delete temp;
							return;
						}
					}
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
				cout << "NULL<->";
				while(temp->next != NULL)
				{
					cout << temp->key << "|" << temp->data << "<->";
					temp = temp->next;
				}
				cout << temp->key << "|" << temp->data << "<->NULL" << endl;
			}
		}
};
int main()
{
	DoublyLinkedList Link;
	int x = 0, data, key, pos;
	while(1)
	{
		cout << "\t\t\t\tLab 6 DoublyLinkedList K213309" << endl << endl;
		cout << "1.Add a node at the end of a Doubly Linked List" << endl
		<<		"2.Add a node at the front of a Doubly Linked List (Prepend a new node)" << endl
		<<		"3.Add a node after a given position in a Doubly Linked List (List starts from 0)" << endl
		<<		"4.Delete a node from a Doubly Linked List" << endl
		<<		"5.Update a node in a Doubly Linked List" << endl
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
