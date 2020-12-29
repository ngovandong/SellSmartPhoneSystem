#pragma once
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
class invoice;
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
	friend class LIST;
	friend ostream& operator<<(ostream&, const invoice&);
	smartphone(int=0,string= "", string = "",int=0,int=0,int=0,int=0,int=0,int=0,float=0, string = "",int=0, string = "", string = "");
	~smartphone();
	friend ostream& operator<<(ostream&, const smartphone&);
	friend istream& operator>>(istream&, smartphone&);
	int getPrice();
	int getSold();
	int getID();
	string getName();
	string getBrand();
};


template<class T>
inline void nhap(T& n) {
	cin >> n;
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		throw string("syntax error!");
	}
}

inline  void checkNegativeOrEqual0(int n) {
	if (n < 0)
		throw string("syntax error!");
}

inline void checkNegative(int n) {
	if (n <= 0) throw string("syntax error!");
}
inline void checkNegative(float n) {
	if (n <= 0) throw string("syntax error!");
}
template <class T>
inline void checkGreater(T t1, T t2) {
	if (t1 <= t2)
		throw string("syntax error!");
}