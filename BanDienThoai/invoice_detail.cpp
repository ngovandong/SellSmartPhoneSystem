#include "invoice_detail.h"

invoice_detail::invoice_detail(int a, int b, int c, int d):invoice_id(a),smartphone_id(b),qty(c),unit_price(d)
{
}

invoice_detail::~invoice_detail()
{
}

ostream& operator<<(ostream& o, const invoice_detail t)
{
	o << "Invoice_id: " << t.invoice_id<<endl;
	o << "Smartphone_id: " << t.smartphone_id<<endl;
	o << "Quantity: " << t.qty<<endl;
	o << "Unit price: " << t.unit_price << endl;
	return o;
}
