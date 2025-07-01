#pragma once

#include "User.h"
#include "Date.h"
#include "Helper.h"
#include "Pages.h"
#include "Post.h"
#include "Memory.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

class App:public Helper
{
private:
    User current;
    C_Array<User> users;
    C_Array<Post> anonymous_posts;
    C_Array<Pages> all_pages;
    Date today;

    void initialise_users();
    void initialise_pages();
    void initialise_anonymous_posts();
    void save_data();

public:
    App();
    ~App();

    void run();
};
