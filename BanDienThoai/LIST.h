#pragma once
#include "DBHelper.h"
#include <vector>
#include <string>
class LIST
{
	vector<smartphone> SM;
	vector<smartphone> SMD;
	vector<invoice> INV;
	LIST();
	~LIST();
	static LIST* instance; //singleton
public:
	static LIST* getInstance();
	void displaySmartphone(bool (*cmp)(int, int), int(*val)(smartphone));
	void addSmartphone();
	void DeleteSmartphone();
	void updateSmartphone();
	void searchSmartphone(string(*val)(smartphone),string);
	void displayInvoice();
	void buy();
	void consult();
	void findIDSmartphone(int);
};


inline bool increase(int a, int b) {
	return a < b;
}
inline bool decrease(int a, int b) {
	return a > b;
}
inline int orderBySold(smartphone S) {
	return S.getSold();
}
inline int orderByPrice(smartphone S) {
	return S.getPrice();
}
inline int orderByID(smartphone S) {
	return S.getID();
}

inline string searchName(smartphone s) {
	return s.getName();
}
inline string searchBrand(smartphone s) {
	return s.getBrand();
}

inline void quicksort(vector<smartphone>& S, bool (*cmp)(int, int), int(*val)(smartphone), int L, int R)
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


inline void quicksort(vector<smartphone>& S, int* rank, int L, int R)
{
	int pivot = rank[L];
	int i = L;
	int j = R;
	while (i <= j) {
		while (rank[i] > pivot) i++;
		while (rank[j] < pivot) j--;
		if (i <= j) {
			if (i < j) {
				swap(S[i], S[j]);
				swap(rank[i], rank[j]);
			}
			i++;
			j--;
		}
	}
	if (L < j)
		quicksort(S, rank, L, j);
	if (R > i)
		quicksort(S, rank, i, R);
}