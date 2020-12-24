#pragma once
#include"LIST.h"
class UI
{
	UI();
	~UI();
	static UI* instance;
public:
	static UI* getInstance();
	void perform();
	void cinInt(int&);
	void function1();
	void function2();
	void function3();
	void function4();
	void function5();
	void function6();
};





