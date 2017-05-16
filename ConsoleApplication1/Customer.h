#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<string>
using namespace std;
class Customer
{
public:
	Customer(){}
	Customer(string name,int age);
	void printInfo()const;

private:
	string m_strName;
	int m_iAge;

};

#endif