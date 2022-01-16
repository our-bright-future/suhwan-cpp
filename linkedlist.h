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

void AddFirst(node* head, int data);		//맨앞쪽 바로 다음에 node 추가
void AddLast(node* head, int data);			//맨 뒤에 node 추가
void AddNode(node* head, int n, int data);	//head를 index 0이라 할때 n번째 와 n+1 사이에 노드 추가

void DeleteFirst(node* head);				//맨 앞쪽 node 제거
void DeleteLast(node* head);				//맨 뒤쪽 node 제거
void DeleteNode(node* head, int n);			//head를 index 0이라 할때 n번째 노드 제거

int GetData(node* head, int n);				//head를 index 0이라 할때 n번째 data 얻는 함수 최대 리스트 개수보다 넘어가면 마지막 data 출력

void ShowList(node* head);					//연결리스트 전체 출력

void FreeList(node* head);					//연결리스트 전체 할당해제
