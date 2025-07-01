#pragma once

#include <string>
#include <iostream>

using namespace std;


class Activity {
    friend std::ostream& operator<<(std::ostream& out, const Activity& obj);

private:
    std::string type;
    std::string value;

public:
    Activity(int _type);
    Activity(std::string _type = "", std::string _value = "");

    Activity(const Activity& other);
    Activity& operator=(const Activity& other);

    string get_act_type();

    string get_act_value();

    ~Activity();
};
