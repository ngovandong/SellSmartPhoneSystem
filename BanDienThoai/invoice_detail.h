#pragma once
#include <string>
#include <iostream>
#include "smartphone.h"
#include <vector>
using namespace std;
class invoice;
class invoice_detail
{
	int invoice_id;
	int smartphone_id;
	int qty;
	int unit_price;
	smartphone* SM;
public:
	invoice_detail(int = 0, int = 0, int = 0, int = 0);
	~invoice_detail();
	int getInvoiceID();
	void setSmartphone(vector<smartphone>&);
	friend ostream& operator<<(ostream&, const invoice&);
};

