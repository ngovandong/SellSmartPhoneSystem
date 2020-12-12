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
void smartphone::print()
{
	cout << "*******Smartphone feature********" << endl;
	cout << "Id: " << this->smartphone_id << endl;
	cout << "Name: " << this->smartphone_name << endl;
	cout << "Brand: " << this->brand << endl;
	cout << "Price: " << this->price << endl;
	cout << "Quantity: " << this->qty << endl;
	cout << "Sold: " << this->qty_sold << endl;
	cout << "RAM: " << this->RAM << endl;
	cout << "ROM: " << this->ROM << endl;
	cout << "Battery: " << this->battery << endl;
	cout << "Screen: " << this->screen << endl;
	cout << "Color: " << this->color << endl;
	cout << "Cameras: " << this->cameras << endl;
	cout << "Warranty: " << this->warranty << endl;
	cout << "Others: " << this->others << endl;
}
void smartphone::scan()
{
	cout << "*******Enter smartphone feature********"<<endl;
	cout << "Id: ";cin>> this->smartphone_id ;
	cin.ignore();
	cout << "Name: "; getline(cin,this->smartphone_name) ;
	cout << "Brand: "; getline(cin,this->brand) ;
	cout << "Price: ";cin>> this->price ;
	cout << "Qantity: "; cin >> this->qty;
	cout << "Sold: ";cin>> this->qty_sold;
	cout << "RAM: ";cin>> this->RAM;
	cout << "ROM: ";  cin >> this->ROM;
	cout << "Battery: ";cin>> this->battery;
	cout << "Screen: ";cin>> this->screen;
	cin.ignore();
	cout << "Color: "; getline(cin,this->color) ;
	cout << "Cameras: ";cin>> this->cameras ;
	cin.ignore();
	cout << "Warranty: "; getline(cin,this->warranty) ;
	cout << "Others: "; getline( cin,this->others);
}

void smartphone::update()
{
	cout << "******Enter smartphone feature*******" << endl;
	cout << "Name: "; getline(cin, this->smartphone_name);
	cout << "Brand: "; getline(cin, this->brand);
	cout << "Price: "; cin >> this->price;
	cout << "Qantity: "; cin >> this->qty;
	cout << "Sold: "; cin >> this->qty_sold;
	cout << "RAM: "; cin >> this->RAM;
	cout << "ROM: ";  cin >> this->ROM;
	cout << "Battery: "; cin >> this->battery;
	cout << "Screen: "; cin >> this->screen;
	cin.ignore();
	cout << "Color: "; getline(cin, this->color);
	cout << "Cameras: "; cin >> this->cameras;
	cin.ignore();
	cout << "Warranty: "; getline(cin, this->warranty);
	cout << "Others: "; getline(cin, this->others);
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
	cout << "Id: "; i >> s.smartphone_id;
	i.ignore();
	cout << "Name: "; getline(i,s.smartphone_name);
	cout << "Brand: "; getline(i,s.brand);
	cout << "Price: "; i >> s.price;
	cout << "Qantity: "; i >> s.qty;
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
