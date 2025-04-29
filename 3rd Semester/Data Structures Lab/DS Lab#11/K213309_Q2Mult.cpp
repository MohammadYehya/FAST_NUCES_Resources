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
		int HashFunc(int k){return (int)(n * (k * 0.1));}
		void Insert(T val, int k)
		{
			int _k = HashFunc(k);
			if(table[_k] != NULL) delete table[_k];
			table[_k] = new HashTableEntry(val, k);
		}
		T Search(int k)
		{
			if(table[k] != NULL) return table[k]->val;
		}
		void Remove(int k)
		{
			if(table[k] != NULL) 
			{
				delete table[k];
				table[k] = NULL;
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
	h.Insert(27,1);
	h.PrintMap();
	cout << endl << h.Search(1) << endl << endl;
	h.Remove(1);
	h.PrintMap();
}

