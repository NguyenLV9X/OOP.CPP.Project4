#include "Algorithm.h"

int CAlgorithm::strcmpstr(string value1, string value2)
{
	for (int i = 0 ; value1[i] !='\0' && value2[i] != '\0'; ++i)
	{
		if (value1[i] < value2[i])
			return -1;

		if (value1[i] > value2[i])
			return 1;

		if (value1[i] == '\0')
			if (value2[i] != '\0')
				return -1;

		if (value1[i] != '\0')
			if (value2[i] == '\0')
				return 1;
	}
	return 0;
}

bool CAlgorithm::strcmpdate(string value1, string value2)
{
	string tDatestart1 = value1;
	string tDatestart2 = value2;
	int tyear1 = tDatestart1[6] * 1000 + tDatestart1[7] * 100 + tDatestart1[8] * 10 + tDatestart1[9];
	int tyear2 = tDatestart2[6] * 1000 + tDatestart2[7] * 100 + tDatestart2[8] * 10 + tDatestart2[9];
	if (tyear1 > tyear2)
	{
		return 1;
	}
	else if (tyear1 == tyear2)
	{
		int tmonth1 = tDatestart1[3] * 10 + tDatestart1[4];
		int tmonth2 = tDatestart2[3] * 10 + tDatestart2[4];
		if (tmonth1 > tmonth2)
		{
			return 1;
		}
		else if (tmonth1 == tmonth2)
		{
			int tDate1 = tDatestart1[0] * 10 + tDatestart1[1];
			int tDate2 = tDatestart2[0] * 10 + tDatestart2[1];
			if (tDate1 >= tDate2)
			{
				return 1;
			}
		}
	}
	return 0;
}

void CAlgorithm::sortTitle(CListBook & list)
{
	CNode<CBook> *pTemp1 = list.getpHead();
	for (; pTemp1->pNext() != NULL;pTemp1 = pTemp1->pNext())

	{
		CNode<CBook> *pTemp2 = pTemp1->pNext();
		for (; pTemp2 != NULL;pTemp2 = pTemp2->pNext())
		{
			string str1 = pTemp1->getData().getTitle();
			string str2 = pTemp2->getData().getTitle();
			if (strcmpstr(str1 , str2) > 0)
			{
				CBook temp1 = pTemp1->getData();
				CBook temp2 = pTemp2->getData();
				pTemp1->setData(temp2);
				pTemp2->setData(temp1);
			}
		}
	}
	
}

void CAlgorithm::sortPublisher(CListBook & list)
{
	CNode<CBook> *pTemp1 = list.getpHead();
	for (; pTemp1->pNext() != NULL; pTemp1 = pTemp1->pNext())

	{
		CNode<CBook> *pTemp2 = pTemp1->pNext();
		for (; pTemp2 != NULL; pTemp2 = pTemp2->pNext())
		{
			string str1 = pTemp1->getData().getPublisher();
			string str2 = pTemp2->getData().getPublisher();
			if (strcmpstr(str1, str2) > 0)
			{
				CBook temp1 = pTemp1->getData();
				CBook temp2 = pTemp2->getData();
				pTemp1->setData(temp2);
				pTemp2->setData(temp1);
			}
		}
	}
}

void CAlgorithm::sortAuthor(CListBook & list)
{
	CNode<CBook> *pTemp1 = list.getpHead();
	for (; pTemp1->pNext() != NULL; pTemp1 = pTemp1->pNext())

	{
		CNode<CBook> *pTemp2 = pTemp1->pNext();
		for (; pTemp2 != NULL; pTemp2 = pTemp2->pNext())
		{
			string str1 = pTemp1->getData().getAuthor();
			string str2 = pTemp2->getData().getAuthor();
			if (strcmpstr(str1, str2) > 0)
			{
				CBook temp1 = pTemp1->getData();
				CBook temp2 = pTemp2->getData();
				pTemp1->setData(temp2);
				pTemp2->setData(temp1);
			}
		}
	}
}

void CAlgorithm::sortDatestart(CListCard & list)
{
	CNode<CCallCard> *pTemp1 = list.getpHead();
	for (; pTemp1->pNext() != NULL; pTemp1 = pTemp1->pNext())

	{
		CNode<CCallCard> *pTemp2 = pTemp1->pNext();
		for (; pTemp2 != NULL; pTemp2 = pTemp2->pNext())
		{
			string str1 = pTemp1->getData().getDatestart();
			string str2 = pTemp2->getData().getDatestart();
			if (strcmpdate(str1, str2))
			{
				CCallCard temp1 = pTemp1->getData();
				CCallCard temp2 = pTemp2->getData();
				pTemp1->setData(temp2);
				pTemp2->setData(temp1);
			}
		}
	}
}

void CAlgorithm::sortDateend(CListCard & list)
{
	CNode<CCallCard> *pTemp1 = list.getpHead();
	for (; pTemp1->pNext() != NULL; pTemp1 = pTemp1->pNext())
	{
		CNode<CCallCard> *pTemp2 = pTemp1->pNext();
		for (; pTemp2 != NULL; pTemp2 = pTemp2->pNext())
		{
			string str1 = pTemp1->getData().getDateend();
			string str2 = pTemp2->getData().getDateend();
			if (str1 == "NULL")
				break;
			if (str2 == "NULL")
			{
				CCallCard temp1 = pTemp1->getData();
				CCallCard temp2 = pTemp2->getData();
				pTemp1->setData(temp2);
				pTemp2->setData(temp1);
				continue;
			}
			if (strcmpdate(str1, str2))
			{
				CCallCard temp1 = pTemp1->getData();	
				CCallCard temp2 = pTemp2->getData();
				pTemp1->setData(temp2);
				pTemp2->setData(temp1);
			}
		}
	}
}

void CAlgorithm::sortName(CListCard & list)
{
	CNode<CCallCard> *pTemp1 = list.getpHead();
	for (; pTemp1->pNext() != NULL; pTemp1 = pTemp1->pNext())
	{
		CNode<CCallCard> *pTemp2 = pTemp1->pNext();
		for (; pTemp2 != NULL; pTemp2 = pTemp2->pNext())
		{
			string str1 = pTemp1->getData().getName();
			string str2 = pTemp2->getData().getName();
			if (strcmpstr(str1, str2) > 0)
			{
				CCallCard temp1 = pTemp1->getData(); 
				CCallCard temp2 = pTemp2->getData();
				pTemp1->setData(temp2);
				pTemp2->setData(temp1);
			}
		}
	}
}

void CAlgorithm::sortSTcard(CListCard & list)
{
	CNode<CCallCard> *pTemp1 = list.getpHead();
	for (; pTemp1->pNext() != NULL; pTemp1 = pTemp1->pNext())
	{
		CNode<CCallCard> *pTemp2 = pTemp1->pNext();
		for (; pTemp2 != NULL; pTemp2 = pTemp2->pNext())
		{
			string str1 = pTemp1->getData().getSTcard();
			string str2 = pTemp2->getData().getSTcard();
			if (strcmpstr(str1, str2) > 0)
			{
				CCallCard temp1 = pTemp1->getData();
				CCallCard temp2 = pTemp2->getData();
				pTemp1->setData(temp2);
				pTemp2->setData(temp1);
			}
		}
	}
}

void CAlgorithm::searchbookCodehuman(CListBook listbook, CListCard listcard, string value)
{
	set<string> codebook;
	CNode<CCallCard> *pTemp1 = listcard.getpHead();
	for (; pTemp1 != NULL; pTemp1 = pTemp1->pNext())
	{
		if (pTemp1->getData().getCodehuman() == value)
		{
			codebook.insert(pTemp1->getData().getCodebook());
		}
	}
	if (codebook.empty())
	{
		cout << "============================================" << endl;
		cout << "Khong co dau sach nao !" << endl;
	}
	else
	{
		int iCount = 0;
		set<string>::iterator pTemp2 = codebook.begin();
		while (pTemp2 != codebook.end())
		{
			cout << "============================================" << endl;
			cout << "THONG TIN DAU SACH " << iCount + 1 << endl;
			searchCodebook(listbook, *pTemp2);
			++pTemp2;
			++iCount;
		}
	}
}

void CAlgorithm::searchbookName(CListBook listbook, CListCard listcard, string value)
{
	set<string> codebook;
	CNode<CCallCard> *pTemp1 = listcard.getpHead();
	for (; pTemp1 != NULL; pTemp1 = pTemp1->pNext())
	{
		if (pTemp1->getData().getName() == value)
		{
			codebook.insert(pTemp1->getData().getCodebook());
		}
	}
	if (codebook.empty())
	{
		cout << "============================================" << endl;
		cout << "Khong co dau sach nao !" << endl;
	}
	else
	{
		int iCount = 0;
		set<string>::iterator pTemp2 = codebook.begin();
		while (pTemp2 != codebook.end())
		{
			cout << "============================================" << endl;
			cout << "THONG TIN DAU SACH " << iCount + 1 << endl;
			searchCodebook(listbook, *pTemp2);
			++pTemp2;
			++iCount;
		}
	}
}

void CAlgorithm::searchbookDatestart(CListBook listbook, CListCard listcard, string value)
{
	set<string> codebook;
	CNode<CCallCard> *pTemp1 = listcard.getpHead();
	for (; pTemp1 != NULL; pTemp1 = pTemp1->pNext())
	{
		if (pTemp1->getData().getDatestart() == value)
		{
			codebook.insert(pTemp1->getData().getCodebook());
		}
	}
	if (codebook.empty())
	{
		cout << "============================================" << endl;
		cout << "Khong co dau sach nao !" << endl;
	}
	else
	{
		int iCount = 0;
		set<string>::iterator pTemp2 = codebook.begin();
		while (pTemp2 != codebook.end())
		{
			cout << "============================================" << endl;
			cout << "THONG TIN DAU SACH " << iCount + 1 << endl;
			searchCodebook(listbook, *pTemp2);
			++pTemp2;
			++iCount;
		}
	}
}

void CAlgorithm::searchbookDateend(CListBook listbook, CListCard listcard, string value)
{
	set<string> codebook;
	CNode<CCallCard> *pTemp1 = listcard.getpHead();
	for (; pTemp1 != NULL; pTemp1 = pTemp1->pNext())
	{
		if (pTemp1->getData().getDateend() == value)
		{
			codebook.insert(pTemp1->getData().getCodebook());
		}
	}
	if (codebook.empty())
	{
		cout << "============================================" << endl;
		cout << "Khong co dau sach nao !" << endl;
	}
	else
	{
		int iCount = 0;
		set<string>::iterator pTemp2 = codebook.begin();
		while (pTemp2 != codebook.end())
		{
			cout << "============================================" << endl;
			cout << "THONG TIN DAU SACH " << iCount + 1 << endl;
			searchCodebook(listbook, *pTemp2);
			++pTemp2;
			++iCount;
		}
	}
}

void CAlgorithm::searchbookSTbook(CListBook listbook, CListCard listcard, string value)
{
	set<string> codebook;
	CNode<CCallCard> *pTemp1 = listcard.getpHead();
	for (; pTemp1 != NULL; pTemp1 = pTemp1->pNext())
	{
		if (pTemp1->getData().getSTcard() == "Muon")
		{
			if (pTemp1->getData().getSTbookS() == value)
				codebook.insert(pTemp1->getData().getCodebook());
		}
		else
		{
			if (pTemp1->getData().getSTbookE() == value)
				codebook.insert(pTemp1->getData().getCodebook());
		}	
	}
	if (codebook.empty())
	{
		cout << "============================================" << endl;
		cout << "Khong co dau sach nao !" << endl;
	}
	else
	{
		int iCount = 0;
		set<string>::iterator pTemp2 = codebook.begin();
		while (pTemp2 != codebook.end())
		{
			cout << "============================================" << endl;
			cout << "THONG TIN DAU SACH " << iCount + 1 << endl;
			searchCodebook(listbook, *pTemp2);
			++pTemp2;
			++iCount;
		}
	}
}

void CAlgorithm::searchcardCodebook(CListBook listbook, CListCard listcard, string value)
{
	set<string> codecard;
	CNode<CCallCard> *pTemp1 = listcard.getpHead();
	for (; pTemp1 != NULL; pTemp1 = pTemp1->pNext())
	{
		if (pTemp1->getData().getCodebook() == value)
		{
			codecard.insert(pTemp1->getData().getCodecard());
		}
	}
	if (codecard.empty())
	{
		cout << "============================================" << endl;
		cout << "Khong co phieu muon nao !" << endl;
	}
	else
	{
		int iCount = 0;
		set<string>::iterator pTemp2 = codecard.begin();
		while (pTemp2 != codecard.end())
		{
			cout << "============================================" << endl;
			cout << "THONG TIN PHIEU MUON " << iCount + 1 << endl;
			searchCodecard(listcard, *pTemp2);
			++pTemp2;
			++iCount;
		}
	}
}

void CAlgorithm::searchcardTitlebook(CListBook listbook, CListCard listcard, string value)
{
	set<string> codebook;
	CNode<CBook> *pTemp1 = listbook.getpHead();
	for (; pTemp1 != NULL; pTemp1 = pTemp1->pNext())
	{
		if (pTemp1->getData().getTitle() == value)
		{
			codebook.insert(pTemp1->getData().getCode());
		}
	}
	if (codebook.empty())
	{
		cout << "============================================" << endl;
		cout << "Khong co phieu muon nao !" << endl;
	}
	else
	{
		int iCount = 0;
		set<string>::iterator pTemp2 = codebook.begin();
		while (pTemp2 != codebook.end())
		{
			searchcardCodebook(listcard, *pTemp2, iCount);
			++pTemp2;
		}
	}
}

void CAlgorithm::searchcardYearbook(CListBook listbook, CListCard listcard, int value)
{
	set<string> codebook;
	CNode<CBook> *pTemp1 = listbook.getpHead();
	for (; pTemp1 != NULL; pTemp1 = pTemp1->pNext())
	{
		if (pTemp1->getData().getYear() == value)
		{
			codebook.insert(pTemp1->getData().getCode());
		}
	}
	if (codebook.empty())
	{
		cout << "============================================" << endl;
		cout << "Khong co phieu muon nao !" << endl;
	}
	else
	{
		int iCount = 0;
		set<string>::iterator pTemp2 = codebook.begin();
		while (pTemp2 != codebook.end())
		{
			searchcardCodebook(listcard, *pTemp2, iCount);
			++pTemp2;
		}
	}
}

void CAlgorithm::searchcardAuthorbook(CListBook listbook, CListCard listcard, string value)
{
	set<string> codebook;
	CNode<CBook> *pTemp1 = listbook.getpHead();
	for (; pTemp1 != NULL; pTemp1 = pTemp1->pNext())
	{
		if (pTemp1->getData().getAuthor() == value)
		{
			codebook.insert(pTemp1->getData().getCode());
		}
	}
	if (codebook.empty())
	{
		cout << "============================================" << endl;
		cout << "Khong co phieu muon nao !" << endl;
	}
	else
	{
		int iCount = 0;
		set<string>::iterator pTemp2 = codebook.begin();
		while (pTemp2 != codebook.end())
		{
			searchcardCodebook(listcard, *pTemp2, iCount);
			++pTemp2;
		}
	}
}

void CAlgorithm::searchcardKindbook(CListBook listbook, CListCard listcard, string value)
{
	set<string> codebook;
	CNode<CBook> *pTemp1 = listbook.getpHead();
	for (; pTemp1 != NULL; pTemp1 = pTemp1->pNext())
	{
		if (pTemp1->getData().getKind() == value)
		{
			codebook.insert(pTemp1->getData().getCode());
		}
	}
	if (codebook.empty())
	{
		cout << "============================================" << endl;
		cout << "Khong co phieu muon nao !" << endl;
	}
	else
	{
		int iCount = 0;
		set<string>::iterator pTemp2 = codebook.begin();
		while (pTemp2 != codebook.end())
		{
			searchcardCodebook(listcard, *pTemp2 ,iCount);
			++pTemp2;
		}
	}
}

void CAlgorithm::searchCodebook(CListBook list,string value)
{
	CNode<CBook> *pTemp = list.getpHead();
	int iCount = 0;
	for (; pTemp != NULL; pTemp = pTemp->pNext())
	{
		if (pTemp->getData().getCode() == value)
		{
			pTemp->getData().exportbook();
			break; 
		}
	}
	if (iCount == 0)
	{
		cout << "Ma sach khong ton tai !" << endl;
	}
}

void CAlgorithm::searchCodecard(CListCard list, string value)
{
	CNode<CCallCard> *pTemp = list.getpHead();
	int iCount = 0;
	for (; pTemp != NULL; pTemp = pTemp->pNext())
	{
		if (pTemp->getData().getCodecard() == value)
		{
			pTemp->getData().exportcard();
			break;
		}
	}
	if (iCount == 0)
	{
		cout << "Ma sach khong ton tai !" << endl;
	}
}

void CAlgorithm::searchcardCodebook(CListCard list, string value , int &iCount)
{
	CNode<CCallCard> *pTemp = list.getpHead();
	for (; pTemp != NULL; pTemp = pTemp->pNext())
	{
		if (pTemp->getData().getCodebook() == value)
		{
			cout << "============================================" << endl;
			cout << "THONG TIN PHIEU MUON " << iCount + 1 << endl;
			pTemp->getData().exportcard();
			++iCount;
		}
	}
}

void CAlgorithm::searchTitlebook(CListBook list, string value)
{
	CNode<CBook> *pTemp = list.getpHead();
	int iCount = 0;
	for (; pTemp != NULL; pTemp = pTemp->pNext())
	{
		if (pTemp->getData().getTitle() == value)
		{
			cout << "============================================" << endl;
			cout << "THONG TIN DAU SACH " << iCount + 1 << endl;
			pTemp->getData().exportbook();
			++iCount;
		}
	}
	if (iCount == 0)
	{
		cout << "============================================" << endl;
		cout << "Khong co dau sach nao !" << endl;
	}
	cout << "============================================";
	cout << endl;
	cout << endl;
	cout << "Hay an phim enter de quay lai menu chinh" << endl;
	system("pause");
}

void CAlgorithm::searchYearbook(CListBook list, int value)
{
	CNode<CBook> *pTemp = list.getpHead();
	int iCount = 0;
	for (; pTemp != NULL; pTemp = pTemp->pNext())
	{
		if (pTemp->getData().getYear() == value)
		{
			cout << "============================================" << endl;
			cout << "THONG TIN DAU SACH " << iCount + 1 << endl;
			pTemp->getData().exportbook();
			++iCount;
		}
	}
	if (iCount == 0)
	{
		cout << "============================================" << endl;
		cout << "Khong co dau sach nao !" << endl;
	}
	cout << "============================================";
	cout << endl;
	cout << endl;
	cout << "Hay an phim enter de quay lai menu chinh" << endl;
	system("pause");
}

void CAlgorithm::searchPublisherbook(CListBook list, string value)
{
	CNode<CBook> *pTemp = list.getpHead();
	int iCount = 0;
	for (; pTemp != NULL; pTemp = pTemp->pNext())
	{
		if (pTemp->getData().getPublisher() == value)
		{
			cout << "============================================" << endl;
			cout << "THONG TIN DAU SACH " << iCount + 1 << endl;
			pTemp->getData().exportbook();
			++iCount;
		}
	}
	if (iCount == 0)
	{
		cout << "============================================" << endl;
		cout << "Khong co dau sach nao !" << endl;
	}
	cout << "============================================";
	cout << endl;
	cout << endl;
	cout << "Hay an phim enter de quay lai menu chinh" << endl;
	system("pause");
}

void CAlgorithm::searchAuthorbook(CListBook list, string value)
{
	CNode<CBook> *pTemp = list.getpHead();
	int iCount = 0;
	for (; pTemp != NULL; pTemp = pTemp->pNext())
	{
		if (pTemp->getData().getAuthor() == value)
		{
			cout << "============================================" << endl;
			cout << "THONG TIN DAU SACH " << iCount + 1 << endl;
			pTemp->getData().exportbook();
			++iCount;
		}
	}
	if (iCount == 0)
	{
		cout << "============================================" << endl;
		cout << "Khong co dau sach nao !" << endl;
	}
	cout << "============================================";
	cout << endl;
	cout << endl;
	cout << "Hay an phim enter de quay lai menu chinh" << endl;
	system("pause");
}

void CAlgorithm::searchKindbook(CListBook list, string value)
{
	CNode<CBook> *pTemp = list.getpHead();
	int iCount = 0;
	for (; pTemp != NULL; pTemp = pTemp->pNext())
	{
		if (pTemp->getData().getKind() == value)
		{
			cout << "============================================" << endl;
			cout << "THONG TIN DAU SACH " << iCount + 1 << endl;
			pTemp->getData().exportbook();
			++iCount;
		}
	}
	if (iCount == 0)
	{
		cout << "============================================" << endl;
		cout << "Khong co dau sach nao !" << endl;
	}
	cout << "============================================";
	cout << endl;
	cout << endl;
	cout << "Hay an phim enter de quay lai menu chinh" << endl;
	system("pause");
}

void CAlgorithm::searchCodehumancard(CListCard list, string value)
{
	CNode<CCallCard> *pTemp = list.getpHead();
	int iCount = 0;
	for (; pTemp != NULL; pTemp = pTemp->pNext())
	{
		if (pTemp->getData().getCodehuman() == value)
		{
			cout << "============================================" << endl;
			cout << "THONG TIN PHIEU MUON " << iCount + 1 << endl;
			pTemp->getData().exportcard();
			++iCount;
		}
	}
	if (iCount == 0)
	{
		cout << "============================================" << endl;
		cout << "Khong co phieu muon nao !" << endl;
	}
	cout << "============================================";
	cout << endl;
	cout << endl;
	cout << "Hay an phim enter de quay lai menu chinh" << endl;
	system("pause");
}

void CAlgorithm::searchNamecard(CListCard list, string value)
{
	CNode<CCallCard> *pTemp = list.getpHead();
	int iCount = 0;
	for (; pTemp != NULL; pTemp = pTemp->pNext())
	{
		if (pTemp->getData().getName() == value)
		{
			cout << "============================================" << endl;
			cout << "THONG TIN PHIEU MUON " << iCount + 1 << endl;
			pTemp->getData().exportcard();
			++iCount;
		}
	}
	if (iCount == 0)
	{
		cout << "============================================" << endl;
		cout << "Khong co phieu muon nao !" << endl;
	}
	cout << "============================================";
	cout << endl;
	cout << endl;
	cout << "Hay an phim enter de quay lai menu chinh" << endl;
	system("pause");
}

void CAlgorithm::searchSTbookScard(CListCard list, string value)
{
	CNode<CCallCard> *pTemp = list.getpHead();
	int iCount = 0;
	for (; pTemp != NULL; pTemp = pTemp->pNext())
	{
		if (pTemp->getData().getSTbookS() == value)
		{
			cout << "============================================" << endl;
			cout << "THONG TIN PHIEU MUON " << iCount + 1 << endl;
			pTemp->getData().exportcard();
			++iCount;
		}
	}
	if (iCount == 0)
	{
		cout << "============================================" << endl;
		cout << "Khong co phieu muon nao !" << endl;
	}
	cout << "============================================";
	cout << endl;
	cout << endl;
	cout << "Hay an phim enter de quay lai menu chinh" << endl;
	system("pause");
}

void CAlgorithm::searchSTbookEcard(CListCard list, string value)
{
	CNode<CCallCard> *pTemp = list.getpHead();
	int iCount = 0;
	for (; pTemp != NULL; pTemp = pTemp->pNext())
	{
		if (pTemp->getData().getSTbookE() == value)
		{
			cout << "============================================" << endl;
			cout << "THONG TIN PHIEU MUON " << iCount + 1 << endl;
			pTemp->getData().exportcard();
			++iCount;
		}
	}
	if (iCount == 0)
	{
		cout << "============================================" << endl;
		cout << "Khong co phieu muon nao !" << endl;
	}
	cout << "============================================";
	cout << endl;
	cout << endl;
	cout << "Hay an phim enter de quay lai menu chinh" << endl;
	system("pause");
}

void CAlgorithm::searchDatestartcard(CListCard list, string value)
{
	CNode<CCallCard> *pTemp = list.getpHead();
	int iCount = 0;
	for (; pTemp != NULL; pTemp = pTemp->pNext())
	{
		if (pTemp->getData().getDatestart() == value)
		{
			cout << "============================================" << endl;
			cout << "THONG TIN PHIEU MUON " << iCount + 1 << endl;
			pTemp->getData().exportcard();
			++iCount;
		}
	}
	if (iCount == 0)
	{
		cout << "============================================" << endl;
		cout << "Khong co phieu muon nao !" << endl;
	}
	cout << "============================================";
	cout << endl;
	cout << endl;
	cout << "Hay an phim enter de quay lai menu chinh" << endl;
	system("pause");
}

void CAlgorithm::searchDateendcard(CListCard list, string value)
{
	CNode<CCallCard> *pTemp = list.getpHead();
	int iCount = 0;
	for (; pTemp != NULL; pTemp = pTemp->pNext())
	{
		if (pTemp->getData().getDateend() == value)
		{
			cout << "============================================" << endl;
			cout << "THONG TIN PHIEU MUON " << iCount + 1 << endl;
			pTemp->getData().exportcard();
			++iCount;
		}
	}
	if (iCount == 0)
	{
		cout << "============================================" << endl;
		cout << "Khong co phieu muon nao !" << endl;
	}
	cout << "============================================";
	cout << endl;
	cout << endl;
	cout << "Hay an phim enter de quay lai menu chinh" << endl;
	system("pause");
}



