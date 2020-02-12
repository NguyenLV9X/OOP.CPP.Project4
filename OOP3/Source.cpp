#include"Library.h"

int main()
{
	int menu_option;
	CLibrary clLibrary;
	do
	{
		try
		{
			system("cls");
			cout << "========Chuong Trinh Quan Ly Thu Vien========" << endl;
			cout << endl;
			cout << "Moi Ban chon:" << endl;
			cout << endl;
			cout << "1-Nhap thong tin sach." << endl;
			cout << endl;
			cout << "2-Danh sach thong tin sach." << endl;
			cout << endl;
			cout << "3-Muon sach." << endl;
			cout << endl;
			cout << "4-Tra sach." << endl;
			cout << endl;
			cout << "5-Danh sach phieu muon sach." << endl;
			cout << endl;
			cout << "6-Tim kiem." << endl;
			cout << endl;
			cout << "0-Thoat." << endl;
			cout << endl;
			cout << "============================================" << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "Lua chon cua ban la : ";
			cin >> menu_option;
			if ( cin.fail() || !(cin.peek() == EOF || cin.peek() == '\n') )
			{
				cin.clear();
				cin.ignore();
				throw 1;
			}
			cin.ignore();
			system("cls");
			switch (menu_option)
			{
			case 1:
				clLibrary.createbook();
				break;
			case 2:
				int menu_option2;
				do
				{
					try
					{
						system("cls");
						cout << "========Hien Thi Dau Sach========" << endl;
						cout << endl;
						cout << "Moi Ban chon:" << endl;
						cout << endl;
						cout << "1-Sap xep theo tieu de sach." << endl;
						cout << endl;
						cout << "2-Sap xep theo nha xuat ban." << endl;
						cout << endl;
						cout << "3-Sap xep theo tac gia." << endl;
						cout << endl;
						cout << "0-Thoat." << endl;
						cout << endl;
						cout << "============================================" << endl;
						cout << endl;
						cout << endl;
						cout << endl;
						cout << "Lua chon cua ban la : ";
						cin >> menu_option2;
						if (cin.fail() || !(cin.peek() == EOF || cin.peek() == '\n'))
						{
							cin.clear();
							cin.ignore();
							throw 1;
						}
						if (menu_option2 < 0 || menu_option2 > 3)
						{
							throw 1;
						}
						cin.ignore();
						system("cls");
						if (menu_option2 != 0)
						{
							clLibrary.showallbook(menu_option2);
							break;
						}
					}
					catch (...)
					{
						menu_option2 = 4;
					}
				} while ( menu_option2 != 0 );
				break;
			case 3:
				clLibrary.createcard();
				break;
			case 4:
				clLibrary.updatecard();
				break;
			case 5:
				int menu_option3;
				do
				{
					try
					{
						system("cls");
						cout << "========Danh Sach Phieu Muon========" << endl;
						cout << endl;
						cout << "Moi Ban chon:" << endl;
						cout << endl;
						cout << "1-Sap xep theo ngay muon." << endl;
						cout << endl;
						cout << "2-Sap xep theo ngay tra." << endl;
						cout << endl;
						cout << "3-Sap xep theo ten nguoi muon." << endl;
						cout << endl;
						cout << "4-Sap xep theo trang thai phieu muon." << endl;
						cout << endl;
						cout << "0-Thoat." << endl;
						cout << endl;
						cout << "============================================" << endl;
						cout << endl;
						cout << endl;
						cout << endl;
						cout << "Lua chon cua ban la : ";
						cin >> menu_option3;
						if (cin.fail() || !(cin.peek() == EOF || cin.peek() == '\n'))
						{
							cin.clear();
							cin.ignore();
							throw 1;
						}
						if (menu_option3 < 0 || menu_option3 > 4)
						{
							throw 1;
						}
						cin.ignore();
						system("cls");
						if (menu_option3 != 0)
						{
							clLibrary.showcard(menu_option3);
							break;
						}
					}
					catch (...)
					{
						menu_option3 = 5;
					}
				} while (menu_option3 != 0);
				break;
			case 6:
				int menu_option4;
				do
				{
					try
					{
						system("cls");
						cout << "========Tim kiem========" << endl;
						cout << endl;
						cout << "Moi Ban chon:" << endl;
						cout << endl;
						cout << "1-Sach." << endl;
						cout << endl;
						cout << "2-Phieu muon." << endl;
						cout << endl;
						cout << "0-Thoat." << endl;
						cout << endl;
						cout << "============================================" << endl;
						cout << endl;
						cout << endl;
						cout << endl;
						cout << "Lua chon cua ban la : ";
						cin >> menu_option4;
						if (cin.fail() || !(cin.peek() == EOF || cin.peek() == '\n'))
						{
							cin.clear();
							cin.ignore();
							throw 1;
						}
						if (menu_option4 < 0 || menu_option4 > 2)
						{
							throw 1;
						}
						cin.ignore();
						system("cls");
						if (menu_option4 != 0)
						{
							if (menu_option4 == 1)
							{
								int menu_option5;
								do
								{
									try
									{
										system("cls");
										cout << "========Tim kiem sach========" << endl;
										cout << endl;
										cout << "Moi Ban chon:" << endl;
										cout << endl;
										cout << "1-Theo ma nguoi muon." << endl;
										cout << endl;
										cout << "2-Theo ten nguoi muon." << endl;
										cout << endl;
										cout << "3-Theo ngay muon." << endl;
										cout << endl;
										cout << "4-Theo ngay tra." << endl;
										cout << endl;
										cout << "5-Theo tinh trang sach." << endl;
										cout << endl;
										cout << "0-Thoat." << endl;
										cout << endl;
										cout << "============================================" << endl;
										cout << endl;
										cout << endl;
										cout << endl;
										cout << "Lua chon cua ban la : ";
										cin >> menu_option5;
										if (cin.fail() || !(cin.peek() == EOF || cin.peek() == '\n'))
										{
											cin.clear();
											cin.ignore();
											throw 1;
										}
										if (menu_option5 < 0 || menu_option5 > 5)
										{
											throw 1;
										}
										cin.ignore();
										system("cls");
										if (menu_option5 != 0)
										{
											clLibrary.searchbook(menu_option5);
											break;
										}
									}
									catch (...)
									{
										menu_option5 = 6;
									}
								} while (menu_option5 != 0);
								break;
							}
							if (menu_option4 == 2)
							{
								int menu_option6;
								do
								{
									try
									{
										system("cls");
										cout << "========Tim kiem sach========" << endl;
										cout << endl;
										cout << "Moi Ban chon:" << endl;
										cout << endl;
										cout << "1-Theo ma sach." << endl;
										cout << endl;
										cout << "2-Tieu de sach." << endl;
										cout << endl;
										cout << "3-Nam xuat ban." << endl;
										cout << endl;
										cout << "4-Tac gia." << endl;
										cout << endl;
										cout << "5-The loai." << endl;
										cout << endl;
										cout << "0-Thoat." << endl;
										cout << endl;
										cout << "============================================" << endl;
										cout << endl;
										cout << endl;
										cout << endl;
										cout << "Lua chon cua ban la : ";
										cin >> menu_option6;
										if (cin.fail() || !(cin.peek() == EOF || cin.peek() == '\n'))
										{
											cin.clear();
											cin.ignore();
											throw 1;
										}
										if (menu_option6 < 0 || menu_option6 > 5)
										{
											throw 1;
										}
										cin.ignore();
										system("cls");
										if (menu_option6 != 0)
										{
											clLibrary.searchcard(menu_option6);
											break;
										}
									}
									catch (...)
									{
										menu_option6 = 6;
									}
								} while (menu_option6 != 0);
								break;
							}
							break;
						}
					}
					catch (...)
					{
						menu_option4 = 3;
					}
				} while (menu_option4 != 0);
				break;

			default:
				break;
			}
		}
		catch (...)
		{
			menu_option = 7;
		}
		
	} while ( menu_option != 0 );
	return 0;
}