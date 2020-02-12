#pragma once
#include<fstream>
#include"LinkListBook.h"
#include"LinkListCard.h"
class CFile
{
protected:
	void writeFilebook(CListBook list);
	void writeFilecard(CListCard list);
	void readFilebook(CListBook &list);
	void readFilecard(CListCard &list);
};

