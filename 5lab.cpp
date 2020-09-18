#include <iostream>
#include <fstream>
#include "Date.h"
using namespace std;

void InputDate(int& day, int& month, int& year);

int main()
{
	setlocale(LC_ALL, "rus");
	int day;
	int month;
	int year;



	InputDate(day, month, year);

	GregorianCalendar gCalendar(day, month, year);

	gCalendar.GetProdCalendar();

	return 0;
}



void InputDate(int& day, int& month, int& year)

{
	cout << "Введите дату\n";
	cout << "День: ";	cin >> day;
	cout << "Месяц: ";  cin >> month;
	cout << "Год: ";	cin >> year;
}
