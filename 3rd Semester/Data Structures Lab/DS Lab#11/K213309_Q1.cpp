#include <iostream>
using namespace std;
template<typename T, int n>
class HashMapTable
{
	private:
		class HashTableEntry	//Encapsulated Class is unaccessible in main
		{
			public:
				T val;
				int key;
				HashTableEntry() {}
				HashTableEntry(T val, int key) {this->val = val; this->key = key;}
		} **table;
	public:
		HashMapTable() 
		{
			table = new HashTableEntry*[n];
			for(int i = 0 ; i < n ; i++) table[i] = NULL;
		}
		~HashMapTable()
		{
			for(int i = 0 ; i < n ; i++) if(table[i] != NULL) delete table[i];
			delete [] table;
		}
		int HashFunc(int k){return k%n;}
		void Insert(T val, int k)
		{
			int _k = HashFunc(k);
			while(table[_k] != NULL && table[_k]->key != k) _k = HashFunc(_k + 1);
			if(table[_k] != NULL) delete table[_k];
			table[_k] = new HashTableEntry(val, k);
		}
		T Search(int k)
		{
			int _k = HashFunc(k);
			while(table[_k] != NULL && table[_k]->key != k) _k = HashFunc(_k + 1);
			if(table[_k] != NULL) return table[_k]->val;
		}
		void Remove(int k)
		{
			int _k = HashFunc(k);
			while(table[_k] != NULL) if(table[_k]->key == k) break; else _k = HashFunc(_k + 1);
			if(table[_k] != NULL) 
			{
				delete table[_k];
				table[_k] = NULL;
			}
		}
		void PrintMap()
		{
			for(int i = 0 ; i < n ; i++)
			{
				cout << i << ")";
				if(table[i] != NULL)cout << table[i]->val << "|" << table[i]->key << endl;
				else cout << "0|0" << endl;
			}
		}
};
int main()
{
	HashMapTable<int,10> h;
	h.Insert(10,6);
	h.Insert(27,16);
	h.PrintMap();
	cout << endl << h.Search(16) << endl << endl;
	h.Remove(16);
	h.PrintMap();
}

