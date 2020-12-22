#pragma once
#include <string>
#include <iostream>
using namespace std;
class invoice;
class customer
{
	int customer_id;
	string customer_name;
	string phonenumber;
	string address;
public:
	customer(int =0, string="",string="", string="");
	~customer();
	int getCustomerID();
	friend istream& operator>>(istream&, customer&);
	friend ostream& operator<<(ostream&, const invoice&);
};

