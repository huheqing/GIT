#include<iostream>
#include "Customer.h"
using namespace std;
Customer::Customer(string name, int age) :m_strName(name), m_iAge(age){

}
void Customer::printInfo() const{
	cout << "������" << m_strName << endl;
	cout << "���䣺" << m_iAge << endl;
	cout << endl;
}