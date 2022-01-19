#include "binary_search_tree.h"

int erase(bst* t, int target)
{
	node* tnode = find(t, target);
	if (tnode != NULL)
	{
		if (tnode->right == NULL && tnode->left == NULL)
		{
			delete tnode;
			return 1;
		}
		else if (tnode->right != NULL && tnode->left != NULL)
		{
			node* temp = tnode->right;
			while (temp->left != NULL)
			{
				temp = temp->left;
			}
			int a = temp->data;
			erase(t, a);
			tnode->data = a;
			return 1;
		}
		else
		{
			node* temp = tnode->right == NULL ? tnode->left : tnode->right;
			tnode->data = temp->data;
			delete temp;
			return 1;
		}
	}
	else return -1;
}

node* find(bst* t, int target)
{
	node* temp;
	temp = t->root;
	while (temp->data != target)
	{
		if (temp->data < target)
		{
			if (temp->right == NULL)
				return NULL;
			temp = temp->right;
		}
		else
		{
			if (temp->left == NULL)
				return NULL;
			temp = temp->left;
		}
	}
	return temp;
}

void insert(bst* t, int data)
{
	node* newnode = new node;
	newnode->depth = 0;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->data = data;
	if (t->size == 0)
	{
		t->root = newnode;
		t->size++;
		return;
	}
	else
	{
		newnode->depth = 1;
		node* temp = t->root;
		while (1)
		{
			if (temp->data < data) //current node data < input data -> push right
			{
				if (temp->right == NULL)
				{
					temp->right = newnode;
					if (t->depth < newnode->depth) t->depth = newnode->depth;
					t->size++;
					break;
				}
				else
				{
					temp = temp->right;
					newnode->depth++;
				}
			}
			else if(temp->data > data)	//current node data > input data -> push left
			{
				if (temp->left == NULL)
				{
					temp->left = newnode;
					if (t->depth < newnode->depth) t->depth = newnode->depth;
					t->size++;
					break;
				}
				else
				{
					temp = temp->left;
					newnode->depth++;
				}
			}
			else						//current node data == input data -> do nothing
				break;
		}
	}
}

bst init_bst()
{
	bst bst;
	bst.root = NULL;
	bst.size = 0;
	bst.depth = 0;
	return bst;
}


