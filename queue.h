#pragma once
//#ifndef __QUEUE_H__
//#define __QUEUE_H__

#include <iostream>

using namespace std;

struct node
{
	node* next;
	int data;
};

struct queue
{
	node* head;
	node* tail;
	int size;
};

void push(queue* q, int data);
void pop(queue* q);
int front(queue* q);
int back(queue* q);
int size(queue* q);
bool empty(queue* q);

