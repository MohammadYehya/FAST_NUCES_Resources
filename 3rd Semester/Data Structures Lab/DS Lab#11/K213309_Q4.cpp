#include <iostream>
using namespace std;
template<int n>
class ContactBook
{
	private:
		class HashTableNode	//Encapsulated Class is unaccessible in main
		{
			public:
				int val;
				int key;
				HashTableNode* next;
				HashTableNode() {}
				HashTableNode(int val, int key) {this->val = val; this->key = key;next = NULL;}
		} **book;
		int size;
	public:
		ContactBook() 
		{
			size = 0;
			book = new HashTableNode*[n];
			for(int i = 0 ; i < n ; i++) book[i] = NULL;
		}
		~ContactBook()
		{
			for(int i = 0 ; i < n ; i++) 
			{
				while(book[i] != NULL)
				{
					HashTableNode *temp = book[i];
					book[i] = book[i]->next;
					delete temp;
				}
			}
			delete [] book;
		}
		bool isEmpty()
		{
			for(int i = 0 ; i < n ; i++) {if(book[i] != NULL)return 1;}
			return 0;
		}
		int getSize(){return size;}
		int HashFunc(int k){return k%n;}
		void Insert(int val, int k)
		{
			int _k = HashFunc(k);
			if(book[_k] == NULL)
			{
				book[_k] = new HashTableNode(val,k);
				return;
			}
			HashTableNode* temp = book[_k];
			while(temp->next != NULL) temp = temp->next;
			temp->next = new HashTableNode(val,k);
			size++;
		}
		int Search(int k)
		{
			int _k = HashFunc(k);
			HashTableNode* temp = book[_k];
			while(temp != NULL)
			{
				if(temp->key == k) return temp->val;
				temp = temp->next;
			}
			return -1;
		}
		void Remove(int k)
		{
			int _k = HashFunc(k);
			if(book[_k]->key == k)
			{
				HashTableNode *temp = book[_k];
				book[_k] = book[_k]->next;
				delete temp;
			}
			HashTableNode *temp = book[_k];
			while(temp->next != NULL)
			{
				if(temp->next->key == k)
				{
					HashTableNode *temp2 = temp->next;
					temp->next = temp->next->next;
					delete temp2;
				}
				temp = temp->next;
			}
		}
		void PrintMap()
		{
			for(int i = 0 ; i < n ; i++)
			{
				cout << i << ")";
				if(book[i] != NULL)
				{
					HashTableNode *temp = book[i];
					while(temp != NULL)
					{
						cout << temp->val << "|" << temp->key << " -> ";
						temp = temp->next;
					}
					cout << "NULL" << endl;
				}
				else cout << "0|0" << endl;
			}
		}
};
int main()
{
	ContactBook<10> h;
	for(int i = 0 ; i < 10 ; i++) h.Insert(i+1,5+10*i);
	h.PrintMap();
	cout << endl << h.Search(4) << endl << endl;
	h.Remove(5);
	h.PrintMap();
}

