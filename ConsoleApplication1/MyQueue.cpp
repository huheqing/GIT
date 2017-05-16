#include "MyQueue.h"
#include<iostream>
#include "Customer.h"
using namespace std;

MyQueue::MyQueue(int queueCapacity){
	m_iQueueCapacity = queueCapacity;
	m_pQueue = new Customer[m_iQueueCapacity];//有可能申请失败
	ClearQueue();
}

MyQueue::~MyQueue(){
	delete[]m_pQueue;
	m_pQueue = nullptr;


}
void MyQueue::ClearQueue(){
	m_iHead = 0;
	m_iTail = 0;
	m_iQueueLen = 0;
}

bool MyQueue::QueueEmpty() const{
	return m_iQueueLen == 0 ? true : false;
}

int MyQueue::QueueLength() const{
	return m_iQueueLen;
}

bool MyQueue::QueueFull() const{
	if (m_iQueueLen == m_iQueueCapacity)
		return true;
	return false;
}
bool MyQueue::EnQueue(Customer element){
	if (QueueFull())
		return false;
	m_pQueue[m_iTail] = element;
	m_iTail++;
	m_iQueueLen++;
	m_iTail %= m_iQueueCapacity;
	return true;
}

bool MyQueue::DeQueue(Customer &element){
	if (QueueEmpty())
		return false;
	element = m_pQueue[m_iHead];
	m_iHead++;
	m_iQueueLen--;
	m_iHead %= m_iQueueCapacity;
	return true;
}

void MyQueue::QueueTraverse(){

	for (int i = m_iHead; i < m_iQueueLen + m_iHead; i++){
		m_pQueue[i%m_iQueueCapacity].printInfo();
		cout << "前面还有" << (i - m_iHead) << "人" << endl;
	}
	cout << endl;
}