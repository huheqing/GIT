#include"List.h"
#include<iostream>
#include"Node.h"
using namespace std;

List::List(){
	
	m_pList = new Node();//Í·½áµã
	m_pList->data = 0;
	m_pList->next = NULL;
	m_iLength = 0;
	
}

List::~List(){
	ClearList();
	delete m_pList;
	m_pList = NULL;
}

void List::ClearList(){
	Node *tempNode = m_pList->next;
	while (tempNode != NULL){
		Node *ClearNode = tempNode->next;
		delete tempNode;
		tempNode = NULL;
		tempNode = ClearNode;
	}
	m_pList->next = NULL;//key
	m_iLength = 0;//add personal
	return;
}

bool List::ListEmpty(){
	if (0 == m_iLength)
		return true;
	return false;
}

int List::ListLength(){
	return m_iLength;
}

bool List::GetElem(int i, Node *pNode){
	if (ListEmpty() || i < 0 || i >= m_iLength)
		return false;
	Node *tempNode = m_pList;
	for (int j = 0; j <= i;j++)
		tempNode = tempNode->next;
	pNode->data = tempNode->data;
	return true;
}

int List::LocateElem(Node *pNode){
	Node *tempNode = m_pList->next;
	for (int i = 0; i < m_iLength; i++){
		if (tempNode->data== pNode->data){
		
			return i;
		}
		tempNode = tempNode->next;
	}
	return -1;
}

bool List::PriorElem(Node *pCurrentNode, Node *pPreNode){
	int index = LocateElem(pCurrentNode);
	if (-1 == index || 0 == index)
		return false;
	if (GetElem(index - 1, pPreNode))
		return true;
	return false;
}

bool List::NextElem(Node *pCurrentNode, Node *pNextNode){
	int index = LocateElem(pCurrentNode);
	if (-1 == index || (m_iLength-1)== index)
		return false;
	if (GetElem(index + 1, pNextNode))
		return true;
	return false;
}
bool List::ListInsert(int i, Node *pNode){
	if (i<0 || i>m_iLength)
		return false;
	Node*tempNode = m_pList;
	for (int k = 0; k < i; k++)
		tempNode = tempNode->next;
	Node *newNode = new Node();
	if (newNode == NULL)
		return false;
	newNode->data = pNode->data;
	newNode->next = tempNode->next;
	tempNode->next = newNode;
	m_iLength++;
	return true;
}
bool List::ListDelete(int i, Node *pNode){
	if (i<0 || i>=m_iLength)
		return false;
	if (ListEmpty())
		return false;
	Node*tempNode = m_pList;
	for (int k = 0; k < i; k++)
		tempNode = tempNode->next;

	Node*DelteNode = tempNode->next;
	pNode->data = DelteNode->data;
	tempNode->next = DelteNode->next;
	delete DelteNode;
	m_iLength--;
	return true;
}
void List::ListTraverse(){
	Node*tempNode = m_pList->next;
	for (int i = 0; i < m_iLength; i++){
		tempNode->printNode();
		tempNode = tempNode->next;
	}		
}

bool List::ListInsertHead(Node *pNode){
	Node*tempNode = m_pList->next;
	Node *newNode = new Node();
	if (newNode == NULL)
		return false;
	newNode->data = pNode->data;
	m_pList->next = newNode;
	newNode->next = tempNode;
	m_iLength++;
	return true;
	
}
bool List::ListInsertTail(Node *pNode){
	Node*tempNode = m_pList;
	while (tempNode->next != NULL)
		tempNode = tempNode->next;
	Node *newNode = new Node();
	if (newNode == NULL)
		return false;
	newNode->data = pNode->data;
	newNode->next = NULL;
	tempNode->next = newNode;
	m_iLength++;
	return true;
}