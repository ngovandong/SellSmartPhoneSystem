#include "UI.h"
UI* UI::instance = 0;
UI::UI()
{
}
UI::~UI()
{
}

UI* UI::getInstance()
{
	if (UI::instance == 0)
		UI::instance = new UI();
	return UI::instance;
}

void UI::perform()
{
    int out = 1;
    while (out) {
        int chon;
        system("cls");
        cout << "All funtion:\n";
        cout << "1.Search smartphone\n";
        cout << "2.Display smartphone\n";
        cout << "3.Consult\n";
        cout << "4.Buy smartphone\n";
        cout << "5.Update inventory\n";
        cout << "6.Display invoice\n";
        cout << "7.Exit\n";
        while (1) {
            int kt = 1;
            try {
                cout << "Choose function: ";
                nhap<int>(chon);
            }
            catch (string S) {
                cout << S << endl;
                kt = 0;
            }
            if (kt) break;
        }
        system("cls");
        switch (chon)
        {
        case 1:
            this->function1();
            break;
        case 2:
            this->function2();
            break;
        case 3:
            this->function3();
            break;
        case 4:
            this->function4();
            break;
        case 5:
            this->function5();
            break;
        case 6:
            this->function6();
            break;
        case 7:
            out = 0;
            break;
        default:
            cout << "Does not this function!" << endl;
            system("pause");
            break;
        }
    }
}




void UI::function1()
{
    cout << "Search for:" << endl;
    cout << "1.Name" << endl;
    cout << "2.Brand" << endl;
    int chon;
    string s1, s2;
    while (1) {
        int kt = 1;
        try {
            cout << "Choose function: ";
            nhap<int>(chon);
        }
        catch (string S) {
            cout << S << endl;
            kt = 0;
        }
        if (kt) break;
    }
    system("cls");
    switch (chon)
    {
    case 1:
    {
        string s1;
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, s1);
        LIST::getInstance()->searchSmartphone(searchName, s1);
        break;
    }
    case 2:
    {
        string s2;
        cout << "Enter brand: ";
        cin.ignore();
        getline(cin, s2);
        LIST::getInstance()->searchSmartphone(searchBrand, s2);
        break;
    }
    default:
        cout << "Does not have this funtion!" << endl;
        break;
    }
    system("pause");
}



void UI::function2()
{
    cout << "Order by:" << endl;
    cout << "1.Increase price" << endl;
    cout << "2.Decrease price" << endl;
    cout << "3.Increase sold" << endl;
    cout << "4.Decrease sold" << endl;
    cout << "5.Lastest" << endl;
    cout << "6.Oldest" << endl;
    
    int chon;
    while (1) {
        int kt = 1;
        try {
            cout << "Choose function: ";
            nhap<int>(chon);
        }
        catch (string S) {
            cout << S << endl;
            kt = 0;
        }
        if (kt) break;
    }
    system("cls");
    switch (chon)
    {
    case 1:
    {
        LIST::getInstance()->displaySmartphone(increase,orderByPrice);
        break;
    }
    case 2:
    {
        LIST::getInstance()->displaySmartphone(decrease, orderByPrice);
        break;
    }
    case 3:
    {
        LIST::getInstance()->displaySmartphone(increase, orderBySold);
        break;
    }
    case 4:
    {
        LIST::getInstance()->displaySmartphone(decrease, orderBySold);
        break;
    }
    case 5:
    {
        LIST::getInstance()->displaySmartphone(decrease, orderByID);
        break;
    }
    case 6:
    {
        LIST::getInstance()->displaySmartphone(increase, orderByID);
        break;
    }
    default:
        cout << "Does not have this funtion!" << endl;
        break;
    }
    system("pause");
}

void UI::function3()
{
    LIST::getInstance()->consult();
    system("pause");
}

void UI::function4()
{
    LIST::getInstance()->buy();
}

void UI::function5()
{
    cout << "Function:" << endl;
    cout << "1.Insert smartphone" << endl;
    cout << "2.Delete smartphone" << endl;
    cout << "3.Update smartphone" << endl;
    int chon;
    while (1) {
        int kt = 1;
        try {
            cout << "Choose function: ";
            nhap<int>(chon);
        }
        catch (string S) {
            cout << S << endl;
            kt = 0;
        }
        if (kt) break;
    }
    system("cls");
    switch (chon)
    {
    case 1:
    {
        LIST::getInstance()->addSmartphone();
        break;
    }
    case 2:
    {
        LIST::getInstance()->DeleteSmartphone();
        break;
    }
    case 3:
    {
        LIST::getInstance()->updateSmartphone();
        break;
    }
    default:
        cout << "Does not have this funtion!" << endl;
        break;
    }
    system("pause");
}

void UI::function6()
{
    LIST::getInstance()->displayInvoice();
    system("pause");
}
