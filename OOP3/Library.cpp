#include<algorithm>
#include"Library.h"


void CLibrary::createbook()
{
	CBook cbTemp;
	cout << "NHAP THONG TIN SACH" << endl;
	cbTemp.importbook();
	if ( cl_mBook.findcodebook( cbTemp.getCode() ) )
	{
		cout << endl;
		cout << "Dau sach da ton tai!!!" << endl;
		cout << "============================================";
		cout << endl;
		cout << endl;
		cout << "Hay an phim enter de quay lai menu chinh" << endl;
		system("pause");
	}
	else
	{
		cl_mBook.Append(cbTemp);
	}
}

void CLibrary::showallbook(int option)
{
	if (cl_mBook.empty())
	{
		cout << "Hien tai chua co dau sach nao !" << endl;;
	}
	else
	{
		switch (option)
		{
			case 1:
				sortTitle(cl_mBook);
				break;
			case 2:
				sortPublisher(cl_mBook);
				break;
			case 3:
				sortAuthor(cl_mBook);
				break;
		}
		
		int iLenght = cl_mBook.size();
		cout << "Tong So Dau Sach: " << iLenght << endl;
		cout << endl;
		cout << endl;
		int iCount = 0;
		while (iCount < iLenght)
		{
			cout << "============================================" << endl;
			cout << "THONG TIN DAU SACH " << iCount + 1 << endl;
			cl_mBook[iCount].getData().exportbook();
			++iCount;
		}
	}
	cout << "============================================";
	cout << endl;
	cout << endl;
	cout << "Hay an phim enter de quay lai menu chinh" << endl;
	system("pause");
}

void CLibrary::createcard()
{
	if (cl_mBook.empty())
	{
		cout << "Hien tai chua co dau sach nao !" << endl;
		cout << "============================================";
		cout << endl;
		cout << endl;
		cout << "Hay an phim enter de quay lai menu chinh" << endl;
		system("pause");
	}
	else
	{
		CCallCard ccTemp;
		cout << "NHAP THONG TIN PHIEU MUON" << endl;
		ccTemp.importcard();
		string tCodecard = ccTemp.getCodecard();
		string tCodebook = ccTemp.getCodebook();
		if ( cl_mCard.findcodecard(tCodecard) )
		{
			cout << endl;
			cout << "Ma phieu muon da ton tai!!!" << endl;
			cout << "============================================";
			cout << endl;
			cout << endl;
			cout << "Hay an phim enter de quay lai menu chinh" << endl;
			system("pause");
		}
		else
		{
			if ( !cl_mBook.findcodebook(tCodebook) )
			{
				cout << endl;
				cout << "Dau sach khong ton tai!!!" << endl;
				cout << "============================================";
				cout << endl;
				cout << endl;
				cout << "Hay an phim enter de quay lai menu chinh" << endl;
				system("pause");
			}
			else
			{
				CBook cbTemp = cl_mBook[tCodebook];
				int tAmount = cbTemp.getAmount();
				if (tAmount == 0)
				{
					cout << endl;
					cout << "Dau sach khong du so luong!!!" << endl;
					cout << "============================================";
					cout << endl;
					cout << endl;
					cout << "Hay an phim enter de quay lai menu chinh" << endl;
					system("pause");
				}
				else
				{
					cl_mCard.Append(ccTemp);
					cl_mBook[tCodebook].setAmount(tAmount - 1);
				}
			}
		}
	}
}

void CLibrary::updatecard()
{
	if (cl_mCard.empty())
	{
		cout << "Hien tai chua co phieu muon nao !" << endl;
		cout << "============================================";
		cout << endl;
		cout << endl;
		cout << "Hay an phim enter de quay lai menu chinh" << endl;
		system("pause");
	}
	else
	{
		string tCodecard;
		cout << "Nhap ma so phieu muon : ";
		getline(cin, tCodecard);
		if ( !cl_mCard.findcodecard(tCodecard) )
		{
			cout << endl;
			cout << "Phieu muon khong ton tai!!!" << endl;
			cout << "============================================";
			cout << endl;
			cout << endl;
			cout << "Hay an phim enter de quay lai menu chinh" << endl;
			system("pause");
		}
		else
		{
			cout << "CAP NHAP THONG TIN PHIEU MUON" << endl;
			cl_mCard[tCodecard].updatecard();
			string tCodebook = cl_mCard[tCodecard].getCodebook();
			int tAmount = cl_mBook[tCodebook].getAmount();
			cl_mBook[tCodebook].setAmount(tAmount + 1);
		}
	}
}

void CLibrary::showcard(int option)
{
	if (cl_mCard.empty())
	{
		cout << "Hien tai chua co phieu muon nao !" << endl;
	}
	else
	{
		switch (option)
		{
		case 1:
			sortDatestart(cl_mCard);
			break;
		case 2:
			sortDateend(cl_mCard);
			break;
		case 3:
			sortName(cl_mCard);
			break;
		case 4:
			sortSTcard(cl_mCard);
			break;
		}

		int iLenght = cl_mCard.size();
		int iCount = 0;
		while (iCount < iLenght)
		{
			cout << "============================================" << endl;
			cout << "THONG TIN PHIEU MUON " << iCount + 1 << endl;
			cl_mCard[iCount].getData().exportcard();
			++iCount;
		}
	}
	cout << "============================================";
	cout << endl;
	cout << endl;
	cout << "Hay an phim enter de quay lai menu chinh" << endl;
	system("pause");
}

void CLibrary::searchbook(int option)
{
	if (cl_mBook.empty())
	{
		cout << "============================================" << endl;
		cout << "Hien tai chua co dau sach nao !" << endl;
	}
	else
	{
		string strCodehuman;
		string strName;
		string strDatestart;
		string strDateend;
		string strSTbook;
		switch (option)
		{
		case 1:
			cout << "Nhap ma nguoi muon : ";
			getline(cin, strCodehuman);
			searchbookCodehuman(cl_mBook, cl_mCard, strCodehuman);
			break;
		case 2:
			cout << "Nhap ten nguoi muon : ";
			getline(cin, strName);
			searchbookName(cl_mBook, cl_mCard, strName);
			break;
		case 3:
			cout << "Nhap ngay muon : ";
			getline(cin, strDatestart);
			searchbookDatestart(cl_mBook, cl_mCard, strDatestart);
			break;
		case 4:
			cout << "Nhap ngay tra : ";
			getline(cin, strDateend);
			searchbookDateend(cl_mBook, cl_mCard, strDateend);
			break;
		case 5:
			cout << "Nhap tinh trang sach : ";
			getline(cin, strSTbook);
			searchbookDateend(cl_mBook, cl_mCard, strSTbook);
			break;
		}
	}
	cout << "============================================";
	cout << endl;
	cout << endl;
	cout << "Hay an phim enter de quay lai menu chinh" << endl;
	system("pause");
}

void CLibrary::searchcard(int option)
{
	if (cl_mCard.empty())
	{
		cout << "============================================" << endl;
		cout << "Hien tai chua co phieu muon nao !" << endl;
	}
	else
	{
		string strCodebook;
		string strTitle;
		int strYear;
		string strAuthor;
		string strKind;
		switch (option)
		{
		case 1:
			cout << "Nhap ma sach : ";
			getline(cin, strCodebook);
			searchcardCodebook(cl_mBook, cl_mCard, strCodebook);
			break;
		case 2:
			cout << "Nhap tieu de sach : ";
			getline(cin, strTitle);
			searchcardTitlebook(cl_mBook, cl_mCard, strTitle);
			break;
		case 3:
			cout << "Nhap nam xuat ban : ";
			cin >> strYear;
			cin.ignore();
			searchcardYearbook(cl_mBook, cl_mCard, strYear);
			break;
		case 4:
			cout << "Nhap tac gia : ";
			getline(cin, strAuthor);
			searchcardAuthorbook(cl_mBook, cl_mCard, strAuthor);
			break;
		case 5:
			cout << "Nhap the loai sach : ";
			getline(cin, strKind);
			searchcardKindbook(cl_mBook, cl_mCard, strKind);
			break;
		}
	}
	cout << "============================================";
	cout << endl;
	cout << endl;
	cout << "Hay an phim enter de quay lai menu chinh" << endl;
	system("pause");
}


CLibrary::CLibrary()
{
	readFilebook(cl_mBook);
	readFilecard(cl_mCard);
}

CLibrary::~CLibrary()
{
	writeFilebook(cl_mBook);
	writeFilecard(cl_mCard);
}
