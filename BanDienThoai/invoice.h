#pragma once
#include <string>
#include <iostream>
#include "customer.h"
#include "invoice_detail.h"
using namespace std;
class invoice
{
	int invoice_id;
	int customer_id;
	string datebuy;
	int total;
	customer CUS;
	vector<invoice_detail>  DE;
public:
	invoice(int=0, int=0, string="", int=0);
	~invoice();
	void setInvoiceDetail(vector<invoice_detail>);
	void setCustomer(vector<customer>);
	void setCustomer(const customer&);
	int getInvoiceID();
	friend ostream& operator<<(ostream&, const invoice&);
};

