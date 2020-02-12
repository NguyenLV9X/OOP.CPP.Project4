#pragma once
#include"LinkListBook.h"
#include"LinkListCard.h"
#include"Algorithm.h"
#include"File.h"

class CLibrary : private CAlgorithm , private CFile
{
private:
	CListBook cl_mBook;
	CListCard cl_mCard;
public:
	void createbook();
	void showallbook(int option);
	void createcard();
	void updatecard();
	void showcard(int option);
	void searchbook(int option);
	void searchcard(int option);
	CLibrary();
	~CLibrary();
};





