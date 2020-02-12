#include "CallCard.h"


string CCallCard::getName()
{
	return cc_strName;
}

string CCallCard::getSTcard()
{
	return cc_strSTcard;
}

string CCallCard::getDatestart()
{
	return cc_strDatestart;
}

string CCallCard::getDateend()
{
	return cc_strDateend;
}

string CCallCard::getCodecard()
{
	return cc_strCodecard;
}

string CCallCard::getCodebook()
{
	return cc_strCodebook;
}

string CCallCard::getCodehuman()
{
	return cc_strCodehuman;
}

string CCallCard::getSTbookS()
{
	return cc_strSTbookS;
}

string CCallCard::getSTbookE()
{
	return cc_strSTbookE;
}

void CCallCard::setCodecard(string t_strValue)
{
	try
	{
		if (!checkValue6Number(t_strValue))
			throw 1;
		cc_strCodecard = t_strValue;
	}
	catch (int exception)
	{
		throw exception;
	}
}

void CCallCard::setCodehuman(string t_strValue)
{
	try
	{
		if (!checkValue6Number(t_strValue))
			throw 2;
		cc_strCodehuman = t_strValue;
	}
	catch (int exception)
	{
		throw exception;
	}
}

void CCallCard::setCodebook(string t_strValue)
{
	try
	{
		if (!checkValue6Number(t_strValue))
			throw 3;
		cc_strCodebook = t_strValue;
	}
	catch (int exception)
	{
		throw exception;
	}
}

void CCallCard::setDatestart(string t_strValue)
{
	try
	{
		if (!checkFormat(t_strValue))
			throw 4;
		cc_strDatestart = t_strValue;
	}
	catch (int exception)
	{
		throw exception;
	}
}

void CCallCard::setDateendfile(string t_strValue)
{
	cc_strDateend = t_strValue;
}

void CCallCard::setDateend(string t_strValue)
{
	try
	{
		if (!checkFormat(t_strValue))
			throw 5;
		cc_strDateend = t_strValue;
	}
	catch (int exception)
	{
		throw exception;
	}
}

void CCallCard::setSTbookS(string t_strValue)
{
	cc_strSTbookS = t_strValue;
}

void CCallCard::setSTbookE(string t_strValue)
{
	cc_strSTbookE = t_strValue;
}

void CCallCard::setSTcard(string t_strValue)
{
	cc_strSTcard = t_strValue;
}

void CCallCard::setName(string t_strValue)
{
	cc_strName = t_strValue;
}

void CCallCard::importcard()
{
	do
	{
		try
		{
			string strCodecard;
			cout << "Nhap ma phieu muon : ";
			getline(cin, strCodecard);
			setCodecard(strCodecard);
			string strCodehuman;
			cout << "Nhap ma so nguoi muon : ";
			getline(cin, strCodehuman);
			setCodehuman(strCodehuman);
			cout << "Nhap ten nguoi muon : ";
			getline(cin, cc_strName);
			string strCodebook;
			cout << "Nhap ma sach : ";
			getline(cin, strCodebook);
			setCodebook(strCodebook);
			string strDatestart;
			cout << "Nhap ngay muon : ";
			getline(cin, strDatestart);
			setDatestart(strDatestart);
			cout << "Nhap trang thai sach khi muon : ";
			getline(cin, cc_strSTbookS);
			break;
		}
		catch (int exception)
		{
			switch (exception)
			{
				case 1:
					cout << "Ma phieu muon khong hop le xin nhap lai tu dau!!!" << endl;
					break;
				case 2:
					cout << "Ma so nguoi muon khong hop le xin nhap lai tu dau!!!" << endl;
					break;
				case 3:
					cout << "Ma sach khong hop le xin nhap lai tu dau!!!" << endl;
					break;
				case 4:
					cout << "Ngay muon khong dung dinh dang xin nhap lai tu dau!!!" << endl;
					break;
				default:
					break;
			}
		}

	}while(true);	
}

void CCallCard::exportcard()
{
	cout << "Tinh trang phieu muon : " << cc_strSTcard << endl;
	cout << "Ma phieu muon : " << cc_strCodecard << endl;
	cout << "Ma so nguoi muon : " << cc_strCodehuman << endl;
	cout << "Ten nguoi muon : " << cc_strName << endl;
	cout << "Ma sach : " << cc_strCodebook << endl;
	cout << "Ngay muon : " << cc_strDatestart << endl;
	cout << "Ngay tra : " << cc_strDateend << endl;
	cout << "Tinh trang sach khi muon : " << cc_strSTbookS << endl;
}

void CCallCard::updatecard()
{
	do
	{
		try
		{
			string rgDateend;
			cout << "Nhap ngay tra : ";
			getline(cin, rgDateend);
			setDateend(rgDateend);
			cout << "Nhap trang thai sach khi tra : ";
			getline(cin, cc_strSTbookS);
			this->cc_strSTcard = "Tra";
			break;
		}
		catch (int exception)
		{
			if (exception == 5)
				cout << "Ngay tra khong dung dinh dang xin nhap lai tu dau!!!" << endl;
		}
	} while (true);
	
}

CCallCard::CCallCard()
{
	this->cc_strSTbookE = "NULL";
	this->cc_strSTcard = "Muon";
	this->cc_strDateend = "NULL";
}

CCallCard::~CCallCard()
{

}
