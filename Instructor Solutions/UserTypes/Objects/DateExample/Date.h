#pragma once
#include <stdexcept>

class Date {
    int month_ = 0; //valid (00 .. 11)
    int day_ = 0; //valid (00 .. 31) 
    int year_ = 0; //valid (00 .. 2050)

public: //Things that are public define the interface to the user. 
    Date() {}
    Date(int month, int day, int year) :month_(month), day_(day), year_(year) {}

    int getMonth() const { return month_; }
    int getDay() const { return day_; }
    int getYear() const { return year_; }
    void setYear(int year) {
        year_ = year >= 00 && year <= 2050 ? year : throw std::runtime_error("Bad Year");
    }
    void setDay(int day) {
        day_ = day >= 0 && day <= 31 ? day : throw std::runtime_error("Bad Day");
    }
    void setMonth(int month) {
        month_ = month >= 0 && month <= 31 ? month : throw std::runtime_error("Bad Month");
    }
};