/*
Kevin Lehman  - 1463553
Tarrant County College - COSC 1437- Fall 2017
Assignment 2 - Week 9
*/

#include<iostream>
using namespace std;

const int MAX_CHAR = 3;

class Date
{
private:
	int month;
	int day;
	int year;
public:
	bool setMonth(int);
	bool setDay(int);
	bool setYear(int);
	int getMonth();
	int getDay();
	int getYear();
	void displayYMD();
	Date();
};
class Time
{
private:
	int hour;
	int minute;
	int second;
	char ind[MAX_CHAR];
public:
	bool setHour(int);
	bool setMinute(int);
	bool setSecond(int);
	bool setInd(char[]);
	int getHour();
	int getMinute();
	int getSecond();
	char getInd();
	void displayFullTime();
	void displayMilitaryTime();
	Time();
};
Time::Time()
{
	hour = 0;
	minute = 0;
	second = 0;
	ind[0] = 'A';
	ind[1] = 'M';
}
bool Time::setHour(int h)
{
	if (h >= 0 && h <= 11)
	{
		hour = h;
		return true;
	}
	else
	{
		cout << "Please enter a valid hour." << endl;
		return false;
	}
}
bool Time::setMinute(int m)
{
	if (m >= 0 && m <= 59)
	{
		minute = m;
		return true;
	}
	else
	{
		cout << "Please enter a valid minutes value (0-59)." << endl;
		return false;
	}
}
bool Time::setSecond(int s)
{
	if (s >= 0 && s <= 59)
	{
		second = s;
		return true;
	}
	else
	{
		cout << "Please enter a valid seconds value (0-59)." << endl;
		return false;
	}
}
bool Time::setInd(char i[])
{
	if (i[0] == 'P' || i[0] == 'p')
	{
		ind[0] = 'P';
		ind[1] = 'M';
		return true;
	}
	else if (i[0] == 'A' || i[0] == 'a')
	{
		ind[0] = 'A';
		ind[1] = 'M';
		return true;
	}
	else
	{
		cout << "Please enter a valid indicator value (AM or PM)." << endl;
		return false;
	}
}
int Time::getHour()
{
	return hour;
}
int Time::getMinute()
{
	return minute;
}
int Time::getSecond()
{
	return second;
}
char Time::getInd()
{
	return ind[MAX_CHAR];
}



Date::Date()
{
	year = 1900;
	day = 1;
	month = 1;
}
bool Date::setMonth(int m)
{
	if (m >= 1 && m <= 12)
	{
		month = m;
		return true;
	}
	else
	{
		return  false;
	}
}
bool Date::setDay(int d)
{
	if (d >= 1 && d <= 31)
	{
		day = d;
		return true;
	}
	else
	{
		return false;
	}
}
bool Date::setYear(int y)
{
	if (y >= 1900 && y <= 2100)
	{
		year = y;
		return true;
	}
	else
	{
		return false;
	}
}
int Date::getMonth()
{
	return month;
}
int Date::getDay()
{
	return day;
}
int Date::getYear()
{
	return year;
}


int main()
{
	Date Birth;
	Time Wake;
	int locMonth;
	int locDay;
	int locYear;
	int locHour;
	int locMinute;
	int locSecond;
	char locInd[MAX_CHAR];
	bool flag = false;

	while (flag != true)
	{
		cout << "Please enter your birth month." << endl;
		cin >> locMonth;
		flag = Birth.setMonth(locMonth);
	}
	flag = false;
	while (flag != true)
	{
		cout << "Please enter your birth day." << endl;
		cin >> locDay;
		flag = Birth.setDay(locDay);
	}
	flag = false;
	while (flag != true)
	{
		cout << "Please enter your birth year." << endl;
		cin >> locYear;
		flag = Birth.setYear(locYear);
	}
	flag = false;
	while (flag != true)
	{
		cout << "Please enter your typical wake up hour." << endl;
		cin >> locHour;
		flag = Wake.setHour(locHour);
	}
	flag = false;
	while (flag != true)
	{
		cout << "Please enter your typical wake up minutes (2 digits only)." << endl;
		cin >> locMinute;
		flag = Wake.setMinute(locMinute);
	}
	flag = false;
	while (flag != true)
	{
		cout << "Please enter your typical wake up seconds (2 digits only)." << endl;
		cin >> locSecond;
		flag = Wake.setSecond(locSecond);
	}
	flag = false;
	while (flag != true)
	{
		cout << "Please enter your typical wake up indicator(AM or PM)." << endl;
		cin >> locInd;
		flag = Wake.setInd(locInd);
	}
	Birth.displayYMD();
	Wake.displayFullTime();
	Wake.displayMilitaryTime();

	system("PAUSE");
	return 0;
}

void Time::displayMilitaryTime()
{
	if (ind[0] == 'P' || ind[0] == 'p')
	{
		cout << "Your typical wake up military time is " << (hour + 12) << ":" << minute << "." << second << " " << "." << endl;
	}
	else
	{
		cout << "Your typical wake up military time is " << hour << ":" << minute << "." << second << "." << endl;
	}
}
void Time::displayFullTime()
{
	cout << "Your typical wake up time is " << hour << ":" << minute << "." << second << " " << ind[0] << ind[1] << "." << endl;
}
void Date::displayYMD()
{
	cout << "Your entered birth date is " << year << "/" << month << "/" << day << "." << endl;
}