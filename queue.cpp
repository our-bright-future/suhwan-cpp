#include "queue.h"

void push(queue* q, int data)
{
	node* newnode = new node;
	if (empty(q))
	{
		q->head = newnode;
		q->tail = newnode;
	}
	else
	{
		q->tail->next = newnode;
		q->tail = newnode;
	}
	newnode->data = data;
	q->size++;
}

void pop(queue* q)
{
	if (empty(q))
	{
		cout << "queue is empty\n";
		return;
	}
	node* temp;
	temp = q->head;
	q->head = temp->next;
	delete temp;
	q->size--;
}

int front(queue* q)
{
	if (empty(q))
	{
		cout << "queue is empty, return -1 \n";
		return -1;
	}
	return q->head->data;
}

int back(queue* q)
{
	if (empty(q))
	{
		cout << "queue is empty, return -1 \n";
		return -1;
	}
	return q->tail->data;
}

int size(queue* q)
{
	return q->size;
}

bool empty(queue* q)
{
	if (q->size == 0)
		return true;
	else
		return false;
}