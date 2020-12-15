#include "invoice.h"

invoice::invoice(int a, int b,string c, int d):invoice_id(a),customer_id(b),total(d),datebuy(c)
{
}

invoice::~invoice()
{
}

ostream& operator<<(ostream& o, const invoice& t)
{
	o << "Invoice_id: " << t.invoice_id << endl;
	o << "Customer_id: " << t.customer_id << endl;
	o << "Date buy: " << t.datebuy << endl;
	o << "Total: " << t.total << endl;
	return o;
}


