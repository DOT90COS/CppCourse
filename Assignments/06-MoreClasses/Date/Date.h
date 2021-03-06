#pragma once
#include <iostream>
#include <string>
#include <map>

class Day
{
    int day_;
    static bool verifyDay(int d);
public:
    explicit Day(int d = 1);
    int getDay() const;
    void setDay(int d);
};

std::ostream& operator<<(std::ostream& os, const Day& day);

class Month
{
    int month_;
    static const std::map<int, std::string> monthNames_;
    static const std::map<int, int> monthDays_;

    static bool verifyMonth(int m);

public:
    explicit Month(int m = 1);
    int getMonth() const;
    std::string str() const;
    int daysInMonth() const;
    void setMonth(int m);
};

std::ostream& operator<<(std::ostream& os, const Month& month);

class Year {
    int year_;

public:
    explicit Year(int y = 2016);
    int getYear() const;
    void setYear(int y);
};

std::ostream& operator<<(std::ostream& os, const Year& year);

class Date
{
    Day d_;
    Month m_;
    Year y_;

public:
    Date(const Day& d, const Month& m, const Year& y);
    int getDay() const;
    int getMonth() const; 
    int getYear() const;
    void setDay(const Day& d);
    void setMonth(const Month& m);
    void setYear(const Year& y);
};

std::ostream& operator<<(std::ostream& os, const Date& year);


//Finds the number of days between
int operator-(const Date& date1, const Date& date2);