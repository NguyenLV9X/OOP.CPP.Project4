#pragma once
#include"Node.h"
#include"Book.h"

class CListBook
{
private:
	CNode<CBook> *pHead;
public:
	void Append(CBook data);
	bool findcodebook(string value);
	bool empty();
	int size();
	CNode<CBook> *getpHead();
	CNode<CBook> &operator[](int index);
	CBook &operator[](string index);
	CListBook();
};

