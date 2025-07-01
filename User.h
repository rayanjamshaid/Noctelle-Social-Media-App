#pragma once
#include "Pages.h"
#include "Array.h"
#include "C_Array.h"
#include "Helper.h"
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

class Pages;

class User : public Helper
{
private:
    int id;
    string user_name;
    Array<int> friends;
    Array<int> pages; // pages are liked_pages

    
    bool user_found(const int _id, string& _user_name); // check if user is in registered_users.txt
    void register_user(int& _id, string& _user_name);
    void add_friend_list(string _user_name, Array<int>& _friends);
    void add_pages_list(string _user_name, Array<int>& _pages);

public:
    User();
    User(const User& other);
    User& operator=(const User& other);
    void init_user(int _id);
    User(int _id);
    ~User();
    string get_username();
    int get_id();
    void add_friend(int _id);
    void like_page(int _id);
    void print_friend_pages(C_Array<Pages> page_list,Date*date=nullptr);
    void print_user_profile();
    
    void view_friend_list(C_Array<User> _friends);
    void UserMenu();
};