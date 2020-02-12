#pragma once
#include"LinkListBook.h"
#include"LinkListCard.h"
#include<set>
class CAlgorithm
{
private:
	int strcmpstr(string value1, string value2);
	bool strcmpdate(string value1, string value2);
	void searchCodebook(CListBook list, string value);
	void searchCodecard(CListCard list, string value);
	void searchcardCodebook(CListCard list, string value, int &iCount);
	void searchTitlebook(CListBook list, string value);
	void searchYearbook(CListBook list, int value);
	void searchPublisherbook(CListBook list, string value);
	void searchAuthorbook(CListBook list, string value);
	void searchKindbook(CListBook list, string value);
	void searchCodehumancard(CListCard list, string value);
	void searchNamecard(CListCard list, string value);
	void searchSTbookScard(CListCard list, string value);
	void searchSTbookEcard(CListCard list, string value);
	void searchDatestartcard(CListCard list, string value);
	void searchDateendcard(CListCard list, string value);
protected:
	void sortTitle(CListBook &list);
	void sortPublisher(CListBook &list);
	void sortAuthor(CListBook &list);
	void sortDatestart(CListCard &list);
	void sortDateend(CListCard &list);
	void sortName(CListCard &list);
	void sortSTcard(CListCard &list);
	void searchbookCodehuman(CListBook listbook, CListCard listcard, string value);
	void searchbookName(CListBook listbook, CListCard listcard, string value);
	void searchbookDatestart(CListBook listbook, CListCard listcard, string value);
	void searchbookDateend(CListBook listbook, CListCard listcard, string value);
	void searchbookSTbook(CListBook listbook, CListCard listcard, string value);
	void searchcardCodebook(CListBook listbook, CListCard listcard, string value);
	void searchcardTitlebook(CListBook listbook, CListCard listcard, string value);
	void searchcardYearbook(CListBook listbook, CListCard listcard, int value);
	void searchcardAuthorbook(CListBook listbook, CListCard listcard, string value);
	void searchcardKindbook(CListBook listbook, CListCard listcard, string value);
};

