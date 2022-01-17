#pragma once
//#ifndef __DEQUE_H__
//#define __DEQUE_H__

#include <iostream>

using namespace std;

struct node
{
	node* next;
	node* pre;
	int data;
};

struct deque
{
	node* head;
	node* tail;
	int size;
};

void push_front(deque* d, int data);
void push_back(deque* d, int data);
int pop_front(deque* d);
int pop_back(deque* d);
int front(deque* d);
int back(deque* d);
bool empty(deque* d);
int size(deque* d);
