#pragma once
#include "Array.h"
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class Helper
{
public:
    // Gets the first integer from the last line of a file
    int getLastLineInteger(string filename);

    // Adds a post record to a file with format:
    // id likes date text,activity type,activity value, l i k e r s
    void add_post_record(string filename, int id, int likes, int d, int m, int y,
        string text, string activity_type, string activity_value);
};