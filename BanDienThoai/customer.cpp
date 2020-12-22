#include "customer.h"

customer::customer(int a, string b, string c, string d):customer_id(a),customer_name(b),phonenumber(c),address(d)
{
}

customer::~customer()
{
}

int customer::getCustomerID()
{
	return this->customer_id;
}


istream& operator>>(istream& i, customer& C)
{
	cout << "Customer name: "; i >> C.customer_name;
	cout << "Phonenumber: "; i >> C.phonenumber;
	cout << "Address: "; i >> C.address;
	return i;
}
