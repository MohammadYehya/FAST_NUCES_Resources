#include <iostream>
using namespace std;
template<int n>
class ContactBook
{
	private:
		class HashTableEntry	//Encapsulated Class is unaccessible in main
		{
			public:
				int val;
				int key;
				HashTableEntry() {}
				HashTableEntry(int val, int key) {this->val = val; this->key = key;}
		} **book;
		int size;
	public:
		ContactBook() 
		{
			size = 0;
			book = new HashTableEntry*[n];
			for(int i = 0 ; i < n ; i++) book[i] = NULL;
		}
		~ContactBook()
		{
			for(int i = 0 ; i < n ; i++) if(book[i] != NULL) delete book[i];
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
			int _k = HashFunc(k) , count = 0;
			while(book[_k] != NULL && book[_k]->key != k && count <= n) {_k = HashFunc(_k + 1);count++;}	//Linear Probing
			if(count > n) return; //To avoid Infinite Loop
			if(book[_k] != NULL) delete book[_k];
			book[_k] = new HashTableEntry(val, k);
			size++;
		}
		int Search(int k)
		{
			int _k = HashFunc(k) , count = 0;
			while(book[_k] != NULL && book[_k]->key != k && count <= n) {_k = HashFunc(_k + 1);count++;}
			if(count > n) return -1;
			if(book[_k] != NULL) return book[_k]->val;
		}
		void Remove(int k)
		{
			int _k = HashFunc(k), count = 0;
			while(book[_k] != NULL && count <= n) {if(book[_k]->key == k) break; else _k = HashFunc(_k + 1); count++;}
			if(count > n) return;
			if(book[_k] != NULL) 
			{
				delete book[_k];
				book[_k] = NULL;
				size--;
			}
		}
		void PrintMap()
		{
			for(int i = 0 ; i < n ; i++)
			{
				cout << i << ")";
				if(book[i] != NULL)cout << book[i]->val << "|" << book[i]->key << endl;
				else cout << "0|0" << endl;
			}
		}
};
int main()
{
	ContactBook<10> h;
	for(int i = 0 ; i < 10 ; i++) h.Insert(i+1,5+10*i);
	h.PrintMap();
	cout << endl << h.Search(14) << endl << endl;
	h.Remove(15);
	h.PrintMap();
}

