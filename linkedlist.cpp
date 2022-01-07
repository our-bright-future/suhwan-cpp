#include <iostream>

using namespace std;

typedef struct node
{
	node* nextnode;
	int data;
}

void AddFirst(node* head, int data);		//맨앞쪽 바로 다음에 node 추가
void AddLast(node* head, int data);			//맨 뒤에 node 추가
void AddNode(node* head, int n, int data);	//head를 index 0이라 할때 n번째 와 n+1 사이에 노드 추가

void DeleteFirst(node* head);				//맨 앞쪽 node 제거
void DeleteLast(node* head);				//맨 뒤쪽 node 제거
void DeleteNode(node* head, int n);			//head를 index 0이라 할때 n번째 노드 제거

int GetData(node* head, int n);				//head를 index 0이라 할때 n번째 data 얻는 함수 최대 리스트 개수보다 넘어가면 마지막 data 출력

void ShowList(node* head);					//연결리스트 전체 출력

void FreeList(node* head);					//연결리스트 전체 할당해제

//int main()
//{
//	node* head = new node;
//	head->nextnode = nullptr;
//	AddFirst(head, 10);
//	AddFirst(head, 20);
//	AddFirst(head, 30);
//	AddLast(head, 15);
//	AddLast(head, 25);
//	AddNode(head, 2, 11);
//	AddNode(head, 7, 12);
//	AddNode(head, 6, 13);
//	DeleteNode(head, 8);
//	cout << GetData(head, 5) << endl;
//	DeleteLast(head);
//
//	ShowList(head);
//
//	FreeList(head);
//
//	return 0;
//}

void ShowList(node* head)
{
	node* curr = head->nextnode;
	while (curr != NULL)
	{
		cout << curr->data << " ";
		curr = curr->nextnode;
	}
}

void FreeList(node* head)
{
	node* curr = head->nextnode;
	while (curr != NULL)
	{
		node* next = curr->nextnode;
		delete curr;
		curr = next;
	}
	delete head;
}

void AddFirst(node* head, int data) 
{
	node* newnode = new node;
	newnode->nextnode = head->nextnode;
	newnode->data = data;

	head->nextnode = newnode;
}

void AddLast(node* head, int data) 
{
	node* temp = head->nextnode;
	while (temp->nextnode != NULL)
	{
		temp = temp->nextnode;
	}
	node* newnode = new node;
	temp->nextnode = newnode;
	newnode->nextnode = NULL;
	newnode->data = data;
}

void AddNode(node* head, int n, int data)
{
	node* temp = head->nextnode;
	for (int i = 0; i < n - 1; i++)
	{
		if (temp->nextnode != NULL)
		{
			temp = temp->nextnode;
		}
	}
	node* newnode = new node;
	newnode->nextnode = temp->nextnode;
	temp->nextnode = newnode;
	newnode->data = data;
}

void DeleteFirst(node* head) 
{
	node* del = head->nextnode;
	head->nextnode = del->nextnode;
	delete del;
}

void DeleteLast(node* head)
{
	node* temp1 = head->nextnode;
	node* temp2 = temp1;
	while (temp1->nextnode != NULL)
	{
		temp2 = temp1;
		temp1 = temp1->nextnode;
	}
	delete temp1;
	temp2->nextnode = NULL;
}

void DeleteNode(node* head, int n)
{
	node* temp1 = head->nextnode;
	node* temp2 = temp1;
	for (int i = 0; i < n - 1; i++)
	{
		if (temp1->nextnode != NULL)
		{
			temp2 = temp1;
			temp1 = temp1->nextnode;
		}
	}
	temp2->nextnode = temp1->nextnode;
	delete temp1;
}

int GetData(node* head, int n)  
{
	node* temp = head->nextnode;
	for (int i = 0; i < n - 1; i++)
	{
		if (temp->nextnode != NULL)
		{
			temp = temp->nextnode;
		}
	}
	return temp->data;
}
