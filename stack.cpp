#include "stack.h"

void pop(stack* s)
{
	if (empty(s))
	{
		cout << "stack is empty\n";
		return;
	}
	node* temp;
	temp = s->top;
	s->top = s->top->next;
	delete temp;
	s->size--;
}

void push(stack* s, int data)
{
	node* newnode = new node;
	newnode->data = data;
	newnode->next = s->top;
	s->top = newnode;
	s->size++;
}

int top(stack* s)
{
	if (empty(s))
	{
		cout << "stack is empty\n";
		return -1;
	}
	return s->top->data;
}

bool empty(stack* s)
{
	if (s->size == 0)
		return true;
	else 
		return false;
}

int size(stack* s)
{
	return s->size;
}
