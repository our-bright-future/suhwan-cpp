#include <iostream>

using namespace std;

typedef struct LinkedList
{
	node* nextnode;
	int data;
}node;

void AddFirst(node* head, int data);		//�Ǿ��� �ٷ� ������ node �߰�
void AddLast(node* head, int data);			//�� �ڿ� node �߰�
void AddNode(node* head, int n, int data);	//head�� index 0�̶� �Ҷ� n��° �� n+1 ���̿� ��� �߰�

void DeleteFirst(node* head);				//�� ���� node ����
void DeleteLast(node* head);				//�� ���� node ����
void DeleteNode(node* head, int n);			//head�� index 0�̶� �Ҷ� n��° ��� ����

int GetData(node* head, int n);				//head�� index 0�̶� �Ҷ� n��° data ��� �Լ� �ִ� ����Ʈ �������� �Ѿ�� ������ data ���

void ShowList(node* head);					//���Ḯ��Ʈ ��ü ���

void FreeList(node* head);					//���Ḯ��Ʈ ��ü �Ҵ�����

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