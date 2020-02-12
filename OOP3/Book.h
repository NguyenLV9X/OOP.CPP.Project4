#pragma once
#include"Check.h"
using namespace std;
class CBook : private CCheck
{
private:
	string cb_strCode;
	string cb_strTitle;
	int cb_nYear;
	string cb_strPublisher;
	string cb_strAuthor;
	string cb_strKind;
	int cb_iAmount;
public:
	int getAmount();
	int getYear();
	string getPublisher();
	string getTitle();
	string getCode();
	string getAuthor();
	string getKind();
	void setCode(string t_strValue);
	void setYear(int t_nValue);
	void setAmount(int t_nValue);
	void setTitle(string t_strValue);
	void setPublisher(string t_strValue);
	void setAuthor(string t_strValue);
	void setKind(string t_strValue);
	void importbook();
	void exportbook();
	CBook();
	~CBook();
};