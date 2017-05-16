#include<iostream>
#include "MyQueue.h"
#include "Customer.h"
using namespace std;

int main(){
	MyQueue *p = new MyQueue(4);
	Customer c1("zhangsan", 20);
	Customer c2("lisi", 30);
	Customer c3("xiaohong", 40);

	p->EnQueue(c1);
	p->EnQueue(c2);
	p->EnQueue(c3);
	p->QueueTraverse();

	Customer c4("", 0);
	p->DeQueue(c4);
	c4.printInfo();

	p->QueueTraverse();

	delete p;
	p = NULL;
	return 0;
}