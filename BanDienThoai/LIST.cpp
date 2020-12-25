#include "LIST.h"
#include <algorithm>


LIST* LIST::instance = 0;
LIST::LIST()
{
	vector<customer> CUS;
	vector<invoice_detail> DE;
	DBHelper::getInstance()->Select(this->SM);
	DBHelper::getInstance()->Select(DE);
	DBHelper::getInstance()->Select(CUS);
	DBHelper::getInstance()->Select(this->INV);
	for (int i = 0; i < DE.size(); i++)
		DE[i].setSmartphone(this->SM);
	for (int i = 0; i < this->INV.size(); i++) {
		this->INV[i].setCustomer(CUS);
		this->INV[i].setInvoiceDetail(DE);
	}
	CUS.clear();
	DE.clear();
}

LIST::~LIST()
{
	LIST::instance = 0;
	this->SM.clear();
	this->INV.clear();
}

LIST* LIST::getInstance()
{
	if (LIST::instance == 0)
		LIST::instance = new LIST();
	return LIST::instance;
}



void LIST::displaySmartphone(bool (*cmp)(int, int), int(*val)(smartphone))
{
	quicksort(this->SM, cmp, val, 0, this->SM.size() - 1); 
	for (int i = 0; i < this->SM.size(); i++) {
		cout << this->SM[i];
	}
}

void LIST::addSmartphone()
{
	smartphone a;
	cin >> a;
	string s = "INSERT INTO SMARTPHONE(smartphone_name,brand,price,qty,qty_sold,RAM,ROM,battery,screen,color,cameras,warranty,others) values('";
	s = s + a.smartphone_name + "','" + a.brand + "'," + to_string(a.price) + "," + to_string(a.qty) + ","
		+ to_string(a.qty_sold) + "," + to_string(a.RAM) + "," + to_string(a.ROM) + "," + to_string(a.battery)
		+ "," + to_string(a.screen) + ",'" + a.color + "'," + to_string(a.cameras) + ",'" + a.warranty + "','" + a.others + "')";
	DBHelper::getInstance()->UDI(s);
	this->SM.clear();
	DBHelper::getInstance()->Select(this->SM);
}

void LIST::DeleteSmartphone()
{
	int smartphone_id;
	cout << "Enter smartphone_id need delete: ";
	while (1) {
		int kt = 1;
		try {
			cout << "Price >=: ";
			nhap<int>(smartphone_id);
			this->findIDSmartphone(smartphone_id);
		}
		catch (string S) {
			cout << S << endl;
			kt = 0;
		}
		if (kt) break;
	}
	string s= "update SMARTPHONE set deleted=1 where smartphone_id= ";
	s += to_string(smartphone_id);
	DBHelper::getInstance()->UDI(s);
	this->SM.clear();
	DBHelper::getInstance()->Select(this->SM);
}

void LIST::updateSmartphone()
{
	int id;
	while (1) {
		int kt = 1;
		try {
			cout << "Enter smartphone_id need to update: ";
			nhap<int>(id);
			this->findIDSmartphone(id);
		}
		catch (string S) {
			cout << S << endl;
			kt = 0;
		}
		if (kt) break;
	}
	cin.ignore();
	smartphone a;
	cin >> a;
	string s = "UPDATE SMARTPHONE SET smartphone_name = '";
	s = s + a.smartphone_name + "', brand= '" + a.brand + "', price= " + to_string(a.price) + ", qty= " + to_string(a.qty)
		+ ", qty_sold= " + to_string(a.qty_sold) + ",RAM= " + to_string(a.RAM) + ",ROM= " + to_string(a.ROM)
		+ ",battery= " + to_string(a.battery) + ",screen= " + to_string(a.screen) + ",color= '" + a.color + "',cameras= "
		+ to_string(a.cameras) + ",warranty= '" + a.warranty + "', others= '" + a.others
		+ "' where smartphone_id= " + to_string(id);
	DBHelper::getInstance()->UDI(s);
	this->SM.clear();
	DBHelper::getInstance()->Select(this->SM);
}


void LIST::searchSmartphone(string(*val)(smartphone), string str)
{
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	for (int i = 0; i < this->SM.size(); i++) {
		string temp = val(this->SM[i]);
		transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
		size_t found = temp.find(str);
		if (found != string::npos)
			cout << this->SM[i];
	}
}

void LIST::displayInvoice()
{
	cout << "~~~~~~~~~~~~~~ALL INVOICE~~~~~~~~~~~~~"<< endl<<endl;
	for (int i = 0; i < this->INV.size(); i++) {
		cout << this->INV[i];
	}
}



void LIST::buy()
{
	string name, address, phone;
	cout << "Enter your infomaton: " << endl;
	cout << "Name: "; 
	cin.ignore();
	getline(cin, name);
	cout << "Phone: "; getline(cin, phone);
	cout << "Address: "; getline(cin, address);
	string s = "INSERT INTO CUSTOMER(customer_name,phonenumber,address) values('";
	s = s + name + "','" + phone + "','" + address + "')";
	DBHelper::getInstance()->UDI(s);
	int customer_id = DBHelper::getInstance()->selectID("select max(customer_id) from CUSTOMER");
	string s1 = "INSERT INTO INVOICE(date_buy,customer_id) values(getdate(),";
	s1 = s1 + to_string(customer_id) + ")";
	DBHelper::getInstance()->UDI(s1);
	int invoice_id = DBHelper::getInstance()->selectID("select max(invoice_id) from INVOICE");
	system("cls");
	this->displaySmartphone(increase, orderByID);
	string s2;
	int smartphone_id, qty;
	vector<invoice_detail> DE;
	while (true) {
		while (1) {
			int kt = 1;
			try {
				while (1) {
					int kt = 1;
					try {
						cout << "Enter smartphone_id need to buy: ";
						nhap<int>(smartphone_id);
					}
					catch (string S) {
						cout << S << endl;
						kt = 0;
					}
					if (kt) break;
				}
				this->findIDSmartphone(smartphone_id);
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
				nhap<int>(qty);
				checkNegative(qty);
			}
			catch (string S) {
				cout << S << endl;
				kt = 0;
			}
			if (kt) break;
		}
		bool k ;
		s2 = "exec  procupdatedata ";
		s2 = s2 + to_string(invoice_id) + ", " + to_string(smartphone_id) + ", " + to_string(qty);
		if (!DBHelper::getInstance()->UDI(s2))
			cout << "Out of stock! please choose another smartphone or enter lower quantity smartphone." << endl;
		while (1) {
			int kt = 1;
			try {
				cout << "Continue buy ? (if continue press 1, if finish press 0): ";
				nhap<bool>(k);
			}
			catch (string S) {
				cout << S << endl;
				kt = 0;
			}
			if (kt) break;
		}
		if (k==0) break;
	}
	this->~LIST();
	LIST::getInstance();
	DBHelper::getInstance()->UDI("delete from INVOICE where total=0 delete from CUSTOMER where customer_id not in (select customer_id from INVOICE");
}


void LIST::consult()
{
	string brand, color;
	int priceLow, priceUp, rom, ram, battery,cameras;
	float  screenLow, screenUp;
	cout << "Enter your need: " << endl;
	cout << "Band: "; 
	cin.ignore();
	getline(cin, brand);
	transform(brand.begin(), brand.end(), brand.begin(), ::tolower);
	while (1) {
		int kt = 1;
		try {
			cout << "Price >=: ";
			nhap<int>(priceLow);
			checkNegativeOrEqual0(priceLow);
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
			cout << "Price <=: ";
			nhap<int>(priceUp);
			checkNegative(priceUp);
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
			nhap<int>(rom);
			checkNegative(rom);
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
			nhap<int>(ram);
			checkNegative(ram);
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
			cout << "Battery >=: ";
			nhap<int>(battery);
			checkNegativeOrEqual0(battery);
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
			cout << "Screen >=: ";
			nhap<float>(screenLow);
			checkNegativeOrEqual0(screenLow);
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
			cout << "Screen <=: ";
			nhap<float>(screenUp);
			checkNegative(screenUp);
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
			cout << "Cameras: ";
			nhap<int>(cameras);
			checkNegative(cameras);
		}
		catch (string S) {
			cout << S << endl;
			kt = 0;
		}
		if (kt) break;
	}
	int n = this->SM.size();
	int* rank = new int[n];
	for (int i = 0; i < n; i++) {
		rank[i] = 0;
		string temp = this->SM[i].brand;
		transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
		if (brand.compare(temp)==0) rank[i]+=4;
		if (priceLow <= this->SM[i].price&&this->SM[i].price<=priceUp) rank[i]+=4;
		if (rom == this->SM[i].ROM) rank[i] ++;
		if (ram == this->SM[i].RAM) rank[i] ++;
		if (this->SM[i].battery >= battery) rank[i]++;
		if (screenLow <= this->SM[i].price && this->SM[i].price <= screenUp) rank[i]++;
		if (cameras == this->SM[i].cameras) rank[i] ++;
	}
	quicksort(this->SM, rank, 0, n - 1);
	for (int i = 0; i < 5; i++)
		cout << this->SM[i];
}

void LIST::findIDSmartphone(int id)
{
	bool k = true;
	for (int i = 0; i < this->SM.size(); i++)
		if (id == this->SM[i].smartphone_id) k=false;
	if(k)
		throw string("Does not have this smartphone!\n");
}








