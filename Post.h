#pragma once
#include"Date.h"
#include"Array.h"
#include"Comment.h"
#include"Activity.h"
#include<iostream>
#include<fstream>

using namespace std;

class Post
{
    //friend ostream& operator<<(ostream& out, const Post& obj);
    friend ofstream& operator<<(ofstream& f_out, Post& obj);
private:
    int id;
    string text;
    int likes;
    Array<int> likers;
    Date date;
    Activity act;
    Comment comment_list;
public:
    // Constructor
    Post(int _id, string _text, Array<int> _likers, Date _date, int _likes,
        string activity_type, string activity_value ,Comment _comm);

    Post();
    // Copy constructor
    Post(const Post& other);

    // Assignment operator
    Post& operator=(const Post& other);

    // Destructor
    ~Post();

    int get_id();
    int getLikes();
    string getText();
    Date getDate();
    string getActivityType();
    string getActivityValue();
    
    // Methods
    void like_post(int user_id);

    void print_post();
    void add_comment(string content);


    bool is24H(const Date&now);
};