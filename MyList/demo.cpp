#include"List.h"
#include<iostream>
using namespace std;
int main(){
	//3 5 7 2 9 1 8
	int gTemp[7] = { 3, 5 ,7 ,2, 9, 1 ,8 };
	int temp = 0;

	List *List1 = new List(10);
	List1->ListInsert(0, gTemp[0]);
	List1->ListInsert(1, gTemp[1]);
	List1->ListInsert(2, gTemp[2]);
	List1->ListInsert(3, gTemp[3]);
	List1->ListInsert(4, gTemp[4]);
	List1->ListInsert(5, gTemp[5]);
	List1->ListInsert(6, gTemp[6]);
	//int temp;
	//List1->ListDelete(0, temp);
	//cout << List1->ListLength() << endl;
	//if (!List1->ListEmpty())
	//	cout << "not empty" << endl;
	//List1->ClearList();
	//if (List1->ListEmpty())
	//	cout << "empty" << endl;
	//List1->ListTraverse();
	//cout << endl<<"#" << temp << endl;

	List1->ListTraverse();
	cout << endl;
	List1->GetElem(0, temp);
	cout << "temp:" << temp << endl;
	cout << List1->LocateElem(temp) << endl;
	if (List1->PriorElem(gTemp[1], temp))
		cout << temp << endl;

	if (List1->NextElem(gTemp[5], temp))
		cout << temp << endl;
	delete List1;
	return 0;
}