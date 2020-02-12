#include "LinkListCard.h"

CNode<CCallCard>* CListCard::getpHead()
{
	return pHead;
}

void CListCard::Append(CCallCard Card)
{
	CNode<CCallCard> *newNode = new CNode<CCallCard>(Card, NULL);
	CNode<CCallCard> *pTemp = pHead;

	if (pTemp == NULL)
	{
		pHead = newNode;
	}
	else
	{
		while (pTemp->pNext()!=NULL)
		{
			pTemp = pTemp->pNext();
		}
		pTemp->setNext(newNode);
	}
}

int CListCard::size()
{
	if (pHead == NULL)
		return 0;

	CNode<CCallCard> *pTemp = pHead;
	int iCount = 0;
	for (; pTemp != NULL; pTemp = pTemp->pNext())
	{
		++iCount;
	}

	return iCount;
}

bool CListCard::empty()
{
	if (pHead == NULL)
	{
		return 1;
	}

	return 0;
}

bool CListCard::findcodecard(string value)
{
	CNode<CCallCard> *pTemp = pHead;
	for (; pTemp != NULL; pTemp = pTemp->pNext())
	{
		if (pTemp->getData().getCodecard() == value)
		{
			return 1;
		}
	}
	return 0;
}

CNode<CCallCard>& CListCard::operator[](int index)
{
	CNode<CCallCard> *pTemp = pHead;
	int iCount = 0;
	for (; pTemp != NULL; pTemp = pTemp->pNext())
	{
		if (iCount == index)
			return *pTemp;
		++iCount;
	}
}

CCallCard& CListCard::operator[](string index)
{
	CNode<CCallCard> *pTemp = pHead;
	int iCount = 0;
	for (; pTemp != NULL; pTemp = pTemp->pNext())
	{
		if (pTemp->getData().getCodecard() == index)
			return pTemp->getaddressData();
		++iCount;
	}
}

CListCard::CListCard()
{
	pHead = NULL;
}
