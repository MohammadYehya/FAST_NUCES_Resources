#include<iostream>
#include<conio.h>
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
		friend class SinglyLinkedList;
};
class SinglyLinkedList
{
	public:
		Node* head;
		SinglyLinkedList()
		{
			head = NULL;
		}
		SinglyLinkedList (Node* n)
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
				Node* temp2 = head->next;
				if(pos == 0)
				{
					head = head->next;
					delete temp;
					return;
				}
				else
				{
					while(temp2 != NULL)
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
				while(temp->next != NULL)
				{
					cout << temp->key << "|" << temp->data << "->";
					temp = temp->next;
				}
				cout << temp->key << "|" << temp->data << "->NULL" << endl;
			}
		}
		void EvenFirst()
		{
			SinglyLinkedList l2;
			Node* temp = this->head;
			int counter = 0;
			while(temp != NULL)
			{
				if((temp->data)%2 == 0)
				{
					l2.Append(temp->key , temp->data);
					temp = temp->next;
					this->DeleteNodeAtPos(counter);
				}
				else 
				{
					temp=temp->next;
					counter++;
				}
			}
			temp = l2.head;
			if(temp == NULL)
			{
				cout << "No even Numbers!" << endl;
				return;
			}
			while(temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = head;
			head = l2.head;
		}
};
int main()
{
	SinglyLinkedList Link;
	int x = 0, data, key, pos;
	while(1)
	{
		cout << "\t\t\t\tSinglyLinkedList" << endl << endl;
		cout << "1.Add a node at the end of a Singly Linked List" << endl
		<<		"2.Add a node at the front of a Singly Linked List (Prepend a new node)" << endl
		<<		"3.Add a node after a given position in a Singly Linked List (List starts from 0)" << endl
		<<		"4.Delete a node from a Singly Linked List" << endl
		<<		"5.Update a node in a Singly Linked List" << endl
		<<		"6.All even numbers appear before all the odd numbers" << endl
		<<		"7.Print List (In the format Key|Data)" << endl
		<<		"8.Exit" << endl << endl;
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
				Link.EvenFirst();
				break;
			case 7:
				Link.Print();
				break;
			case 8:
				return 0;
		}
		getch();
		system("CLS");
	}
}

