#include"List.h"
#include<iostream>
using namespace std;

List::List(int size){
	m_iSize = size;
	m_pList = new int[m_iSize];
	m_iLength = 0;
}

List::~List(){
	delete[]m_pList;
	m_pList = NULL;
}

void List::ClearList(){
	m_iLength = 0;
}

bool List::ListEmpty(){
	if (0 == m_iLength)
		return true;
	return false;
}

int List::ListLength(){
	return m_iLength;
}

bool List::GetElem(int i, int &e){
	if (ListEmpty() || i < 0 || i >= m_iLength)
		return false;
	e = m_pList[i];
	return true;
}

int List::LocateElem(int &e){
	for (int i = 0; i < m_iLength; i++){
		if (m_pList[i] == e){
		
			return i;
		}
	}
	return -1;
}

bool List::PriorElem(int &currentElem, int &preElem){
	int index = LocateElem(currentElem);
	if (-1 == index || 0 == index)
		return false;
	preElem = m_pList[index - 1];
	return true;
}

bool List::NextElem(int &currentElem, int &nextElem){
	int index = LocateElem(currentElem);
	if (-1 == index || (m_iLength-1)== index)
		return false;
	nextElem = m_pList[index + 1];
	return true;
}
bool List::ListInsert(int i, int &e){
	if (i<0 || i>m_iLength)
		return false;
	if (m_iLength == m_iSize)//×Ô¼ºÌí¼Ó
		return false;
	m_iLength++;
	for (int j = m_iLength - 1; j > i; j--)
		m_pList[j] = m_pList[j - 1];
	m_pList[i] = e;
	return true;
}
bool List::ListDelete(int i, int &e){
	if (i<0 || i>m_iLength)
		return false;
	if (ListEmpty())
		return false;
	e = m_pList[i];
	for (int j = i; j < m_iLength-1; j++)
		m_pList[j] = m_pList[j + 1];
	m_iLength--;
	return true;
}
void List::ListTraverse(){
	for (int i = 0; i < m_iLength; i++)
		cout << m_pList[i] << " ";
}
