#pragma once
#include <string>
#include <iostream>
using namespace std;
class invoice
{
	int invoice_id;
	int customer_id;
	string datebuy;
	int total;
public:
	invoice(int=0, int=0, string="", int=0);
	~invoice();
	friend ostream& operator<<(ostream&, const invoice&);
	
};

