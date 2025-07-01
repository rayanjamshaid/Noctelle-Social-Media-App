#pragma once

#include "Post.h"

#include "User.h"
#include "Helper.h"
#include "Array.h"

#include "C_Array.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

class User;


class Pages : public Helper {
private:
    int id;
    User* owner;
    std::string title;

    

    C_Array<Post>posts;
    int like_count;

    void add_post_list();
    bool page_found(int _id,int owner_id, std::string& out_title);
    void register_page();

public:
    Pages(int _id, User* _owner); // optional owner
    Pages();
    Pages(int _id, string _title, User* _owner);
    ~Pages();
    Pages(const Pages& other);
    Pages& operator=(const Pages& other);

    void print_posts(bool dated=false,Date* date=nullptr);
    bool if_user_owns_page(int user_id);
    void like_some_post(int liker_id);
    void comment_on_some_post(int post_id,string comment_text);
    void add_post(int id, int likes, Date d, string text,
        string activity_type,string activity_value);

    void print_profile();
};
