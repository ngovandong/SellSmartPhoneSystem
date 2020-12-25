#include "smartphone.h"
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

string smartphone::getName()
{
	return this->smartphone_name;
}

string smartphone::getBrand()
{
	return this->brand;
}


ostream& operator<<(ostream& o, const smartphone& s)
{
	o << "\n\nSmartphone feature" << endl;
	o << "____________________________________________"<<endl;
	o << setw(-10)<< "Id: " << s.smartphone_id << endl;
	o << "____________________________________________|"<<endl;
	o << setw(-10) << "Name: " << s.smartphone_name << endl;
	o << "____________________________________________|"<<endl;
	o << setw(-10) << "Brand: " << s.brand << endl;
	o << "____________________________________________|"<<endl;
	o << setw(-10) << "Price: " << s.price << endl;
	o << "____________________________________________|" << endl;
	o << setw(-10) << "Quantity: " << s.qty << endl;
	o << "____________________________________________|" << endl;
	o << setw(-10) << "Sold: " << s.qty_sold << endl;
	o << "____________________________________________|" << endl;
	o << setw(-10) << "RAM: " << s.RAM << endl;
	o << "____________________________________________|" << endl;
	o << setw(-10) << "ROM: " << s.ROM << endl;
	o << "____________________________________________|" << endl;
	o << setw(-10) << "Battery: " <<s.battery << endl;
	o << "____________________________________________|" << endl;
	o << setw(-10) << "Screen: " << s.screen << endl;
	o << "____________________________________________|" << endl;
	o << setw(-10) << "Color: " << s.color << endl;
	o << "____________________________________________|" << endl;
	o << setw(-10) << "Cameras: " << s.cameras << endl;
	o << "____________________________________________|" << endl;
	o << setw(-10) << "Warranty: " << s.warranty << endl;
	o << "____________________________________________|" << endl;
	o << setw(-10) << "Others: " << s.others << endl;
	o << "____________________________________________|" << endl<<endl;
	return o;
}

istream& operator>>(istream& i, smartphone& s)
{
	cout << "*******Enter smartphone feature********" << endl;
	cout << "Name: "; 
	cin.ignore();
	getline(i, s.smartphone_name);
	cout << "Brand: "; getline(i,s.brand);
	while (1) {
		int kt = 1;
		try {
			cout << "Price: ";
			nhap<int>(s.price);
		}
		catch (string S) {
			cout << S << endl;
			kt = 0;
		}
		if (kt) break;
	}
	while (1) {
		int kt = 1;
		try {
			cout << "Quantity: ";
			nhap<int>(s.qty);
			checkNegative(s.qty);
		}
		catch (string S) {
			cout << S << endl;
			kt = 0;
		}
		if (kt) break;
	}
	while (1) {
		int kt = 1;
		try {
			cout << "Sold: ";
			nhap<int>(s.qty_sold);
			checkNegativeOrEqual0(s.qty_sold);
		}
		catch (string S) {
			cout << S << endl;
			kt = 0;
		}
		if (kt) break;
	}
	while (1) {
		int kt = 1;
		try {
			cout << "RAM: ";
			nhap<int>(s.RAM);
			checkNegative(s.RAM);
		}
		catch (string S) {
			cout << S << endl;
			kt = 0;
		}
		if (kt) break;
	}
	while (1) {
		int kt = 1;
		try {
			cout << "ROM: ";
			nhap<int>(s.ROM);
			checkNegative(s.ROM);
		}
		catch (string S) {
			cout << S << endl;
			kt = 0;
		}
		if (kt) break;
	}
	while (1) {
		int kt = 1;
		try {
			cout << "Battery: ";
			nhap<int>(s.battery);
			checkNegative(s.battery);
		}
		catch (string S) {
			cout << S << endl;
			kt = 0;
		}
		if (kt) break;
	}
	while (1) {
		int kt = 1;
		try {
			cout << "Screen: ";
			nhap<float>(s.screen);
			checkNegative(s.screen);
		}
		catch (string S) {
			cout << S << endl;
			kt = 0;
		}
		if (kt) break;
	}
	i.ignore();
	cout << "Color: "; getline(i,s.color);
	while (1) {
		int kt = 1;
		try {
			cout << "Cameras: ";
			nhap<int>(s.cameras);
			checkNegative(s.cameras);
		}
		catch (string S) {
			cout << S << endl;
			kt = 0;
		}
		if (kt) break;
	}
	i.ignore();
	cout << "Warranty: ";getline(i,s.warranty);
	cout << "Others: "; getline(i,s.others);
	return i;
}

