#pragma once

#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#include<stdlib.h>
#include "smartphone.h"
#include "invoice.h"
#include "customer.h"
#include "invoice_detail.h"
#include <vector>
class DBHelper
{
#define SQL_RESULT_LEN 240
#define SQL_RETURN_CODE_LEN 1024
	//define handles and variables
	SQLHANDLE sqlConnHandle;
	SQLHANDLE sqlStmtHandle;
	SQLHANDLE sqlEnvHandle;
	SQLWCHAR retconstring[SQL_RETURN_CODE_LEN];

public:
	void init();
	void Insert();
	void Select(vector<smartphone>);
	void Select(vector<invoice>);
	void Select(vector<customer>);
	void Select(vector<invoice_detail>);
	void Update();
	void Delete();
	void close();
};

