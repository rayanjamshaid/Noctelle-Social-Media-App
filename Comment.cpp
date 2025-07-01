#include "Comment.h"

Comment::Comment() : comm() {}

Comment::Comment(const Comment& other) {
    comm = other.comm;
}

Comment& Comment::operator=(const Comment& other) {
    if (this != &other) {
        comm = other.comm;
    }
    return *this;
}

void Comment::print_comments() {
    int length = comm.getlength(); 
    for (int i = 0; i < length; i++) {
        cout << "--------" << comm[i] << endl;
    }
}

bool Comment::add_comment(string content) {
    if (comm.getlength() < 10) {
        comm.push(content);
        return true;
    }
    else {
        cout << "Error: No more comments allowed." << endl;
        return false;
    }
}

Comment::~Comment() {}

ostream& operator<<(ostream& out, Comment& obj)
{
    out << "Comments :\n";
    int length = obj.comm.getlength();
    for (int i = 0; i < length; i++)
    {
        out << "----" << obj.comm[i] << endl;
    }
    return out;
}

ofstream& operator<<(ofstream& fout, Comment& obj)
{
    for (int i = 0; i < obj.comm.getlength(); i++)
    {
        fout << obj.comm[i] << ",";
    }
   
    return fout;
}
