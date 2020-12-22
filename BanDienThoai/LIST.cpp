#include "LIST.h"
#include <algorithm>


LIST* LIST::instance = 0;
LIST::LIST()
{
	DBHelper::getInstance()->Select(this->SM);
	DBHelper::getInstance()->Select(this->CUS);
	DBHelper::getInstance()->Select(this->INV);
	DBHelper::getInstance()->Select(this->DE);
}

LIST::~LIST()
{
	this->SM.clear();
	this->CUS.clear();
	this->INV.clear();
	this->DE.clear();
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
	cin >> smartphone_id;
	string s= "update SMARTPHONE set deleted=1 where smartphone_id= ";
	s += to_string(smartphone_id);
	DBHelper::getInstance()->UDI(s);
	this->SM.clear();
	DBHelper::getInstance()->Select(this->SM);
}

void LIST::updateSmartphone()
{
	int id;
	cout << "Enter smartphone_id need to update: ";
	cin >> id;
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


customer* LIST::getCustomer(int ID)
{
	for (int i = 0; i < this->CUS.size(); i++)
		if (this->CUS[i].customer_id == ID)
			return &this->CUS[i];
	return nullptr;
}

smartphone* LIST::getSmartphone(int ID)
{
	for (int i = 0; i < this->SM.size(); i++)
		if (this->SM[i].smartphone_id == ID)
			return &this->SM[i];
	return nullptr;
}

vector<invoice_detail*> LIST::getInvoiceDetail(int ID)
{
	vector<invoice_detail*> D;
	for (int i = 0; i < this->DE.size(); i++)
		if (this->DE[i].invoice_id == ID)
			D.push_back( &this->DE[i]);
	return D;
}

void LIST::hoadon()
{
	cout << "~~~~~~~~~~~~~~ALL INVOICE~~~~~~~~~~~~~" << endl << endl;
	for (int i = 0; i < this->INV.size(); i++) {
		cout << this->INV[i];
		cout << "~Bill to:" << endl;
		cout <<* this->getCustomer(this->INV[i].customer_id);
		cout << "~Detail: " << endl;
		vector<invoice_detail*> D = this->getInvoiceDetail(this->INV[i].invoice_id);
		for (int j = 0; j < D.size(); j++) {
			cout << "Name: " << this->getSmartphone(D[j]->smartphone_id)->smartphone_name << endl;
			cout << "Quantity: " << D[j]->qty<<endl;
			cout << "Unit price: " << D[j]->unit_price << endl;
		}
		cout << "************************************" << endl;
	}
}

void LIST::displayInvoice()
{
	cout << "~~~~~~~~~~~~~~ALL INVOICE~~~~~~~~~~~~~"<< endl<<endl;
	for (int i = 0; i < this->INV.size(); i++) {
		cout <<"~"<< this->INV[i];
		for (int j = 0; j < this->CUS.size(); j++) {
			if (this->INV[i].customer_id == this->CUS[j].customer_id) {
				cout << "~Bill to: " << endl;
				cout << this->CUS[j];
			}
		}
		cout << "~Invoice detail: " << endl;
		for (int j = 0; j < this->DE.size(); j++) {
			if (this->INV[i].invoice_id == this->DE[j].invoice_id) {
				for (int k = 0; k < this->SM.size(); k++) {
					if (this->DE[j].smartphone_id == this->SM[k].smartphone_id) {
						cout << "Smartphone name: " << this->SM[k].smartphone_name << endl;
						cout << "Quantity: " << this->DE[j].qty << endl;
						cout << "Unit price: " << this->DE[j].unit_price << endl;
					}
				}
			}
		}
		cout << "************************************" << endl;
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
	this->CUS.clear();
	DBHelper::getInstance()->Select(this->CUS);
	string s1 = "INSERT INTO INVOICE(date_buy,customer_id) values(getdate(),";
	s1 = s1 + to_string(this->CUS[this->CUS.size()-1].customer_id) + ")";
	DBHelper::getInstance()->UDI(s1);
	system("cls");
	this->INV.clear();
	DBHelper::getInstance()->Select(this->INV);
	for (int i = 0; i < this->SM.size(); i++) {
		cout << this->SM[i];
	}
	string s2 = "  exec  procupdatedata ";
	int smartphone_id, qty;
	while (true) {
		cout << "\nChoose smartphone_id you need to buy: ";
		cin >> smartphone_id;
		cout << "Quantity: ";
		cin >> qty;
		int k ;
		s2 = s2 + to_string(this->INV[this->INV.size()-1].invoice_id) + ", " + to_string(smartphone_id) + ", " + to_string(qty);
		cout << "Continue buy ? (if continue press 1, if finish press 0): ";
		cin >> k;
		if (k==0) break;
		s2 += "  exec  procupdatedata ";
	}
	DBHelper::getInstance()->UDI(s2);
	this->DE.clear();
	DBHelper::getInstance()->Select(this->DE);
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
	cout << "Price >=: "; cin >> priceLow;
	cout << "Price <=: "; cin >> priceUp;
	cout << "ROM: "; cin >> rom;
	cout << "RAM: "; cin >> ram;
	cout << "Battery >=: "; cin >> battery;
	cout << "Screen >=: "; cin>>screenLow;
	cout << "Screen <=: "; cin>>screenUp;
	cout << "Cameras: "; cin >> cameras;
	int n = this->SM.size();
	int* rank = new int[n];
	for (int i = 0; i < n; i++) {
		rank[i] = 0;
		if (brand.compare(this->SM[i].brand)==0) rank[i]+=4;
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








