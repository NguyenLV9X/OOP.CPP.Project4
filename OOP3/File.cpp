#include "File.h"

void CFile::writeFilebook(CListBook list)
{
	ofstream os;
	os.open("BOOK.dat", ios::binary | ios::out | ios::trunc);
	if (!list.empty())
	{
		int nTemp = list.size();
		os << nTemp << endl;
		for (int i = 0; i < list.size(); ++i)
		{
			CBook Temp = list[i].getData();
			os << Temp.getAmount() << endl;
			os << Temp.getAuthor() << endl;
			os << Temp.getCode() << endl;
			os << Temp.getKind() << endl;
			os << Temp.getPublisher() << endl;
			os << Temp.getTitle() << endl;
			os << Temp.getYear() << endl;
		}
	}
	os.close();
}

void CFile::writeFilecard(CListCard list)
{
	ofstream os;
	os.open("CARD.dat", ios::binary | ios::out | ios::trunc);
	if (!list.empty())
	{
		int nTemp = list.size();
		os << nTemp << endl;
		for (int i = 0; i < list.size(); ++i)
		{
			CCallCard Temp = list[i].getData();
			os << Temp.getCodebook() << endl;
			os << Temp.getCodecard() << endl;
			os << Temp.getCodehuman() << endl;
			os << Temp.getDateend() << endl;
			os << Temp.getDatestart() << endl;
			os << Temp.getName() << endl;
			os << Temp.getSTbookE() << endl;
			os << Temp.getSTbookS() << endl;
			os << Temp.getSTcard() << endl;
		}
	}
	os.close();
}

void CFile::readFilebook(CListBook & list)
{
	ifstream is;
	int iCount = 0;
	int iSize;
	is.open("BOOK.dat", ios::binary | ios::in);
	if (!is.fail())
	{
		is >> iSize;
		while (!is.eof())
		{
			CBook Temp;
			int nTemp;
			string strTemp;
			is >> nTemp;
			Temp.setAmount(nTemp);
			is >> strTemp;
			Temp.setAuthor(strTemp);
			is >> strTemp;
			Temp.setCode(strTemp);
			is >> strTemp;
			Temp.setKind(strTemp);
			is >> strTemp;
			Temp.setPublisher(strTemp);
			is >> strTemp;
			Temp.setTitle(strTemp);
			is >> nTemp;
			Temp.setYear(nTemp);
			list.Append(Temp);
			++iCount;
			if (iSize == iCount)
			{
				break;
			}
		}
	}
	is.close();
}

void CFile::readFilecard(CListCard & list)
{
	ifstream is;
	int iCount = 0;
	int iSize;
	is.open("CARD.dat", ios::binary | ios::in);
	if (!is.fail())
	{
		is >> iSize;
		while (!is.eof())
		{
			CCallCard Temp;
			string strTemp;
			is >> strTemp;
			Temp.setCodebook(strTemp);
			is >> strTemp;
			Temp.setCodecard(strTemp);
			is >> strTemp;
			Temp.setCodehuman(strTemp);
			is >> strTemp;
			Temp.setDateendfile(strTemp);
			is >> strTemp;
			Temp.setDatestart(strTemp);
			is >> strTemp;
			Temp.setName(strTemp);
			is >> strTemp;
			Temp.setSTbookE(strTemp);
			is >> strTemp;
			Temp.setSTbookS(strTemp);
			is >> strTemp;
			Temp.setSTcard(strTemp);
			list.Append(Temp);
			++iCount;
			if (iSize == iCount)
			{
				break;
			}
		}
	}
	is.close();
}
