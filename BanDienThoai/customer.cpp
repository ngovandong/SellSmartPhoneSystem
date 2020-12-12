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
