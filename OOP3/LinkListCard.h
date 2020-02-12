#pragma once
#include"Node.h"
#include"CallCard.h"

class CListCard
{
private:
	CNode<CCallCard> *pHead;
public:
	void Append(CCallCard Card);
	int size();
	bool empty();
	bool findcodecard(string value);
	CNode<CCallCard> *getpHead();
	CNode<CCallCard> &operator[](int index);
	CCallCard &operator[](string index);
	CListCard();
};