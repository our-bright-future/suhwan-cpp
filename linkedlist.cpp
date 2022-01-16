#include "linkedlist.h"

void ShowList(node* head)
{
	node* curr = head->nextnode;
	while (curr != NULL)
	{
		cout << curr->data << " ";
		curr = curr->nextnode;
	}
}

void FreeList(node* head)
{
	node* curr = head->nextnode;
	while (curr != NULL)
	{
		node* next = curr->nextnode;
		delete curr;
		curr = next;
	}
	delete head;
}

void AddFirst(node* head, int data) 
{
	node* newnode = new node;
	newnode->nextnode = head->nextnode;
	newnode->data = data;

	head->nextnode = newnode;
}

void AddLast(node* head, int data) 
{
	node* temp = head->nextnode;
	while (temp->nextnode != NULL)
	{
		temp = temp->nextnode;
	}
	node* newnode = new node;
	temp->nextnode = newnode;
	newnode->nextnode = NULL;
	newnode->data = data;
}

void AddNode(node* head, int n, int data)
{
	node* temp = head->nextnode;
	for (int i = 0; i < n - 1; i++)
	{
		if (temp->nextnode != NULL)
		{
			temp = temp->nextnode;
		}
	}
	node* newnode = new node;
	newnode->nextnode = temp->nextnode;
	temp->nextnode = newnode;
	newnode->data = data;
}

void DeleteFirst(node* head) 
{
	node* del = head->nextnode;
	head->nextnode = del->nextnode;
	delete del;
}

void DeleteLast(node* head)
{
	node* temp1 = head->nextnode;
	node* temp2 = temp1;
	while (temp1->nextnode != NULL)
	{
		temp2 = temp1;
		temp1 = temp1->nextnode;
	}
	delete temp1;
	temp2->nextnode = NULL;
}

void DeleteNode(node* head, int n)
{
	node* temp1 = head->nextnode;
	node* temp2 = temp1;
	for (int i = 0; i < n - 1; i++)
	{
		if (temp1->nextnode != NULL)
		{
			temp2 = temp1;
			temp1 = temp1->nextnode;
		}
	}
	temp2->nextnode = temp1->nextnode;
	delete temp1;
}

int GetData(node* head, int n)  
{
	node* temp = head->nextnode;
	for (int i = 0; i < n - 1; i++)
	{
		if (temp->nextnode != NULL)
		{
			temp = temp->nextnode;
		}
	}
	return temp->data;
}
