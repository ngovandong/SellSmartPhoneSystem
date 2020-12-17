#pragma once
#include "DBHelper.h"
#include <vector>
class LIST
{
	vector<smartphone> SM;
	vector<customer> CUS;
	vector<invoice> INV;
	vector<invoice_detail> DE;
	LIST();
	~LIST();
	static LIST* instance;
public:
	static LIST* getInstance();
	void displaySmartphone();
	void addSmartphone();
	void DeleteSmartphone();
	void updateSmartphone();
};
