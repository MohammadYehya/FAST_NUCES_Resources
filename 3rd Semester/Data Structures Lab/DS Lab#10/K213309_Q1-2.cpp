#include <iostream>
#include <cstdlib>
using namespace std;
class CharInfo
{
	char c;
	int freq;
	public:
		CharInfo(){}
		CharInfo(char c , int f){this->c = c ; freq = f;}
		CharInfo operator +(CharInfo& x){return CharInfo('§',freq + x.freq);}
		bool operator >(CharInfo& x){return freq > x.freq;}
		char getChar(){return c;}
		void print(){cout << c << " " << freq << endl;}
};
template<typename T>
class Node
{
	T data;
	public:
		Node<T> *left, *right;
		Node(){left = right = NULL;}
		Node(T d){data = d; left = right = NULL;}
		Node operator + (Node& x){return Node(data + x.data);}
		void print(){data.print();}
		T& getData(){return data;}
};
template<typename T>
class MinHeap
{
	Node<T> **arr;
	int top;
	int capacity;
	public:
		MinHeap(){arr = NULL;top = 0;}
		MinHeap(int n){arr = new Node<T>*[n]; top = 0;capacity = n;}
		int parent(int i) {return (i-1)/2;}
		int Left(int i) {return (2*i + 1);}
		int Right(int i) {return (2*i + 2);}
		void MinHeapify(int i)
		{
			int l = Left(i);
			int r = Right(i);
			int smallest = i;
			if(l < top && arr[l] < arr[smallest]) smallest = l;
			if(r < top && arr[r] < arr[smallest]) smallest = r;
			if(smallest != i) 
			{
				swap (arr[i],arr[smallest]);
				MinHeapify(smallest);
			}
		}
		Node<T> *ExtractMin()
		{
			if (top == 0) {return new Node<T>();}
			if (top == 1)
			{
				top--;
				return arr[0];
			}
			Node<T>* temp = arr[0];
			arr[0] = arr[--top];
			MinHeapify(0);
			return temp;
		}
		void Insert(Node<T>* d)
		{
			if (top == capacity) return;
			int i = top++;
			arr[i] = d;
			while(i != 0 && arr[parent(i)] > arr[i])
			{
				swap(arr[i] , arr[parent(i)]);
				i = parent(i);
			}
		}
		Node<T> *CreateHuffmanTree()
		{
			while(top != 1)
			{
				Node<T> *x = (ExtractMin());
				Node<T> *y = (ExtractMin());
				Node<T> *n = new Node<T>(x->getData() + y->getData());
				n->left = x;
				n->right = y;
				Insert(n);
			}
			return ExtractMin();
		}
};
template<typename T>
class HuffmanTree
{
	Node<T>* root;
	public:
		HuffmanTree(){root = NULL;}
		HuffmanTree(Node<T>* x){root = x;}
		void printTree(){printTree(root);}
		void printTree(Node<T>* r)
		{
			if (r == NULL) return;
			printTree(r->left);
			printTree(r->right);
			r->print();
		}
		void Decompress(string S){Decompress(root , S);}
		void Decompress(Node<T>* r , string S)
		{
			for (int i = 0 ; i < S.length() ; i++)
			{
				Node<T>* temp = r;
				while(temp->left != NULL && temp->right != NULL)
				{
					if(S[i] == '0') temp = temp->left;
					else if (S[i] == '1') temp = temp->right;
					i++;
				}
				cout << temp->getData().getChar();
			}
		}
};
int main()
{
	CharInfo x[10];
	for(int i = 0 ; i < 10 ; i++) x[i] = CharInfo('a'+rand()%26, rand()%10);
	MinHeap<CharInfo> heap(10);
	for(int i = 0 ; i < 10 ; i++) heap.Insert(new Node<CharInfo>(x[i]));
	HuffmanTree<CharInfo> htree(heap.CreateHuffmanTree());
	htree.printTree(); //§ is a dummy character
	htree.Decompress("0100010100111010101001111110110100101100101001010");
}
