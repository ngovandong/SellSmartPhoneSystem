#include "LIST.h"
#include <algorithm>
bool increase(int a, int b) {
	return a < b;
}
bool decrease(int a, int b) {
	return a > b;
}
int orderBySold(smartphone S) {
	return S.getSold();
}
int orderByPrice(smartphone S) {
	return S.getPrice();
}
int orderByID(smartphone S) {
	return S.getID();
}

void quicksort(vector<smartphone>& S, bool (*cmp)(int, int), int(*val)(smartphone), int L, int R)
{
	int pivot = val(S[L]);
	int i = L;
	int j = R;
	while (i <= j) {
		while (cmp(val(S[i]), pivot)) i++;
		while (cmp(pivot, val(S[j]))) j--;
		if (i <= j) {
			if (i < j)
				swap(S[i], S[j]);
			i++;
			j--;
		}
	}
	if (L < j)
		quicksort(S, cmp, val, L, j);
	if (R > i)
		quicksort(S, cmp, val, i, R);
}


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

void LIST::displaySmartphone()
{
	quicksort(this->SM, increase, orderByID, 0, this->SM.size() - 1); 
	for (int i = 0; i < this->SM.size(); i++)
		cout << this->SM[i];
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

void LIST::searchSmartphone(string str)
{
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	for (int i = 0; i < this->SM.size(); i++) {
		string temp = this->SM[i].smartphone_name;
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
	cout << "Name: "; getline(cin, name);
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
	this->INV.clear();
	DBHelper::getInstance()->Select(this->INV);
	this->displaySmartphone();
	string s2 = "  exec  procupdatedata ";
	int smartphone_id, qty;
	while (true) {
		cout << "\nChoose smartphone_id you need to buy: ";
		cin >> smartphone_id;
		cout << "Quantity: ";
		cin >> qty;
		int k = 1;
		s2 = s2 + to_string(this->INV[this->INV.size()-1].invoice_id) + ", " + to_string(smartphone_id) + ", " + to_string(qty);
		cout << "Continue buy ? (if continue press 1, if stop press 0): ";
		cin >> k;
		if (!k) break;
		s2 += "  exec  procupdatedata ";
	}
	DBHelper::getInstance()->UDI(s2);
	this->DE.clear();
	DBHelper::getInstance()->Select(this->DE);
}








