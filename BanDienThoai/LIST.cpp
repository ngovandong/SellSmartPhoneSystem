#include "LIST.h"

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
	DBHelper::getInstance()->init();
	DBHelper::getInstance()->Select(this->SM);
	DBHelper::getInstance()->Select(this->CUS);
	DBHelper::getInstance()->Select(this->INV);
	DBHelper::getInstance()->Select(this->DE);
	DBHelper::getInstance()->close();
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
	quicksort(this->SM, decrease, orderByID, 0, this->SM.size() - 1); 
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
}

void LIST::DeleteSmartphone()
{
	int smartphone_id;
	cout << "Enter smartphone_id need delete: ";
	cin >> smartphone_id;
	string s= "update SMARTPHONE set deleted=1 where smartphone_id= ";
	s += to_string(smartphone_id);
	DBHelper::getInstance()->UDI(s);
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
}








