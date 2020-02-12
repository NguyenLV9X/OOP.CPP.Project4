#pragma once
#include"Check.h"
class CCallCard : private CCheck
{
private:
	string cc_strCodecard;
	string cc_strCodehuman;
	string cc_strName;
	string cc_strCodebook;
	string cc_strDatestart;
	string cc_strDateend;
	string cc_strSTbookS;
	string cc_strSTbookE;
	string cc_strSTcard;
public:
	string getName();
	string getSTcard();
	string getDatestart();
	string getDateend();
	string getCodecard();
	string getCodebook();
	string getCodehuman();
	string getSTbookS();
	string getSTbookE();
	void setCodecard(string t_strValue);
	void setCodehuman(string t_strValue);
	void setCodebook(string t_strValue);
	void setDatestart(string t_strValue);
	void setDateendfile(string t_strValue);
	void setDateend(string t_strValue);
	void setSTbookS(string t_strValue);
	void setSTbookE(string t_strValue);
	void setSTcard(string t_strValue);
	void setName(string t_strValue);
	void importcard();
	void exportcard();
	void updatecard();
	CCallCard();
	~CCallCard();
};