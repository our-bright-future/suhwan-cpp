#include<iostream>

using namespace std;

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
