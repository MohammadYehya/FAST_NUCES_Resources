#include <iostream>
#include <stack>
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
};
class BST
{
	Node *root;
	Node *MinValue(Node *t)
	{
		if (t->left == NULL) return t;
		return MinValue(t->left);
	}
	Node *Search(int d, Node *t)
	{
		if (t == NULL || t->data == d) return t;
		else if (t->data > d) return Search(d, t->left);
		else if (t->data < d) return Search(d, t->right);
	}
	//Task 2
	Node* InsertRecur(int d , Node *t)
	{
		if (t == NULL)
		{
			t = new Node(d);
			return t;
		}
		else if (t->data > d) t->left = InsertRecur(d , t->left);
		else if (t->data < d) t->right = InsertRecur(d , t->right);
		else return t;
	}
	//Task 3 A
	void PreOrderRe(Node *t)
	{
		if (t == NULL) return;
		cout << t->data << " ";
		PreOrderRe(t->left);
		PreOrderRe(t->right);
	}
	void InOrderRe(Node *t)
	{
		if (t == NULL) return;
		InOrderRe(t->left);
		cout << t->data << " ";
		InOrderRe(t->right);
	}
	void PostOrderRe(Node *t)
	{
		if (t == NULL) return;
		PostOrderRe(t->left);
		PostOrderRe(t->right);
		cout << t->data << " ";
	}
	//Task 3 B
	void InOrderIt(Node *t)
	{
	    stack<Node*> s;
	    Node *temp = t;
	    while (temp != NULL || !s.empty() )
	    {
	        if(temp != NULL)
	        {
	        	s.push(temp);
	        	temp = temp->left;
			}
			else
			{
				temp = s.top();
				s.pop();
				cout << temp->data << " ";
				temp = temp->right;
			}
	    }
	}
	void PreOrderIt(Node *t)
	{
	    stack<Node*> s;
	    Node *temp = t;
	    Node *pre = NULL;
	    while (temp != NULL || !s.empty())
	    {
	        if(temp != NULL)
	        {
	        	cout << temp->data << " ";
	        	s.push(temp);
	        	temp = temp->left;
			}
			else
			{
				pre = s.top();
				s.pop();
				temp = pre->right;
			}
	    }
	}
	void PostOrderIt(Node *t)
	{
	    stack<Node*> s;
	    stack<Node*> r;
	    Node *temp = t;
	    while (temp != NULL || !s.empty())
	    {
	        if(temp != NULL)
	        {
	        	if(temp->right != NULL) r.push(temp->right);
	        	s.push(temp);
	        	temp = temp->left;
			}
			else
			{
				temp = s.top();
				if(!r.empty() && temp->right == r.top()) 
				{
					temp = r.top();
					r.pop();
				}
				else
				{
					cout << temp->data << " ";
					s.pop();
					temp = NULL;
				}
			}
	    }
	}
	//Task 4
	Node *DeleteR(int d, Node *t)
	{
		if (t == NULL) return t;
		else if(t->data < d) t->right = DeleteR(d, t->right);
		else if (t->data > d) t->left = DeleteR(d, t->left);
		else
		{
			if (t->left == NULL)
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
				t->right = DeleteR(temp->data , t->right);
			}
		}
	}
	void RangeDeleteR(int lb, int ub, Node *t)
	{
		if (t == NULL) return;
		if(t->data < lb || t->data > ub) t = DeleteR(t->data , root);
		RangeDeleteR(lb, ub, t->left);
		RangeDeleteR(lb, ub, t->right);
	}
	public:
		BST():root(NULL){}
		void Insert(int d){root = InsertRecur(d, root);}
		void PreOrder(){PreOrderRe(root);}
		void InOrder(){InOrderRe(root);}
		void PostOrder(){PostOrderRe(root);}
		void PreOrderIt(){PreOrderIt(root);}
		void InOrderIt(){InOrderIt(root);}
		void PostOrderIt(){PostOrderIt(root);}
		void Delete(int d){root = DeleteR(d, root);}
		void RangeDelete(int lb, int ub)
		{
			RangeDeleteR(lb,ub,root);
			if(root->data < lb || root->data > ub) root = DeleteR(root->data , root);
		}
};
int main()
{
	BST tree;
	int arr[7] = {15,10,20,8,12,16,25};
	int v1 = 10 , v2 = 16;
	
	cout << "Task 2" << endl << endl;
	
	for(int i = 0 ; i < 7 ; i++) 
	{
		cout << "Inserting value: " << arr[i] << endl;
		tree.Insert(arr[i]);
	}
	
	cout << endl <<  "Task 3" << endl << endl;
	
	cout << "Inorder Recursive: "; tree.InOrder(); cout << endl;
	cout << "Preorder Recursive: "; tree.PreOrder(); cout << endl;
	cout << "Postorder Recursive: "; tree.PostOrder(); cout << endl;
	cout << "Inorder Iterative: "; tree.InOrderIt(); cout << endl;
	cout << "Preorder Iterative: "; tree.PreOrderIt(); cout << endl;
	cout << "Postorder Iterative: "; tree.PostOrderIt(); cout << endl;
	
	cout << endl << "Task 4" << endl << endl;
	
	cout << "Valid range " << v1 << "-" << v2 << endl;
	tree.RangeDelete(v1,v2);
	cout << "Printing Inorder: ";
	tree.PreOrderIt();
}

