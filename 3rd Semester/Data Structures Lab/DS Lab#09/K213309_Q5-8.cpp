#include <iostream>
#include <cstdlib>
using namespace std;
class Node
{
	int data;
	Node *left, *right;
	public:
		Node()
		{
			left = right = NULL;
		}
		Node(int d)
		{
			data = d;
			left = right = NULL;
		}
		friend class BST;
		friend class AVL;
};
class BST
{
	public:
		BST(){root = NULL;}
		~BST()
		{
			deleteTree(root);
			root = NULL;
		}
		int Height(){return Height(root);}
		void Insert(int d){root = Insert(d , root);}
		Node* Search(int d){return Search(d , root);}
		void Delete(int d){root = Delete(d , root);}
		void PreOrder(){PreOrder(root);}
		void PrintBalanceFactor(){PrintBalanceFactor(root);}
		bool CheckBSTAVL(){return CheckBSTAVL(root);}
	protected:
		Node *root;
		void deleteTree(Node *t)
		{
			if(t == NULL) return;
			deleteTree(t->left);
			deleteTree(t->right);
			delete t;
		}
		Node* MinValue(Node *t)
		{
			if (t->left == NULL) return t;
			return MinValue(t->left);
		}
		int Height(Node *t)
		{
			if (t == NULL) return 0;
			return 1 + max(Height(t->left),Height(t->right));
		}
		int CalcBalanceFactor(Node *t)
		{
			if (t == NULL) return 0;
			return Height(t->left) - Height(t->right);
		}
		void PreOrder(Node *t)
		{
			if (t == NULL) return;
			cout << t->data << " ";
			PreOrder(t->left);
			PreOrder(t->right);
		}
		Node* Search(int d, Node *t)
		{
			if (t == NULL || t->data == d) return t;
			else if (t->data > d) return Search(d, t->left);
			else if (t->data < d) return Search(d, t->right);
		}
		Node* Insert(int d , Node *t)
		{
			if (t == NULL)
			{
				t = new Node(d);
				return t;
			}
			else if (t->data > d) t->left = Insert(d , t->left);
			else if (t->data < d) t->right = Insert(d , t->right);
			else return t;
		}
		Node* Delete(int d, Node *t)
		{
			if (t == NULL) return t;
			else if (d < t->data) t->left = Delete(d, t->left);
			else if (d > t->data) t->right = Delete(d, t->right);
			else
			{
				if(t->left == NULL)
				{
					Node *temp = t->right;
					delete t;
					return temp;
				}
				else if(t->right == NULL)
				{
					Node *temp = t->left;
					delete t;
					return temp;
				}
				else
				{
					Node *temp = MinValue(t->right);
					t->data = temp->data;
					t->right = Delete(temp->data , t->right);
					return t;
				}
			}
		}
		void PrintBalanceFactor(Node *t)
		{
			if (t == NULL) return;
			cout << t->data << ", Balance Factor: " << CalcBalanceFactor(t) << endl;
			PrintBalanceFactor(t->left);
			PrintBalanceFactor(t->right);
		}
		bool CheckBSTAVL(Node *t)
		{
			if(t == NULL) return true;
			int BalanceFactor = CalcBalanceFactor(t);
			if(t->left != NULL && t->left->data > t->data || BalanceFactor < -1 || BalanceFactor > 1) return false;
			if(t->right != NULL && t->right->data < t->data || BalanceFactor < -1 || BalanceFactor > 1) return false;
			return (CheckBSTAVL(t->left) && CheckBSTAVL(t->right));
		}
};
class AVL : public BST
{
	public:
		AVL() : BST() {}
		~AVL(){}
		void Insert(int d){root = Insert(d , root);}
	protected:
		Node* RightRotate(Node *t)
		{
			Node *x = t->left;
			Node *y = x->right;
			t->left = y;
			x->right = t;
			return x;
		}
		Node* LeftRotate(Node *t)
		{
			Node *x = t->right;
			Node *y = x->left;
			t->right = y;
			x->left = t;
			return x;
		}
		Node* Balance(int d , Node *t)
		{
			int BalanceFactor = CalcBalanceFactor(t);
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
		Node* Insert(int d , Node *t)
		{
			if (t == NULL)
			{
				t = new Node(d);
				return t;
			}
			else if (t->data > d) t->left = Insert(d , t->left);
			else if (t->data < d) t->right = Insert(d , t->right);
			else return t;
			return Balance(d , t);
		}
};
int main()
{
	BST tree;
	tree.Insert(10);
	tree.Insert(11);
	tree.Insert(5);
	tree.Insert(4);
	tree.Insert(3);
	cout << "Task 5" << endl << endl;
	tree.PrintBalanceFactor();
	
	AVL atree;
	atree.Insert(10);
	atree.Insert(11);
	atree.Insert(5);
	atree.Insert(4);
	atree.Insert(3);
	cout << endl << "Task 6" << endl << endl;
	atree.PrintBalanceFactor();
	
	cout << endl << "Task 7" << endl << endl;
	tree.CheckBSTAVL()? cout << "Valid BST & AVL" << endl : cout << "Invalid BST & AVL" << endl;
	atree.CheckBSTAVL()? cout << "Valid BST & AVL" << endl : cout << "Invalid BST & AVL" << endl;
	
	cout << endl << "Task 8" << endl << endl;
	atree.~AVL();
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	for (int i = 0 ; i < sizeof(arr)/sizeof(arr[i]) ; i++) atree.Insert(arr[i]);
	cout << "PreOrder traversal of AVL Tree: "; 
	atree.PreOrder();
}

