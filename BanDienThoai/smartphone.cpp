#include "smartphone.h"
#include <iostream>
using namespace std;

smartphone::smartphone(int id, string name, string brand, int price, int qty, int qty_sold, int ram
	, int rom, int battery, float screen, string color, int cameras, string warranty, string others) {
	this->smartphone_id = id;
	this->smartphone_name = name;
	this->brand= brand;
	this->price = price;
	this->qty = qty;
	this->qty_sold = qty_sold;
	this->RAM = ram;
	this->ROM = rom;
	this->battery = battery;
	this->screen = screen;
	this->color = color;
	this->cameras = cameras;
	this->warranty = warranty;
	this->others = others;
}
smartphone::~smartphone() {

}

int smartphone::getPrice()
{
	return this->price;
}

int smartphone::getSold()
{
	return this->qty_sold;
}

int smartphone::getID()
{
	return this->smartphone_id;
}


ostream& operator<<(ostream& o, const smartphone& s)
{
	o << "*******Smartphone feature********" << endl;
	o << "Id: " << s.smartphone_id << endl;
	o << "Name: " << s.smartphone_name << endl;
	o << "Brand: " << s.brand << endl;
	o << "Price: " << s.price << endl;
	o << "Quantity: " << s.qty << endl;
	o << "Sold: " << s.qty_sold << endl;
	o << "RAM: " << s.RAM << endl;
	o << "ROM: " << s.ROM << endl;
	o << "Battery: " <<s.battery << endl;
	o << "Screen: " << s.screen << endl;
	o << "Color: " << s.color << endl;
	o << "Cameras: " << s.cameras << endl;
	o << "Warranty: " << s.warranty << endl;
	o << "Others: " << s.others << endl;
	return o;
}

istream& operator>>(istream& i, smartphone& s)
{
	cout << "*******Enter smartphone feature********" << endl;
	cout << "Name: "; getline(i,s.smartphone_name);
	cout << "Brand: "; getline(i,s.brand);
	cout << "Price: "; i >> s.price;
	cout << "Quantity: "; i >> s.qty;
	cout << "Sold: "; i >> s.qty_sold;
	cout << "RAM: "; i >> s.RAM;
	cout << "ROM: ";  i >> s.ROM;
	cout << "Battery: "; i >> s.battery;
	cout << "Screen: "; i >> s.screen;
	i.ignore();
	cout << "Color: "; getline(i,s.color);
	cout << "Cameras: "; i >> s.cameras;
	i.ignore();
	cout << "Warranty: ";getline(i,s.warranty);
	cout << "Others: "; getline(i,s.others);
	return i;
}

