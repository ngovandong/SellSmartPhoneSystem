#pragma once
#include <string>
#include <iostream>
using namespace std;
class smartphone
{
protected:
	int smartphone_id;
	string smartphone_name;
	string brand;
	int	price;
	int qty;
	int qty_sold;
	int RAM;
	int ROM;
	int battery;
	float screen;
	string color;
	int cameras;
	string warranty;
	string others;
public:
	smartphone(int=0,string= "", string = "",int=0,int=0,int=0,int=0,int=0,int=0,float=0, string = "",int=0, string = "", string = "");
	~smartphone();
	friend ostream& operator<<(ostream&, const smartphone&);
	friend istream& operator>>(istream&, smartphone&);
	friend class LIST;
	int getPrice();
	int getSold();
	int getID();
};
