#include "Date.h"
#include "DT.h"
using namespace std;


GregorianCalendar::GregorianCalendar(int day_, int month_, int year_)
	: day(day_), month(month_), year(year_)
{

	DateTime dt;
	bool isDateCorrect = dt.checkDate(year, month, day);
	if (!isDateCorrect) {
		cout << "Дата не верна!" << endl;
		exit(1);
	}
}
void  GregorianCalendar::GetWeekday()
{
	a = (14 - month) / 12;
	yearcalc = year - a;
	monthcalc = month + (12 * a) - 2;
	dayResult = (day + (31 * monthcalc) / 12 + yearcalc + yearcalc / 4 - yearcalc / 100 + yearcalc / 400) % 7;
	string dayString;
	switch (dayResult) {
	case 0:
		dayString = "Воскресенье";
		cout << dayString << endl;
		break;
	case 1:
		dayString = "Понедельник";
		cout << dayString << endl;
		break;
	case 2:
		dayString = "Вторник";
		cout << dayString << endl;
		break;
	case 3:
		dayString = "Среда";
		cout << dayString << endl;
		break;
	case 4:
		dayString = "Четверг";
		cout << dayString << endl;
		break;
	case 5:
		dayString = "Пятница";
		cout << dayString << endl;
		break;
	case 6:
		dayString = "Суббота";
		cout << dayString << endl;
		break;
	default:
		cout << "Error";
		break;
	}
}
int GregorianCalendar::GetDaysCount()
{
	{
		switch (month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
			break;
		case 2:
			if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
				return 29;
			else
				return 28;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
			break;
		}
	}
}
bool GregorianCalendar::IsWeekend()
{
	if (dayResult == 6 || dayResult == 0 || (day == 31 && month == 12) || (day == 8 && month == 3) || (day == 23 && month == 2) || (day == 9 && month == 5) || (day == 1 && month == 5))
		return true;
	else
		return false;
}

JulianCalendar::JulianCalendar(int day_, int month_, int year_)
	: day(day_), month(month_), year(year_)
{
	DateTime dt;
	bool isDateCorrect = dt.checkDate(year, month, day);
	if (!isDateCorrect) {
		cout << "Дата не верна!" << endl;
		exit(1);
	}
}
void JulianCalendar::GetWeekday()
{
	a = (14 - month) / 12;
	yearcalc = year - a + 4800;
	monthcalc = month + (12 * a) - 3;
	dayResult = (day + 153 * monthcalc + 2 / 5 + 365 * yearcalc + yearcalc / 4 - 32083) % 7;
	string dayString;

	switch (dayResult) {
	case 6:
		dayString = "Воскресенье";
		cout << dayString << endl;
		break;
	case 0:
		dayString = "Понедельник";
		cout << dayString << endl;
		break;
	case 1:
		dayString = "Вторник";
		cout << dayString << endl;
		break;
	case 2:
		dayString = "Среда";
		cout << dayString << endl;
		break;
	case 3:
		dayString = "Четверг";
		cout << dayString << endl;
		break;
	case 4:
		dayString = "Пятница";
		cout << dayString << endl;
		break;
	case 5:
		dayString = "Суббота";
		cout << dayString << endl;
		break;
	default:
		cout << "Error";
		break;
	}
}
int JulianCalendar::GetDaysCount()
{
	{
		switch (month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
			break;
		case 2:
			if (year % 4 == 0)
				return 29;
			else
				return 28;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
			break;
		}
	}
}
bool JulianCalendar::IsWeekend()
{
	if (dayResult == 6 || dayResult == 5 || (day == 31 && month == 12) || (day == 8 && month == 3) || (day == 23 && month == 2) || (day == 9 && month == 5) || (day == 1 && month == 5))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void GregorianCalendar::GetProdCalendar()
{
	cout << "Производственный календарь на этот месяц:" << endl;
	string path = "data.txt";
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
	{
		cout << "Error" << endl;
	}
	else
	{
		string str;
		string buf;
		char stop = '\"';
		int mmonth;
		if (year > 2025 || year < 1999)
		{
			cout << "Отсутствует в реестре" << endl;
		}
		{
			string ye = to_string(year);
			char buffer[5] = "1999";
			fin.get(buffer, 5);
			while (true)
			{
				bool is_year = ye == buffer;
				if (is_year)
				{
					for (mmonth = 2 * (month); mmonth > 0; mmonth--)
					{
						getline(fin, str, stop);
					}
					cout << str << endl;
					break;
				}
				else
				{
					getline(fin, str);
					fin.get(buffer, 5);
				}

			}

			fin.close();

		}
	}
}