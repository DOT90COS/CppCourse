#pragma once
//This code is modified but originally from The C++ Standard Library: A Tutorial and Reference, Second Edition Section 5.7
#include <chrono>
#include <ctime>
#include <string>
#include <sstream>
#include <iomanip>

namespace mytime
{
#pragma warning(disable:4996)
    //convert timepoint of system clock to calendar time string
    inline std::string asString(const std::chrono::system_clock::time_point& tp)
    {
        //convert to system time:
        std::stringstream ss;
        std::time_t t = std::chrono::system_clock::to_time_t(tp);
        ss << std::put_time(std::localtime(&t), "%c");
        return ss.str();
    }
#pragma warning(default:4996)

    //convert calendar time to timepoint of system clock
    inline std::chrono::system_clock::time_point
        makeTimePoint(int year, int mon, int day, int hour = 0, int min = 0, int sec = 0)
    {
        struct std::tm t;
        t.tm_sec = sec; //second of minute (0 .. 59 and 60 for leap seconds)
        t.tm_min = min; //minute of hour (0 .. 59)
        t.tm_hour = hour; //hour of day (0 .. 23)
        t.tm_mday = day; //day of month (0 .. 31)
        t.tm_mon = mon - 1; //mon of year (0 .. 11)
        t.tm_year = year - 1900; //year since 1900
        t.tm_isdst = -1; //determine whether daylight saving time
        std::time_t tt = std::mktime(&t);
        if (tt == -1)
        {
            throw std::runtime_error("No valid system time");
        }

        return std::chrono::system_clock::from_time_t(tt);
    }

};