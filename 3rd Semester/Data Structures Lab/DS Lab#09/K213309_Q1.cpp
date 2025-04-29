#include <iostream>
using namespace std;
class Node
{
	public:
		int data;
		Node *left, *right;
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
};
class BST
{
	public:
		Node *root;
		BST(){root = NULL;}
		~BST()
		{
			deleteTree(root);
			root = NULL;
		}
		void deleteTree(Node *t)
		{
			if(t == NULL) return;
			deleteTree(t->left);
			deleteTree(t->right);
			delete t;
		}
		bool checkValidBST(Node *t)
		{
			if(t == NULL) return true;
			if(t->left != NULL && t->left->data > t->data) return false;
			if(t->right != NULL && t->right->data < t->data) return false;
			return (checkValidBST(t->left) && checkValidBST(t->right));
		}
};
int main()
{
	BST tree;
	tree.root = new Node(100);
	tree.root->left = new Node(220);
	tree.root->right = new Node (120);
	tree.checkValidBST(tree.root)? cout << "Valid Tree" << endl : cout << "Invalid Tree" << endl;
	tree.~BST();
	
	
	tree.root = new Node(100);
	tree.root->left = new Node(10);
	tree.root->right = new Node(1000);
	tree.checkValidBST(tree.root)? cout << "Valid Tree" << endl : cout << "Invalid Tree" << endl;
}
