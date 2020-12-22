#include "invoice_detail.h"

invoice_detail::invoice_detail(int a, int b, int c, int d):invoice_id(a),smartphone_id(b),qty(c),unit_price(d)
{
}

invoice_detail::~invoice_detail()
{
}

int invoice_detail::getInvoiceID()
{
	return this->invoice_id;
}

void invoice_detail::setSmartphone(vector<smartphone> &S)
{
	for (int i = 0; i < S.size(); i++) {
		if (this->smartphone_id == S[i].getID()) 
			this->SM = &S[i];
	}
}
