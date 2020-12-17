#pragma once
#include <string>
#include <iostream>

using namespace std;

class customer
{
	int customer_id;
	string customer_name;
	string phonenumber;
	string address;
public:
	customer(int =0, string="",string="", string="");
	~customer();
	friend ostream& operator<<(ostream&, const customer&);
	friend istream& operator>>(istream&, customer&);
	friend class LIST;
};

