#include "Book.h"

int CBook::getAmount()
{
	return cb_iAmount;
}

int CBook::getYear()
{
	return cb_nYear;
}

string CBook::getPublisher()
{
	return cb_strPublisher;
}

string CBook::getTitle()
{
	return cb_strTitle;
}

string CBook::getCode()
{
	return cb_strCode;
}

string CBook::getAuthor()
{
	return cb_strAuthor;
}

string CBook::getKind()
{
	return cb_strKind;
}

void CBook::setCode(string t_strValue)
{
	try
	{
		if (!checkValue6Number(t_strValue))
			throw 1;
		cb_strCode = t_strValue;
	}
	catch (int exception)
	{
		throw exception;
	}
}
void CBook::setYear(int t_nValue)
{
	try
	{
		if (!checkYearBook(t_nValue))
			throw 2;
		cb_nYear = t_nValue;
	}
	catch (int exception)
	{
		throw exception;
	}
}
void CBook::setAmount(int t_nValue)
{
	try
	{
		if (!checkNaturalNumber(t_nValue))
			throw 3;
		cb_iAmount = t_nValue;
	}
	catch (int exception)
	{
		throw exception;
	}
}
void CBook::setTitle(string t_strValue)
{
	cb_strTitle = t_strValue;
}
void CBook::setPublisher(string t_strValue)
{
	cb_strPublisher = t_strValue;
}
void CBook::setAuthor(string t_strValue)
{
	cb_strAuthor = t_strValue;
}
void CBook::setKind(string t_strValue)
{
	cb_strKind = t_strValue;
}
void CBook::importbook()
{
	do
	{
		try
		{
			string strCode;
			cout << "Nhap ma sach : ";
			getline(cin, strCode);
			setCode(strCode);
			cout << "Nhap tieu de sach : ";
			getline(cin, cb_strTitle);
			int nYear;
			cout << "Nhap nam san xuat : ";
			cin >> nYear;
			cin.ignore();
			setYear(nYear);
			cout << "Nhap nha san xuat : ";
			getline(cin, cb_strPublisher);
			cout << "Nhap tac gia : ";
			getline(cin, cb_strAuthor);
			cout << "Nhap the loai : ";
			getline(cin, cb_strKind);
			int iAmount;
			cout << "Nhap so luong : ";
			cin >> iAmount;
			cin.ignore();
			setAmount(iAmount);
			break;
		}
		catch (int exception)
		{
			if (exception == 1)
			{
				cout << "Ma code khong hop le xin nhap lai tu dau!!!" << endl;
			}
			if (exception == 2)
			{
				cout << "Nam san xuat khong hop le xin nhap lai tu dau!!!" << endl;
			}
			if (exception == 3)
			{
				cout << "So luong khong hop le xin nhap lai tu dau!!!" << endl;
			}
		}
	} while (true);
	
}

void CBook::exportbook()
{
	cout << "Ma sach : " << cb_strCode << endl;
	cout << "Tieu de sach : " << cb_strTitle << endl;
	cout << "Nam san xuat : " << cb_nYear << endl;
	cout << "Nha xuat ban : " << cb_strPublisher << endl;
	cout << "Tac gia : " << cb_strAuthor << endl;
	cout << "The loai : " << cb_strKind << endl;
	cout << "So luong : " << cb_iAmount << endl;
}

CBook::CBook()
{
}

CBook::~CBook()
{
}
