#ifndef MYQUEUE_H
#define MYQUEUE_H
#include "Customer.h"
/*
	环形队列C++实现
*/
class MyQueue{
public:
	MyQueue(int queueCapacity);		//构造函数
	virtual ~MyQueue();
	void ClearQueue();
	bool QueueEmpty() const;
	bool QueueFull() const;
	int QueueLength() const;
	bool EnQueue(Customer element);
	bool DeQueue(Customer &element);
	void QueueTraverse();
private:
	Customer *m_pQueue;
	int m_iQueueLen;
	int m_iQueueCapacity;
	int m_iHead;
	int m_iTail;
};
#endif
