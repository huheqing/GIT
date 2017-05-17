#ifndef LIST_H
#define LIST_H

class List{
public:
	List(){}
	List(int size);
	~List();
	void ClearList();
	bool ListEmpty();
	int ListLength();
	bool GetElem(int i, int &e);
	int LocateElem(int &e);
	bool PriorElem(int &currentElem, int &preElem);
	bool NextElem(int &currentElem, int &nextElem);
	bool ListInsert(int i, int &e);
	bool ListDelete(int i, int &e);
	void ListTraverse();
private:
	int *m_pList;
	int m_iSize;
	int m_iLength;	//Á´±í³¤¶È
};
#endif