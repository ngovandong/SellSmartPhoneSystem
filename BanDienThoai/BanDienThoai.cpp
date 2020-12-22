#pragma once
#include <iostream>
#include "UI.h"
using namespace std;

int main()
{
	UI::getInstance()->perform();
	system("pause");
}
