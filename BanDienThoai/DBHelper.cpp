#include "DBHelper.h"
#include <iostream>
#include<iomanip>
#include<conio.h>
#include<string.h>
using namespace std;
void DBHelper::init()
{
	//initializations
	sqlConnHandle = NULL;
	sqlStmtHandle = NULL;
	//allocations
	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlEnvHandle))
		close();

	if (SQL_SUCCESS != SQLSetEnvAttr(sqlEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
		close();

	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, sqlEnvHandle, &sqlConnHandle))
		close();

	//output
	cout << "Attempting connection to SQL Server...";
	cout << "\n";
	switch (SQLDriverConnect(sqlConnHandle, NULL,(SQLWCHAR*)L"DRIVER={SQL Server};SERVER=localhost, 1433;DATABASE=vandong;trusted = true;",
		
		SQL_NTS,
		retconstring,
		1024,
		NULL,
		SQL_DRIVER_NOPROMPT)) {

	case SQL_SUCCESS:
		cout << "Successfully connected to SQL Server";
		cout << "\n";
		break;

	case SQL_SUCCESS_WITH_INFO:
		cout << "Successfully connected to SQL Server";
		cout << "\n";
		break;

	case SQL_INVALID_HANDLE:
		cout << "Could not connect to SQL Server";
		cout << "\n";
		close();
		break;

	case SQL_ERROR:
		cout << "Could not connect to SQL Server";
		cout << "\n";
		close();
		break;

	default:
		break;
	}
	//if there is a problem connecting then exit application
	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle))
		close();
}


void DBHelper::Insert()
{
	
	/*string s = "INSERT INTO Student VALUES('102180111',";
	string s1 = "'Quan',";
	string s2 = "'6')";

	s = s + s1 + s2;*/
	//int M = 50;

	/*char m[50];
	for (int i = 0; i < 50; i++)
	{
		m[i] = s[i];
		cout << m[i];
	}*/
	//cout << m;
	char m[] = "INSERT INTO Student VALUES('102180116','Quan','9')";

	if (SQL_SUCCESS != SQLExecDirectA(sqlStmtHandle,(SQLCHAR*)m , SQL_NTS)) {

		cout << "\n";
		cout << "Error querying SQL Server";
		cout << "\n";
		close();
	}
	else {

		cout << "\nINSERT SUCCESS";
		return;
	}
}

void DBHelper::Select(vector<smartphone> S)
{
	init();
	//if there is a problem executing the query then exit application
	//else display query result
	if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"SELECT * FROM SMARTPHONE where deleted= 0 ", SQL_NTS)) {
		cout << "Error querying SQL Server";
		cout << "\n";
		close();
	}
	else {
		//declare output variable and pointer
		SQLINTEGER ptrSqlVersion;
		int smartphone_id;
		char smartphone_name[50];
		char brand[20];
		int	price;
		int qty;
		int qty_sold;
		int RAM;
		int ROM;
		int battery;
		float screen;
		char color[20];
		int cameras;
		char warranty[20];
		char others[100];
		int i = 0;
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {
			SQLGetData(sqlStmtHandle, 1, SQL_INTEGER, &smartphone_id, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 2, SQL_CHAR, smartphone_name, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 3, SQL_CHAR, brand, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 4, SQL_INTEGER, &price, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 5, SQL_INTEGER, &qty, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 6, SQL_INTEGER, &qty_sold, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 7, SQL_INTEGER, &RAM, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 8, SQL_INTEGER, &ROM, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 9, SQL_INTEGER, &battery, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 10, SQL_C_FLOAT, &screen, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 11, SQL_CHAR, color, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 12, SQL_INTEGER, &cameras, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 13, SQL_CHAR, warranty, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 14, SQL_CHAR, others, SQL_RESULT_LEN, &ptrSqlVersion);


			//display query result
			smartphone* Sm = new smartphone(smartphone_id, smartphone_name, brand, price,
				qty, qty_sold, RAM, ROM, battery, screen, color, cameras, warranty, others);
			S.push_back(*Sm);
			cout << S[i];
			i++;
		}
	}
	SQLCancel(sqlStmtHandle);
	close();
}

void DBHelper::Select(vector<customer> S) {
	init();
	//if there is a problem executing the query then exit application
	//else display query result
	if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"SELECT * FROM CUSTOMER", SQL_NTS)) {
		cout << "Error querying SQL Server";
		cout << "\n";
		close();
	}
	else {
		//declare output variable and pointer
		SQLINTEGER ptrSqlVersion;
		int customer_id;
		char customer_name[30];
		char phonenumber[20];
		char address[60];
		int i = 0;
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {
			SQLGetData(sqlStmtHandle, 1, SQL_INTEGER, &customer_id, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 2, SQL_CHAR, customer_name, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 3, SQL_CHAR, phonenumber, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 4, SQL_CHAR, address, SQL_RESULT_LEN, &ptrSqlVersion);
			//display query result
			customer* Sm = new customer(customer_id, customer_name, phonenumber, address);
			S.push_back(*Sm);
			cout << S[i];
			i++;
		}
	}
	SQLCancel(sqlStmtHandle);
	close();
}

void DBHelper::Select(vector<invoice> S) {
	init();
	//if there is a problem executing the query then exit application
	//else display query result
	if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"SELECT * FROM INVOICE", SQL_NTS)) {
		cout << "Error querying SQL Server";
		cout << "\n";
		close();
	}
	else {
		//declare output variable and pointer
		SQLINTEGER ptrSqlVersion;
		int invoice_id;
		int customer_id;
		char datebuy[20];
		int total;
		int i = 0;
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {
			SQLGetData(sqlStmtHandle, 1, SQL_INTEGER, &invoice_id, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 2, SQL_INTEGER, &customer_id, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 3, SQL_CHAR, datebuy, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 4, SQL_INTEGER, &total, 1, &ptrSqlVersion);


			//display query result
			invoice* Sm = new invoice(invoice_id, customer_id, datebuy, total);
			S.push_back(*Sm);
			cout << S[i];
			i++;
		}
	}
	SQLCancel(sqlStmtHandle);
	close();
}

void DBHelper::Select(vector<invoice_detail> S) {
	init();
	//if there is a problem executing the query then exit application
	//else display query result
	if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"SELECT * FROM INVOICE_DETAIL", SQL_NTS)) {
		cout << "Error querying SQL Server";
		cout << "\n";
		close();
	}
	else {
		//declare output variable and pointer
		SQLINTEGER ptrSqlVersion;
		int invoice_id;
		int smartphone_id;
		int qty;
		int unit_price;
		int i = 0;
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {
			SQLGetData(sqlStmtHandle, 1, SQL_INTEGER, &invoice_id, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 2, SQL_INTEGER, &smartphone_id, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 3, SQL_INTEGER, &qty, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 4, SQL_INTEGER, &unit_price, 1, &ptrSqlVersion);


			//display query result
			invoice_detail* Sm = new invoice_detail(invoice_id, smartphone_id, qty, unit_price);
			S.push_back(*Sm);
			cout << S[i];
			i++;
		}
	}
	SQLCancel(sqlStmtHandle);
	close();
}

void DBHelper::Update()
{
	if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"UPDATE Student SET Id = '102180100' where Id = '102180137'", SQL_NTS)) {
		cout << "\n";
		cout << "Error querying SQL Server";
		cout << "\n";
		close();
	}
	else {

		cout << "\nUPDATE SUCCESS";
		return;
	}
}
void DBHelper::Delete()
{
	if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"DELETE from Student where Id = '102180138'", SQL_NTS)) {
		cout << "\n";
		cout << "Error querying SQL Server";
		cout << "\n";
		close();
	}
	else {

		cout << "\nDELETE SUCCESS";
		return;
	}
}
void DBHelper::close()
{
	SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
	SQLDisconnect(sqlConnHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, sqlConnHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, sqlEnvHandle);
	system("pause");
	exit(0);
}

//SQLCHAR							SalesPerson[11];
//SQLINTEGER				SalesPersonLenOrInd, CustIDInd;
//SQLUINTEGER			CustID;
////	Bind	SalesPerson	to	the	parameter	for	the	SalesPerson	column	and
////	CustID	to	the	parameter	for	the	CustID	column.
//SQLBindParameter(hstmt1, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 10, 0, SalesPerson, sizeof(SalesPerson), &SalesPersonLenOrInd);
//SQLBindParameter(hstmt1, 2, SQL_PARAM_INPUT, SQL_C_ULONG, SQL_INTEGER, 10, 0, 	&CustID, 0, &CustIDInd);
////	Set	values	of	salesperson	and	customer	ID	and	length/indicators.
//strcpy_s((char*)SalesPerson, _countof(SalesPerson), "Garcia");
//SalesPersonLenOrInd = SQL_NTS;
//CustID = 1331;
//CustIDInd = 0;
////	Execute	a	statement	to	get	data	for	all	orders	made	to	the	specified
////	customer	by	the	specified	salesperson.
//SQLExecDirect(hstmt1, "SELECT	*	FROM	Orders	WHERE	SalesPerson=?	AND	CustID=?", SQL_NTS);
////	Prepare	the	procedure	invocation	statement.
//SQLPrepare(hstmt, "{call	test(?)}", SQL_NTS);
////	Populate	record	1	of	ipd.
//SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR,
//	30, 0, szQuote, 0, &cbValue);
////	Get	ipd	handle	and	set	the	SQL_DESC_NAMED	and	SQL_DESC_UNNAMED	fields
////	for	record	#1.
//SQLGetStmtAttr(hstmt, SQL_ATTR_IMP_PARAM_DESC, &hIpd, 0, 0);
//SQLSetDescField(hIpd, 1, SQL_DESC_NAME, "@quote", SQL_NTS);
////	Assuming	that	szQuote	has	been	appropriately	initialized,
////	execute.
//SQLExecute(hstmt);
