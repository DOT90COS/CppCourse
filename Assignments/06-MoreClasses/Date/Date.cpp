#include "Date.h"


///////// DAY
bool Day::verifyDay(int d)
{
    return d > 0 && d <= 31;
}

Day::Day(int d)
{
    day_ = verifyDay(d) ? d : 1;
}

int Day::getDay() const
{
    return day_;
}

void Day::setDay(int d)
{
    day_ = verifyDay(d) ? d : 1;
}

std::ostream& operator<<(std::ostream& os, const Day& day)
{
    os << day.getDay();
    return os;
}


//////////////////// Month
const std::map<int, std::string> Month::monthNames_ = { 
    {1, "Jan"},
    {2, "Feb"},
    {3, "March"},
    {4, "April"},
    {5, "May"},
    {6, "June"},
    {7, "July"},
    {8, "August"},
    {9, "September"},
    {10, "October"},
    {11, "November"},
    {12, "December"} };

const std::map<int, int> Month::monthDays_ = { 
    {1, 31},
    {2, 28},
    {3, 31},
    {4, 30},
    {5, 31},
    {6, 30},
    {7, 31},
    {8, 31},
    {9, 30},
    {10, 31},
    {11, 30},
    {12, 31} };


bool Month::verifyMonth(int m)
{
    return m > 0 && m <= 12;
}

Month::Month(int m) { month_ = verifyMonth(m) ? m : 1; }

int Month::getMonth() const
{
    return month_; 
}

std::string Month::str() const
{
    return monthNames_.at(month_);
}

int Month::daysInMonth() const
{
    return monthDays_.at(month_);
}


void Month::setMonth(int m)
{
    month_ = verifyMonth(m) ? m : month_;
}

std::ostream& operator<<(std::ostream& os, const Month& month)
{
    os << month.str();
    return os;
}

std::ostream & operator<<(std::ostream & os, const Date & year)
{
    // TODO: insert return statement here
    return os;
}

int operator-(const Date & date1, const Date & date2)
{
    return 0;
}

//Year
Year::Year(int y) :year_(y) {}

int Year::getYear() const
{
  //IMPLEMENT ME
    return 0;
}

void Year::setYear(int y)
{
  //IMPLEMENT ME
}


/////////////////// Date
//IMPLEMENT DATE!

Date::Date(const Day & d, const Month & m, const Year & y)
{
}

int Date::getDay() const
{
    return 0;
}

int Date::getMonth() const
{
    return 0;
}

int Date::getYear() const
{
    return 0;
}

void Date::setDay(const Day & d)
{
}

void Date::setMonth(const Month & m)
{
}

void Date::setYear(const Year & y)
{
}
