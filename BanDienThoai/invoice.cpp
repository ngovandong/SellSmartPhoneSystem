#include "invoice.h"

invoice::invoice(int a, int b,string c, int d):invoice_id(a),customer_id(b),total(d),datebuy(c)
{
}

invoice::~invoice()
{
}

void invoice::setInvoiceDetail(vector<invoice_detail> D)
{
	for (int i = 0; i < D.size(); i++)
		if (this->invoice_id == D[i].getInvoiceID())
			this->DE.push_back(D[i]);
}

void invoice::setCustomer(vector<customer> C)
{
	for (int i = 0; i < C.size(); i++)
		if (this->customer_id == C[i].getCustomerID())
			this->CUS = C[i];
}

void invoice::setCustomer(const customer &c)
{
	this->CUS = c;
}

int invoice::getInvoiceID()
{
	return this->invoice_id;
}

ostream& operator<<(ostream& o, const invoice& t)
{
	o << "___________________________________________________________________" << endl;
	o << "Invoice_id: " <<setw(53)<< t.invoice_id<<"  |" << endl;
	o << "Date buy: " << setw(55) << t.datebuy << "  |" << endl;
	o << "Total: " << setw(58) << t.total << "  |" << endl;
	o << "___________________________________________________________________|" << endl;
	o << "Bill to: " << setw(59)<<"|"<<endl;
	o << "Customer name: " << setw(50) << t.CUS.customer_name << "  |" <<endl;
	o << "Phone number: " << setw(51) << t.CUS.phonenumber << "  |" << endl;
	o << "Address: " << setw(56) << t.CUS.address << "  |" <<endl;
	o << "___________________________________________________________________|" << endl;
	o << "Detail:" << setw(61) << "|" << endl;
	o <<setw(30)<< "Smartphone name" <<setw(15) <<"Quantity" <<setw(20) <<"Unit price"<<"  |"<< endl;
	for (int i = 0; i < t.DE.size(); i++) {
		o <<setw(30) << t.DE[i].SM->smartphone_name;
		o <<setw(15)<< t.DE[i].qty;
		o <<setw(20)<< t.DE[i].unit_price <<"  |"<< endl;
	}
	o << "___________________________________________________________________|" << endl;
	o << endl << endl;
	return o;
}


