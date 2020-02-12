#include"LinkListBook.h"

CNode<CBook>* CListBook::getpHead()
{
	return pHead;
}

void CListBook::Append(CBook data)
{
	CNode<CBook> *newNode = new CNode<CBook>(data, NULL);
	CNode<CBook> *pTemp = pHead;
	if (pTemp == NULL)
		pHead = newNode;
	else
	{
		while (pTemp->pNext() != NULL)
		{
			pTemp = pTemp->pNext();
		}
		pTemp->setNext(newNode);
	}
}

bool CListBook::findcodebook(string value)
{
	CNode<CBook> *pTemp = pHead;
	for (; pTemp != NULL; pTemp = pTemp->pNext())
	{
		if (pTemp->getData().getCode() == value)
		{
			return 1;
		}
	}
	return 0;
}

bool CListBook::empty()
{
	if (pHead == NULL)
	{
		return 1;
	}

	return 0;
}

int CListBook::size()
{
	if(pHead==NULL)
		return 0;

	CNode<CBook> *pTemp = pHead;
	int iCount = 0;
	for (; pTemp != NULL; pTemp = pTemp->pNext())
	{
		++iCount;
	}

	return iCount;
}


CNode<CBook>& CListBook::operator[](int index)
{

	CNode<CBook> *pTemp = pHead;
	int iCount = 0;
	for (; pTemp != NULL; pTemp = pTemp->pNext())
	{
		if (iCount == index)
			return *pTemp;
		++iCount;
	}
}

CBook& CListBook::operator[](string index)
{
	CNode<CBook> *pTemp = pHead;
	int iCount = 0;
	for (; pTemp != NULL; pTemp = pTemp->pNext())
	{
		if (pTemp->getData().getCode() == index)
			return pTemp->getaddressData();
		++iCount;
	}
}

CListBook::CListBook()
{
	pHead = NULL;
}
