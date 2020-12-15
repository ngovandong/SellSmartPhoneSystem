#include "customer.h"

customer::customer(int a, string b, string c, string d):customer_id(a),customer_name(b),phonenumber(c),address(d)
{
}

customer::~customer()
{
}

ostream& operator<<(ostream& o, const customer& c)
{
	o << "Customer_id: " << c.customer_id << endl;
	o << "Customer name: " << c.customer_name << endl;
	o << "Phonenumber: " << c.phonenumber << endl;
	o << "Address: " << c.address << endl;
	return o;
}

istream& operator>>(istream& i, customer& C)
{
	cout << "Customer name: "; i >> C.customer_name;
	cout << "Phonenumber: "; i >> C.phonenumber;
	cout << "Address: "; i >> C.address;
	return i;
}
