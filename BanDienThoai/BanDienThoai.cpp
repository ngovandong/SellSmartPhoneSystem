#pragma once
#include <iostream>
#include "DBHelper.h"
using namespace std;
int main()
{
    vector<invoice_detail> S;
    DBHelper d;
    d.Select(S);
}

