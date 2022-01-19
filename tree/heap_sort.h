#pragma once
//#ifndef __HEAP_SORT_H__
//#define __HEAP_SORT_H__

#include<iostream>

using namespace std;

void binarytree(int* arr, int size);
void heapsort(int* arr, int size);

void binarytree(int* arr, int size)
{
	for (int i = 1; i < size; i++)
	{
		int c = i;
		do
		{
			int root = (c - 1) / 2;
			if (arr[root] < arr[c])
			{
				int temp = arr[root];
				arr[root] = arr[c];
				arr[c] = temp;
			}
			c = root;
		} while (c != 0);
	}
}

void heapsort(int* arr, int size)
{
	for (int i = size - 1; i >= 0; i--)
	{
		int root = 0;
		int temp = arr[i];
		arr[i] = arr[root];
		arr[root] = temp;
		int a;
		do
		{
			a = 2 * root + 1;
			if (a < i - 1 && arr[a] < arr[a + 1])
			{
				a++;
			}
			if (a < i && arr[root] < arr[a])
			{
				temp = arr[root];
				arr[root] = arr[a];
				arr[a] = temp;
			}
			root = a;
		} while (2 * a + 1 < i);
	}
}