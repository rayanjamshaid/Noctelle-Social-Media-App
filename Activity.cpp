#include "Activity.h"

using namespace std;

Activity::Activity(int _type) {
    switch (_type) {
    case 1: this->type = "feeling"; break;
    case 2: this->type = "thinking about"; break;
    case 3: this->type = "making"; break;
    case 4: this->type = "celebrating"; break;
    default: this->type = "unknown"; break;
    }

    cout << "Enter your " << this->type << ": ";
    getline(cin, this->value);
}

Activity::Activity(string _type, string _value) 
{
    this->type = _type;
    this->value = _value;
}

Activity::Activity(const Activity& other) 
{
    this->type = other.type;
    this->value = other.value;
}

Activity& Activity::operator=(const Activity& other) {
    if (this != &other) {
        this->type = other.type;
        this->value = other.value;
    }
    return *this;
}

string Activity::get_act_type()
{
    return this->type;
}

string Activity::get_act_value()
{
    return this->value;
}

Activity::~Activity() {
    // No dynamic memory, nothing special needed here
}

ostream& operator<<(ostream& out, const Activity& obj) {
    out << obj.type << ": " << obj.value;
    return out;
}
