#pragma once
#include <iostream>

using namespace std;

class Date {
private:
    int d;
    int m;
    int y;

    int h, min;

public:
    friend std::ostream& operator<<(std::ostream& out, const Date& obj);

    Date(int _d = 0, int _m = 0, int _y = 0,int _h=0,int _min=0);

    Date(const Date& other);
    Date& operator=(const Date& other);
    void init_date(int _d, int _m, int _y,int _h,int _min);

    int getDay();
    int getMonth();
    int getYear();
    ~Date();

    bool is24Hr(const Date& now);
    
};
