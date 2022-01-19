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
node* find(bst* t, int target);	//target이 없으면 NULL 반환
int erase(bst* t, int target);	//target지웠으면 1, 없어서 못지웠으면 -1 반환