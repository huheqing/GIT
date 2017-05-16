#ifndef MYSTACK_H
#define MYSTACK_H

template <typename T>
class MyStack
{
public:
	MyStack(){}
	MyStack(int size);		//分配栈空间
	~MyStack();
	bool stackEmpty();
	bool stackFull();
	void clearStack();
	int stackLength();
	bool push(T elem);
	bool pop(T &elem);
	void stackTraverse();
private:
	T *m_pBuffer;	//栈空间指针
	int m_iSize;		//栈容量
	int m_iTop;			//栈顶，栈中元素个数

};

template<typename T>
MyStack<T>::MyStack(int size){
	m_iSize = size;
	m_iTop = 0;
	m_pBuffer = new T[size];
}

template<typename T>
MyStack<T>::~MyStack(){
	delete[] m_pBuffer;
	m_pBuffer = nullptr;
}

template<typename T>
bool MyStack<T>::stackEmpty(){
	if (0 == m_iTop)
		return true;
	return false;
}

template<typename T>
bool MyStack<T>::stackFull(){
	if (m_iTop == m_iSize)
		return true;
	return false;
}

template<typename T>
void MyStack<T>::clearStack(){
	m_iTop = 0;
}

template<typename T>
int MyStack<T>::stackLength(){
	return m_iTop;
}

template<typename T>
bool MyStack<T>::push(T elem){
	if (stackFull())
		return false;
	m_pBuffer[m_iTop++] = elem;
	return true;
}

template<typename T>
bool MyStack<T>::pop(T &elem){
	if (stackEmpty())
		return false;
	m_iTop--;
	elem = m_pBuffer[m_iTop];
	return true;
}

template<typename T>
void MyStack<T>::stackTraverse(){

	for (int i = 0; i < m_iTop; i++)
		cout << m_pBuffer[i];

}
#endif