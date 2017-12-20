#include "string"
#include "iostream"
using namespace std;
class Date {


public:
	int day, month, year;
	enum weekday { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday  };
	enum month { January, February, March, April, May, June, July, August, September, Oktober, November, December };
	string DayOfWeek(int dayOfWeek) {

		switch (dayOfWeek) {
		case Sunday:   return "Sunday";
		case Monday:   return"Monday";
		case Tuesday: return "Tuesday";
		case Wednesday: return "Wednesday";
		case Thursday:  return "Thursday";
		case Friday:    return "Friday";
		case Saturday:  return"Saturday";
		default:        return "invalid Date";
		}
		return "";
	}
	string Month(int month) {

		switch (month) {
		case January:   return "january";
		case February:   return"february";
		case March: return "march";
		case April: return "april";
		case May:  return "may";
		case June:    return "june";
		case July:  return"july";
		case August:  return"august";
		case September:  return"september";
		case Oktober:  return"oktober";
		case November:  return"november";
		case December:  return"december";
		default:        return "invalid Date";
		}
		return "";
	}
	Date(int d = 1, int m = 1, int y = 1970) {
		if (y < 1970)
			throw string("data must be later than 1.1.1970");
		if (m<1 || m>12)
			throw string("1 < month < 12");
		if (d<1 || d>31)
			throw string("1 < day < 31");
		day = d;
		month = m;
		year = y;

	}
	bool isLeap(int year) {
		if (year % 4 == 0 || year % 100 == 0 || year % 400 == 0)
			return true;
		return false;
	}
	int monthLength(int year, int month) {
		if (!isLeap(year) && month == 2)
			return 28;
		else
			return 28 + (month + month / 8) % 2 + 2 % month + 2 / month;
	}
	int dayOfYear(Date date) {
		int numberOfDays = 0;
		for (int i = 1; i<date.month; i++)
		{

			numberOfDays += monthLength(date.year, i);

		}
		return  numberOfDays += date.day;

	}
	int daysBetween(Date date1, Date date2) {
		int dif = dayOfYear(date2) - dayOfYear(date1);
		if (dif<0)
			return -1;
		return dif + 365 * (date2.year - date1.year) + (date2.year - date1.year) / 4;
	}
	int operator-(Date w) {

		int dif = dayOfYear(*this) - dayOfYear(w);
		if (dif<0)
			return -1;
		for (int i = 0; i < (this->year - w.year); ++i) {
			if (isLeap(w.year + i))
				dif += 366;
			else
				dif += 365;
		}
		return dif;
	}
};
int main()
{
	try {
		Date q(13, 3, 2016);
		Date w(1, 1, 1970);
		int qq = q - w;
		cout << q.day << " " << q.Month(q.month) << " " << q.year << " - " << q.DayOfWeek(qq % 7 + 3) << " - " << qq << " days since 1st January 1970" << endl;
	}
	catch (string s)
	{
		cout << "exeption: " << s << endl;
	}
	return 0;
}
