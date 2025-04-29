#include<iostream>
using namespace std;
class Node
{
	private:
		int data;
		Node* next;
	public:
		Node(){next = NULL;}
		Node(int d){data = d; next = NULL;}
		friend class LinkedList;
};
class LinkedList
{
	public:
		Node* head;
		int size;
		LinkedList(){head = NULL;}
		void Append(int d)
		{
			Node* newnode = new Node(d);
			if (head == NULL){head = newnode;}
			else
			{
				Node* temp = head;
				while(temp->next != NULL) 
				{
					temp = temp->next;
				}
				temp->next = newnode;
				size++;
			}
		}
		Node* Merge(LinkedList L2)
		{
			int i = 0, j = 0;;
			LinkedList L3;
			Node *temp1 = this->head, *temp2 = L2.head;
			while (i < this->size && j < L2.size)
			{
				L3.Append(temp1->data);
				L3.Append(temp2->data);
				i++;j++;
				temp1 = temp1->next;
				temp2 = temp2->next;
			}
			if(i < this->size)
			{
				while(temp1 != NULL)
				{
					L3.Append(temp1->data);
					temp1 = temp1->next;
				}
			}
			if(j < L2.size)
			{
				while(temp2 != NULL)
				{
					L3.Append(temp2->data);
					temp2 = temp2->next;
				}
			}
			return L3.head;
		}
		void PrintList()
		{
			Node* temp = head;
			while(temp != NULL)
			{
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << endl;
		}
};
int main()
{
	LinkedList L1, L2, L3;
	L1.Append(1);
	L1.Append(2);
	L1.Append(5);
	L1.Append(7);
	L1.Append(8);
	L1.Append(11);
	
	L2.Append(22);
	L2.Append(56);
	L2.Append(88);
	L2.Append(99);
	L2.Append(54);
	L2.Append(70);
	L2.Append(98);
	L2.Append(64);
	L2.Append(72);
	
	L3.head = L1.Merge(L2);
	L1.PrintList();
	L2.PrintList();
	L3.PrintList();
}

