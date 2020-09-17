#pragma once
#include<string>
#include<iostream>
#include <fstream>

using namespace std;




class Calendar
{
protected:
	int dayResult = 0;
	int a = 0;
	int yearcalc = 0;
	int monthcalc = 0;
public:
	virtual void GetWeekday() = 0;
	virtual int GetDaysCount() = 0;
	virtual bool IsWeekend() = 0;
};

class GregorianCalendar :public Calendar

{
protected:
	int day;
	int month;
	int year;

public:

	GregorianCalendar(int day_, int month_, int year_);
	void GetWeekday() override;
	bool IsWeekend() override;
	int GetDaysCount() override;
	void GetProdCalendar();


};

class JulianCalendar :public Calendar
{
	int day;
	int month;
	int year;

public:

	JulianCalendar(int day_, int month_, int year_);
	void GetWeekday() override;
	bool IsWeekend() override;
	int GetDaysCount();
};


