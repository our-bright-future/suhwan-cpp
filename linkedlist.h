#pragma once
//#ifndef __LIST_H__
//# define __LIST_H__
#include <iostream>

using namespace std;

typedef struct node
{
	node* nextnode;
	int data;
};

void AddFirst(node* head, int data);		//�Ǿ��� �ٷ� ������ node �߰�
void AddLast(node* head, int data);			//�� �ڿ� node �߰�
void AddNode(node* head, int n, int data);	//head�� index 0�̶� �Ҷ� n��° �� n+1 ���̿� ��� �߰�

void DeleteFirst(node* head);				//�� ���� node ����
void DeleteLast(node* head);				//�� ���� node ����
void DeleteNode(node* head, int n);			//head�� index 0�̶� �Ҷ� n��° ��� ����

int GetData(node* head, int n);				//head�� index 0�̶� �Ҷ� n��° data ��� �Լ� �ִ� ����Ʈ �������� �Ѿ�� ������ data ���

void ShowList(node* head);					//���Ḯ��Ʈ ��ü ���

void FreeList(node* head);					//���Ḯ��Ʈ ��ü �Ҵ�����
