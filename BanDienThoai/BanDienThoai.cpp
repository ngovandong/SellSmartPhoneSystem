#pragma once
#include <iostream>
#include "DBHelper.h"
#include "LIST.h"
using namespace std;


int main()
{
	LIST::getInstance()->displaySmartphone();
	system("pause");
}

