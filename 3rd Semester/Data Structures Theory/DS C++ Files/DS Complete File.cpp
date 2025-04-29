#include <iostream>
#include <cmath>
#define MIN 0
#define MAX 1
using namespace std;
//---------------------------------------------------------------------------
template<typename T>
class Node
{
	public:
		T data;
		Node<T> *right, *left;
		Node(){right = NULL;left = NULL;}
		Node (int d)
		{
			data = d;
			right = NULL;
			left = NULL;
		}
};
//---------------------------------------------------------------------------
template<typename T>
class SinglyLinkedList
{
	private:
		Node<T>* head;
	public:
		SinglyLinkedList() {head = NULL;}
		SinglyLinkedList (Node<T>* n) {head = n;}
		~SinglyLinkedList(){DeleteList();}
		void DeleteList()
		{
			while(head != NULL)
			{
				Node<T>* temp = head;
				head = head->right;
				delete temp;
			}
		}
		void Append(T d)
		{
			Node<T>* newNode = new Node<T>(d);
			Node<T>* temp = head;
			if(head == NULL) {head = newNode;}
			else
			{
				while(temp->right != NULL)
				{
					temp = temp->right;
				}
				temp->right = newNode;
			}
		}
		void Prepend(T d)
		{
			Node<T>* newNode = new Node<T>(d);
			Node<T>* temp = head;
			if(head == NULL) {head = newNode;}
			else
			{
				newNode->right = head;
				head = newNode;
			}
		}
		void InsertAfter(T d , int pos)
		{
			Node<T>* temp = head;
			Node<T>* newNode = new Node<T>(d);
			if(head == NULL) {head = newNode;}
			else
			{
				while(temp != NULL)
				{
					if(pos > 0)
					{
						temp = temp->right;
						pos--;
					}
					else
					{
						newNode->right = temp->right;
						temp->right = newNode;
						return;
					}
				}
			}
			cout << "Invalid Position!" << endl;
		}
		T Search(T d)
		{
			Node<T> *temp = head;
			while(temp != NULL) 
			{
				if(temp->data == d) return temp->data;
				temp = temp->right;
			}
			return 0;
		}
		void DeleteNodeAtPos(int pos)
		{
			if(head == NULL) {cout << "List is already empty!" << endl;}
			else
			{
				Node<T>* temp = head;
				Node<T>* temp2 = head->right;
				if(pos == 0)
				{
					head = head->right;
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
							temp2 = temp2->right;
							pos--;
						}
						else
						{
							temp->right = temp2->right;
							delete temp2;
							return;
						}
					}
				}
			}
			cout << "Invalid Position!" << endl;
		}
		void Print()
		{
			Node<T>* temp = head;
			if (head == NULL){cout << "List is empty!" << endl;}
			else
			{
				while(temp->right != NULL)
				{
					cout << temp->data << "->";
					temp = temp->right;
				}
				cout << temp->data << "->NULL" << endl;
			}
		}
		void Reverse()
		{
			Node<T> *p1,*p2,*p3;
			p1 = NULL;
			p2 = head;
			p3 = head->right;
			while(p2 != NULL)
			{
				p2->right = p1;
				p1 = p2;
				p2 = p3;
				if(p3) p3 = p3->right;
				else break;
			}
			head = p1;
		}
};
//---------------------------------------------------------------------------
template<typename T>
class DoublyLinkedList
{
	Node<T> *head;
	public:
		DoublyLinkedList() {head = NULL;}
		DoublyLinkedList(Node<T> *n) {head = n;}
		~DoublyLinkedList(){DeleteList();}
		void DeleteList()
		{
			while(head)
			{
				Node<T> *temp = head;
				head = head->right;
				delete temp;
			}
		}
		void Append(T d)
		{
			Node<T>* newNode = new Node<T>(d);
			Node<T>* temp = head;
			if(head == NULL) {head = newNode;}
			else
			{
				while(temp->right != NULL)
				{
					temp = temp->right;
				}
				temp->right = newNode;
				newNode->left = temp;
			}
		}
		void Prepend(T d)
		{
			Node<T>* newNode = new Node<T>(d);
			Node<T>* temp = head;
			if(head == NULL) {head = newNode;}
			else
			{
				newNode->right = head;
				head->left = newNode;
				head = newNode;
			}
		}
		void InsertAfter(T d , int pos)
		{
			Node<T>* temp = head;
			Node<T>* newNode = new Node<T>(d);
			if(head == NULL) {head = newNode;}
			else
			{
				while(temp != NULL)
				{
					if(pos > 0)
					{
						temp = temp->right;
						pos--;
					}
					else
					{
						newNode->right = temp->right;
						newNode->left = temp;
						temp->right->left = newNode;
						temp->right = newNode;
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
				Node<T>* temp = head;
				if(pos == 0)
				{
					head = head->right;
					delete temp;
					return;
				}
				else
				{
					while(temp != NULL)
					{
						if(pos - 1 > 0)
						{
							temp = temp->right;
							pos--;
						}
						else
						{
							temp->left->right = temp->right;
							temp->right->left = temp->left;
							delete temp;
							return;
						}
					}
				}
			}
			cout << "Invalid Position!" << endl;
		}
		void Print()
		{
			Node<T>* temp = head;
			if (head == NULL){cout << "List is empty!" << endl;}
			else
			{
				cout << "NULL<->";
				while(temp->right != NULL)
				{
					cout << temp->data << "<->";
					temp = temp->right;
				}
				cout << temp->data << "<->NULL" << endl;
			}
		}
		void Reverse()
		{
			while(head)
			{
				Node<T> *temp = head->right;
				head->right = head->left;
				head->left = temp;
				if(!temp) break;
				head = temp;
			}
		}
};
//---------------------------------------------------------------------------
template<typename T>
class CircularSinglyLinkedList
{
	public:
		Node<T>* head;
		CircularSinglyLinkedList() {head = NULL;}
		CircularSinglyLinkedList(Node<T> *n) {head = n;}
		~CircularSinglyLinkedList(){DeleteList();}
		void DeleteList()
		{
			if(!head) return;
			Node<T> *temp = head->right;
			while(temp != head)
				{
					Node<T> *temp2 = temp->right;
					delete temp;
					temp = temp2;
				}
				delete head;
				head = NULL;
		}
		void Append(T d)
		{
			Node<T>* newNode = new Node<T>(d);
			newNode->right = head;
			Node<T>* temp = head;
			if(head == NULL) {head = newNode;head->right = head;}
			else
			{
				while(temp->right != head)
				{
					temp = temp->right;
				}
				temp->right = newNode;
			}
		}
		void Prepend(T d)
		{
			Node<T>* newNode = new Node<T>(d);
			Node<T>* temp = head;
			if(head == NULL) {head = newNode; head->right = head;}
			else
			{
				while(temp->right != head)
				{
					temp = temp->right;
				}
				temp->right = newNode;
				newNode->right = head;
				head = newNode;
			}
		}
		void InsertAfter(T d , int pos)
		{
			Node<T>* temp = head;
			Node<T>* newNode = new Node<T>(d);
			if(head == NULL) {head = newNode;head->right = head;}
			else
			{
				do
				{
					if(pos > 0)
					{
						temp = temp->right;
						pos--;
					}
					else
					{
						newNode->right = temp->right;
						temp->right = newNode;
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
				Node<T>* temp = head;
				Node<T>* temp2 = head->right;
				if(pos == 0)
				{
					while(temp->right != head)
					{
						temp = temp->right;
					}
					head = head->right;
					delete temp->right;
					temp->right = head;
					return;
				}
				else
				{
					do
					{
						if(pos - 1 > 0)
						{
							temp = temp2;
							temp2 = temp2->right;
							pos--;
						}
						else
						{
							temp->right = temp2->right;
							delete temp2;
							return;
						}
					}
					while(temp2 != head);
				}
			}
			cout << "Invalid Position!" << endl;
		}
		void Print()
		{
			Node<T>* temp = head;
			if (head == NULL){cout << "List is empty!" << endl;}
			else
			{
				while(temp->right != head)
				{
					cout << temp->data << "->";
					temp = temp->right;
				}
				cout << temp->data << "->HEAD" << endl;
			}
		}
		void Reverse()
		{
			bool x = 1;
			Node<T> *p1,*p2,*p3;
			p2 = head;
			p3 = p2->right;
			while(head->right != p2) head = head->right;
			p1 = head;
			while(p1 != head || x)
			{
				x = 0;
				p2->right = p1;
				p1 = p2;
				p2 = p3;
				if(p1 != head) p3 = p3->right;
				else break;
			}
		}
};
//---------------------------------------------------------------------------
class Search
{
	public:
		template<typename T , int n>
		T RecurLinearSearch(T (&arr)[n] , T val) {return RecurLinearSearchUtil(arr , 0 , val);}
		template<typename T , int n>
		T RecurBinarySearch(T (&arr)[n] , T val) {return RecurBinarySearchUtil(arr , 0 , n , val);}
		template<typename T , int n>
		T RecurInterpolationSearch(T (&arr)[n] , T val) {return RecurInterpolationSearchUtil(arr , 0 , n-1 , val);}
		template<typename T , int n>
		T LinearSearch(T (&arr)[n] , T val)
		{
			for (int i = 0 ; i < n ; i++)
			{
				if (arr[i] == val)
				return i;
			}
			return -1;
		}
		template<typename T , int n>
		T BinarySearch(T (&arr)[n] , T val)
		{
			int i = 0 , size = n-1;
			while(i <= size)
			{
				int mid = (i+size)/2;
				if(arr[mid] == val) return mid;
				else if (arr[mid] < val) i = mid+1;
				else size = mid-1;
			}
			return -1;
		}
		template<typename T , int n>
		T InterpolationSearch(T (&arr)[n] , T val)
		{
			int lo = 0, hi = (n - 1);
			while (lo <= hi && val >= arr[lo] && val <= arr[hi])
			{
				if (lo == hi)
				{
					if (arr[lo] == val) return lo;
					return -1;
				}
				int pos = lo + (((double)(hi - lo) /(arr[hi] - arr[lo])) * (val - arr[lo]));
				if (arr[pos] == val) return pos;
				if (arr[pos] < val)
				lo = pos + 1;
        		else hi = pos - 1;
			}
			return -1;
		}
	private:
		template<typename T , int n>
		T RecurLinearSearchUtil(T (&arr)[n] , int i , T val)
		{
			if(i == n-1) return -1;
			else if (arr[i] == val) return i;
			return RecurLinearSearchUtil(arr , i+1 , val);
		}
		template<typename T>
		T RecurBinarySearchUtil(T* arr , int i , int n , T val)
		{
			if(n >= i) 
			{
				int mid = (i+n)/2;
				if (arr[mid] == val) return mid;
				else if (arr[mid] < val) return RecurBinarySearchUtil(arr , mid+1 , n , val);
				else return RecurBinarySearchUtil(arr , i , mid-1 , val);
			}
			return -1;
		}
		template<typename T , int n>
		T RecurInterpolationSearchUtil(T (&arr)[n] , int lo , int hi , int val)
		{
			int pos;
			if (lo <= hi && val >= arr[lo] && val <= arr[hi])
			{
				pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (val - arr[lo]));
				if (arr[pos] == val) return pos;
				if (arr[pos] < val) return RecurInterpolationSearchUtil(arr, pos + 1, hi, val);
				if (arr[pos] > val) return RecurInterpolationSearchUtil(arr, lo, pos - 1, val);
			}
			return -1;
		}
};
//---------------------------------------------------------------------------
class Sort
{
	public:
		template <int n>
		int FindMax(int (&arr)[n])
		{
			int max = INT_MIN;
			for (int i = 0 ; i < n ; i++)
			{
				if (max < arr[i]) max =arr[i];
			}
			return max;
		}
		template<typename T , int n>
		void BubbleSort(T (&arr)[n])
		{
			for (int i = 0 ; i < n ; i++)
			{
				for (int j = 0 ; j < n - 1 - i ; j++)
				{
					if (arr[j] > arr[j+1])
					{
						swap(arr[j],arr[j+1]);
					}
				}
			}
		}
		template<typename T , int n>
		void RecurBubbleSort(T (&arr)[n])
		{
			RecurBubbleSort(arr , 0 , 0);
		}
		template<typename T , int n>
		int RecurBubbleSort(T (&arr)[n] , int x , int y)
		{
			if (x >= n) return 0;
			else if (y >= n - x - 1) return 0;
			else if (arr[y] > arr[y+1])
			{
				swap(arr[y] , arr[y+1]);
			}
			return RecurBubbleSort(arr , x+1 , RecurBubbleSort(arr , x , y+1));
		}
		template<typename T , int n>
		void SelectionSort(T (&arr)[n])
		{
			for (int i = 0 ; i < n ; i++)
			{
				int min = i;
				for (int j = i+1 ; j < n ; j++)
				{
					if(arr[min] > arr[j]) min = j;
				}
				swap(arr[min],arr[i]);
			}
		}
		template<typename T , int n>
		void InsertionSort(T (&arr)[n])
		{
			for (int i = 1 ; i < n ; i++)
			{
				T temp = arr[i];
				int j = i-1;
				while(j >= 0 && arr[j] > temp)
				{
					arr[j+1] = arr[j];
					j--;
				}
				arr[j+1] = temp;
			}
		}
		template<typename T , int n>
		void ShellSort(T (&arr)[n])
		{
			for (int interval = n/2 ; interval > 0 ; interval /= 2)
			{
				for (int i = interval ; i < n ; i++)
				{
					T temp = arr[i];
					int j = i - interval;
					while(j >= 0 && arr[j] > temp)
					{
						arr[j+interval] = arr[j];
						j -= interval;
					}
					arr[j+interval] = temp;
				}
			}
		}
		template<typename T , int n>
		void MergeSort(T (&arr)[n]) 
		{
			MergeSort(arr , 0 , n-1);
		}
		template<typename T , int n>
		void MergeSort(T (&arr)[n] , int l , int r)
		{
			if (l >= r) return;
			int m = (l + r) / 2;
			MergeSort(arr , l , m);
			MergeSort(arr , m + 1 , r);
			Merge(arr , l , m , r);
		}
		template<typename T , int n>
		void Merge(T (&arr)[n] , int l , int m , int r)
		{
			int n1 = m - l + 1;
			int n2 = r - m;
			T L[n1] , R[n2];
			for (int i = 0 ; i < n1 ; i++) L[i] = arr[i+l];
			for (int i = 0 ; i < n2 ; i++) R[i] = arr[i+m+1];
			int i = 0 , j = 0 , k = l;
			while (i < n1 && j < n2)
			{
				if (L[i] <= R[j]) arr[k++] = L[i++];
				else if (L[i] > R[j]) arr[k++] = R[j++];
			}
			while(i < n1)arr[k++] = L[i++];
			while(j < n2)arr[k++] = R[j++];
		}
		template<int n>
		void OptimizedMergeSort(int (&arr)[n]) 
		{
			OptimizedMergeSort(arr , 0 , n-1, FindMax(arr) + 1);
		}
		template<int n>
		void OptimizedMergeSort(int (&arr)[n] , int l , int r , int max)
		{
			if (l >= r) return;
			int m = (l + r) / 2;
			OptimizedMergeSort(arr , l , m , max);
			OptimizedMergeSort(arr , m + 1 , r , max);
			OptimizedMerge(arr , l , m , r , max);
		}
		template<int n>
		void OptimizedMerge(int (&arr)[n] , int l , int m , int r , int max)
		{
			int i = l , j = m + 1 , k = l;
			while (i <= m && j <= r)
			{
				if (arr[i] % max <= arr[j] % max)
				{
					arr[k] += (arr[i] % max) * max;
					i++;
				}
				else
				{
					arr[k] += (arr[j] % max) * max;
					j++;
				}
				k++;
			}
			while(i <= m)
			{
				arr[k] += (arr[i] % max) * max;
				i++;
				k++;
			}
			while(j <= r)
			{
				arr[k] += (arr[j] % max) * max;
				j++;
				k++;
			}
			for (int i = l; i <= r; i++) arr[i] /= max;
		}
		template<typename T , int n>
		void RadixSort(T (&arr)[n])
		{
			
		}
		template<typename T , int n>
		void CombSort(T (&arr)[n])
		{
			
		}
		template<typename T , int n>
		void QuickSort(T (&arr)[n])
		{
			QuickSort(arr , 0 , n - 1);
		}
		template<typename T , int n>
		void QuickSort(T (&arr)[n] , int l , int r)
		{
			if (l >= r) return;
			int pivotIndex = partition(arr , l , r);
			QuickSort(arr , l , pivotIndex - 1);
			QuickSort(arr , pivotIndex + 1 , r);
		}
		template<typename T , int n>
		int partition(T (&arr)[n] , int l , int r)
		{
			T pivot = arr[r];
			int i = l;
			for (int j = l ; j < r ; j++)
			{
				if (arr[j] <= pivot)
				{
					swap(arr[j],arr[i++]);
				}
			}
			swap(arr[r],arr[i]);
			return i;
		}
};
//---------------------------------------------------------------------------
template<typename T>
class BST
{
	public:
		BST() {root = NULL;}
		~BST() {deleteTree(root);root = NULL;}
		int Height(){return Height(root);}
		void Insert(T d){root = Insert(d , root);}
		Node<T>* Search(T d){return Search(d , root);}
		void Delete(T d){root = Delete(d , root);}
		void PreOrder(){PreOrder(root);}
		void PrintBalanceFactor(){PrintBalanceFactor(root);}
		bool CheckBSTAVL(){return CheckBSTAVL(root);}
		void PrintTree(){PrintTree(root, 2);}
		Node<T> *root;
	protected:
		void deleteTree(Node<T> *t)
		{
			if(t == NULL) return;
			deleteTree(t->left);
			deleteTree(t->right);
			delete t;
		}
		Node<T>* MinValue(Node<T> *t)
		{
			if (t->left == NULL) return t;
			return MinValue(t->left);
		}
		int Height(Node<T> *t)
		{
			if (t == NULL) return 0;
			return 1 + max(Height(t->left),Height(t->right));
		}
		int CalcBalanceFactor(Node<T> *t)
		{
			if (t == NULL) return 0;
			return Height(t->left) - Height(t->right);
		}
		void PreOrder(Node<T> *t)
		{
			if (t == NULL) return;
			cout << t->data << " ";
			PreOrder(t->left);
			PreOrder(t->right);
		}
		Node<T>* Search(T d, Node<T> *t)
		{
			if (t == NULL || t->data == d) return t;
			else if (t->data > d) return Search(d, t->left);
			else if (t->data < d) return Search(d, t->right);
		}
		Node<T>* Insert(T d , Node<T> *t)
		{
			if (t == NULL) return new Node<T>(d);
			else if (t->data > d) t->left = Insert(d , t->left);
			else if (t->data < d) t->right = Insert(d , t->right);
			else return t;
		}
		Node<T>* Delete(T d, Node<T> *t)
		{
			if (t == NULL) return t;
			else if (d < t->data) t->left = Delete(d, t->left);
			else if (d > t->data) t->right = Delete(d, t->right);
			else
			{
				if(t->left == NULL)
				{
					Node<T> *temp = t->right;
					delete t;
					return temp;
				}
				else if(t->right == NULL)
				{
					Node<T> *temp = t->left;
					delete t;
					return temp;
				}
				else
				{
					Node<T> *temp = MinValue(t->right);
					t->data = temp->data;
					t->right = Delete(temp->data , t->right);
				}
			}
			return t;
		}
		void PrintBalanceFactor(Node<T> *t)
		{
			if (t == NULL) return;
			cout << t->data << ", Balance Factor: " << CalcBalanceFactor(t) << endl;
			PrintBalanceFactor(t->left);
			PrintBalanceFactor(t->right);
		}
		bool CheckBSTAVL(Node<T> *t)
		{
			if(t == NULL) return true;
			int BalanceFactor = CalcBalanceFactor(t);
			if(t->left != NULL && t->left->data > t->data || BalanceFactor < -1 || BalanceFactor > 1) return false;
			if(t->right != NULL && t->right->data < t->data || BalanceFactor < -1 || BalanceFactor > 1) return false;
			return (CheckBSTAVL(t->left) && CheckBSTAVL(t->right));
		}
		void PrintTree(Node<T> *r, int space)
		{
			if (r == NULL) return;
			space += 10;
			PrintTree(r->right, space);
			cout << endl;
			for (int i = 10; i < space; i++) cout << " ";
			cout << r->data << "\n";
			PrintTree(r->left, space);
		}
};
//---------------------------------------------------------------------------
template<typename T>
class AVL : public BST<T>
{
	public:
		AVL() : BST<T>() {}
		~AVL(){}
		void Insert(T d){BST<T>::root = Insert(d , BST<T>::root);}
		void Delete(T d){BST<T>::root = Delete(d, BST<T>::root);}
	protected:
		Node<T>* RightRotate(Node<T> *t)
		{
			Node<T> *x = t->left;
			Node<T> *y = x->right;
			t->left = y;
			x->right = t;
			return x;
		}
		Node<T>* LeftRotate(Node<T> *t)
		{
			Node<T> *x = t->right;
			Node<T> *y = x->left;
			t->right = y;
			x->left = t;
			return x;
		}
		Node<T>* BalanceInsert(T d , Node<T> *t)
		{
			int BalanceFactor = BST<T>::CalcBalanceFactor(t);
			if (BalanceFactor > 1 && d < t->left->data) return RightRotate(t);
			if (BalanceFactor < -1 && d > t->right->data) return LeftRotate(t);
			if (BalanceFactor > 1 && d > t->left->data) 
			{
				t->left = LeftRotate(t->left);
				return RightRotate(t);
			}
			if (BalanceFactor < -1 && d < t->right->data) 
			{
				t->right = RightRotate(t->right);
				return LeftRotate(t);
			}
			return t;
		}
		Node<T>* BalanceDelete(T d, Node<T> *t)
		{
			int BalanceFactor = BST<T>::CalcBalanceFactor(t);
			if (BalanceFactor > 1 && BST<T>::CalcBalanceFactor(t->left) >= 0) return RightRotate(t);
			if (BalanceFactor > 1 && BST<T>::CalcBalanceFactor(t->left) < 0) 
			{
				t->left = LeftRotate(t->left);
				return RightRotate(t);
			}
			if (BalanceFactor < -1 && BST<T>::CalcBalanceFactor(t->right) <= 0) return LeftRotate(t);
			if (BalanceFactor < -1 && BST<T>::CalcBalanceFactor(t->right) > 0)
			{
				t->right = RightRotate(t->right);
				return LeftRotate(t);
			}
			return t;
		}
		Node<T>* Insert(T d , Node<T> *t)
		{
			if (t == NULL)
			{
				t = new Node<T>(d);
				return t;
			}
			else if (t->data > d) t->left = Insert(d , t->left);
			else if (t->data < d) t->right = Insert(d , t->right);
			else return t;
			return BalanceInsert(d , t);
		}
		Node<T>* Delete(T d , Node<T>* t)
		{
			if (t == NULL) return t;
			else if (d < t->data) t->left = Delete(d, t->left);
			else if (d > t->data) t->right = Delete(d, t->right);
			else
			{
				if(t->left == NULL)
				{
					Node<T> *temp = t->right;
					delete t;
					return temp;
				}
				else if(t->right == NULL)
				{
					Node<T> *temp = t->left;
					delete t;
					return temp;
				}
				else
				{
					Node<T> *temp = BST<T>::MinValue(t->right);
					t->data = temp->data;
					t->right = Delete(temp->data , t->right);
				}
			}
			return BalanceDelete(d,t);
		}
};
//---------------------------------------------------------------------------
template<typename T, int N, bool Extreme>
class Heap
{
	T arr[N];
	int capacity;
	int top;
    int Parent(int i){return (i - 1) / 2;}
    int Left(int i){return 2 * i + 1;}
    int Right(int i){return 2 * i + 2;}
	public:
		Heap() {top = 0;capacity = N;}
	    void Insert(T x)
	    {
	    	if(top == capacity) return;
		    int i = top++;
		    arr[i] = x;
		    while(i != 0 && ((Extreme)?(arr[Parent(i)] < arr[i]):(arr[Parent(i)] > arr[i])))
			{
		        swap(arr[i], arr[Parent(i)]);
		        i = Parent(i);
		    }
		}
	    T Extract()
	    {
	    	if(top == 0) {}
			else if(top == 1)
			{
		        top--;
		        return arr[0];
		    }
			else
			{
		        T root = arr[0];
		        arr[0] = arr[top - 1];
		        top--;
		        Heapify(0);
		        return root;
		    }
		}
	    void Heapify(int i)
	    {
	    	int l = Left(i);
		    int r = Right(i);
		    int index = i;
		    if((l < top) && ((Extreme)?(arr[l] > arr[index]):(arr[l] < arr[index]))) index = l;
			if((r < top) && ((Extreme)?(arr[r] > arr[index]):(arr[r] < arr[index]))) index = r;
		    if(index != i)
			{
		        swap(arr[i], arr[index]);
		        Heapify(index);
		    }
		}
	    void PrintHeap()
	    {
	    	int Exponent = 0;
		    int Val = 1;
		    for(int i = 0; i < top; i++)
		    {
		        if(i == Val)
				{
		            cout << endl;
		            Exponent += 1;
		            Val += (1 << Exponent);
		        }
		        cout << arr[i] << "  ";
		    }
		    cout << endl;
		}
		void Delete(int i) {Delete(i, Extreme?INT_MAX:INT_MIN); Extract();}
		void Delete(int i, T Val)
		{
			cout << "Deleting value: " << arr[i] << endl;
			arr[i] = Val;
			while(i != 0 && ((Extreme)?(arr[Parent(i)] < arr[i]):(arr[Parent(i)] > arr[i])))
			{
				swap(arr[i], arr[Parent(i)]);
				i = Parent(i);
			}
		}
};
class divhash
{
	public:
		int operator () (int key,int n){return key%n;}
};
class foldhash
{
	public:
		int operator () (int key,int n)
		{
			int x = key/100000000;
			int y = key%100000000/10000;
			int z = key%10000;
			return (x+y+z)%n;
		}
};
class midsquarehash
{
	public:
		int NumberOfDigits(int v)
		{
			int c = 0;
			while(v > 0)
			{
				c++;
				v /= 10;
			}
			return c;
		}
		int operator () (int key, int n)
		{
			key *= key;
			int d = pow(10,NumberOfDigits(key)-2);
			if(!d)d = n;
			return key / 10 % d;
		}
};
class multhash
{
	public:
		int operator () (int key, int n){return (int)(n * fmod((key * 0.324658),1));}
};
template<int n, typename T = divhash>
class HashTable
{
	private:
		SinglyLinkedList<int> *Map;
		T HashFunction;
	public:
		HashTable(){Map = new SinglyLinkedList<int>[n];}
		~HashTable(){delete[] Map;}
		void Insert(int data)
		{
			int index = HashFunction(data,n);
			if(index < 0)index += n;
			Map[index].Append(data);
		}
		void Print()
		{
			for(int i = 0 ; i < n ; i++) Map[i].Print();
		}
		int Find(int data)
		{
			int index = HashFunction(data,n);
			if(index < 0)index += n;
			cout << index;
			return Map[index].Search(data);
		}
};
int main()
{
//	cout << "LinkedLists: Singly, Doubly, CircularSingly, CircularDoubly" << endl
//	<<		"Search: Linear, Binary, Interpolation (Iterative and Recursive)" << endl
//	<<		"Sort: Bubble, Selection, Insertion, Shell, Merge, Quick (Some have Recursive, Iterative, or both)" << endl
//	<<		"Binary Search Tree" << endl
//	<<		"AVL Tree" << endl
//	<<		"Heap: Min, Max" << endl
//	<<		"Hashing" << endl; 
	Sort s;
	int arr[] = {15,5,132,13,1565,16,16,516,51,51,3102,51,6,571,7,1976,4197,066,0};
	s.QuickSort(arr);
	for(int i = 0 ; i < sizeof(arr)/4 ; i++) cout << arr[i] << ' ';
}
