#pragma once
#include <string>
#include <iostream>
using namespace std;
class invoice_detail
{
	int invoice_id;
	int smartphone_id;
	int qty;
	int unit_price;
public:
	invoice_detail(int = 0, int = 0, int = 0, int = 0);
	~invoice_detail();
	friend ostream& operator<<(ostream&, const invoice_detail);
};

