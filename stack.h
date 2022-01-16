#pragma once
//#ifndef __STACK_H__
//# define __STACK_H__
#include <iostream>

using namespace std;

struct node
{
	node* next;
	int data;
};

struct stack
{
	node* top;
	int size;
};

void pop(stack* s);
void push(stack* s, int data);
int top(stack* s);
bool empty(stack* s);
int size(stack* s);