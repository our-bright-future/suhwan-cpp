#include "deque.h"

void push_front(deque* d, int data)
{
	node* newnode = new node;
	if (empty(d))
	{
		d->head = newnode;
		d->tail = newnode;
	}
	else
	{
		d->head->pre = newnode;
		newnode->next = d->head;
		d->head = newnode;
	}
	newnode->data = data;
	d->size++;
}

void push_back(deque* d, int data)
{
	node* newnode = new node;
	if (empty(d))
	{
		d->head = newnode;
		d->tail = newnode;
	}
	else
	{
		d->tail->next = newnode;
		newnode->pre = d->tail;
		d->tail = newnode;
	}
	newnode->data = data;
	d->size++;
}

int pop_front(deque* d)
{
	if (empty(d))
	{
		cout << "deque is empty\n";
		return -1;
	}
	int a = d->head->data;
	node* temp;
	temp = d->head;
	if (size(d) == 1)
	{
		d->size--;
		delete temp;
		return a;
	}
	d->head = d->head->next;
	delete temp;
	d->size--;
	return a;
}

int pop_back(deque* d)
{
	if (empty(d))
	{
		cout << "deque is empty\n";
		return -1;
	}
	int a = d->tail->data;
	node* temp;
	temp = d->tail;
	if (size(d) == 1)
	{
		d->size--;
		delete temp;
		return a;
	}
	d->tail = d->tail->pre;
	delete temp;
	d->size--;
	return a;
}

int front(deque* d)
{
	if (empty(d))
		return -1;
	else if (d->head == NULL)
		return -1;
	else
		return d->head->data;
}

int back(deque* d)
{
	if (empty(d))
		return -1;
	else if (d->tail == NULL)
		return -1;
	else
		return d->tail->data;
}

bool empty(deque* d)
{
	if (d->size == 0)
		return true;
	else
		return false;
}

int size(deque* d)
{
	return d->size;
}