#pragma once
#include <iostream>

using namespace std;

struct node
{
	node* left;
	node* right;
	int data;
	int depth;
};

typedef struct binary_search_tree
{
	node* root;
	int size;
	int depth;
}bst;

bst init_bst();
void insert(bst* t, int data);
node* find(bst* t, int target);	//target�� ������ NULL ��ȯ
int erase(bst* t, int target);	//target�������� 1, ��� ���������� -1 ��ȯ