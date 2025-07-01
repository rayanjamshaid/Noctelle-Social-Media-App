#include "Date.h"


Date::Date(int _d, int _m, int _y, int _h, int _min)
    : d(_d), m(_m), y(_y), h(_h), min(_min) {}

Date::Date(const Date& other) {
    this->d = other.d;
    this->m = other.m;
    this->y = other.y;
    this->h = other.h;
    this->min = other.min;
}

Date& Date::operator=(const Date& other) {
    if (this != &other) {
        this->d = other.d;
        this->m = other.m;
        this->y = other.y;
    }
    return *this;
}

void Date::init_date(int _d, int _m, int _y,int _h,int _min) {
    this->d = _d;
    this->m = _m;
    this->y = _y;
    this->h = _h;
    this->min = _min;
}

int Date::getDay()
{
    return this->d;
}

int Date::getMonth()
{
    return this->m;
}

int Date::getYear()
{
    return this->y;
}

Date::~Date() {}

bool Date::is24Hr(const Date& now) {
    int newY, newMon, newD, newH, newMin;
    
    newMin = now.min - min;
    newH = now.h - h;
    newD = now.d - d;
    newMon = now.m - m;
    newY = now.y - y;

    
    if (newMin < 0) {
        newH--;
        newMin += 60;
    }

    if (newH < 0) {
        newD--;
        newH += 24;
    }

    if (newD < 0) {
        newMon--;
        newD += 30;
    }

    if (newMon < 0) {
        newY--;
        newMon += 12;
    }

    return (newY == 0) && (newMon == 0) && (newD == 0) && (newH <= 24);
}

std::ostream& operator<<(std::ostream& out, const Date& obj) {
    out << obj.d << "/" << obj.m << "/" << obj.y;
    return out;
}
