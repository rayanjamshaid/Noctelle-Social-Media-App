#pragma once

#include <string>
#include <iostream>
#include<fstream>

#include "Array.h"

using namespace std;

class Comment {
    friend ostream& operator<<(ostream& out, Comment& obj);
    friend ofstream& operator<<(ofstream& fout, Comment& obj);
private:
    Array<string> comm;

public:
    Comment();
    Comment(const Comment& other);
    Comment& operator=(const Comment& other);

    void print_comments();
    bool add_comment(string content);

    ~Comment();
};
