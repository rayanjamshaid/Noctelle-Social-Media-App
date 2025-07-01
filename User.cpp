#include "User.h"

bool User::user_found(const int _id, string& _user_name)//id will be given to function, while we will give _user_name
{
    string line;
    ifstream fr("./registered_users.txt");
    while (getline(fr, line))
    {
        //cout << line << endl;
        int temp_id;
        stringstream sr(line);
        sr >> temp_id;
        //cout << temp_id << endl;
        if (temp_id == _id)
        {
            sr >> _user_name;
            //cout << _user_name;
            fr.close();
            return true;
        }
    }

    fr.close();
    return false;
}

void User::register_user(int& _id, string& _user_name)
{
    string filepath = "./registered_users.txt";
    _id = Helper::getLastLineInteger(filepath) + 1;
    ofstream fw(filepath, ios::app);
    fw <<endl<< _id << " " << _user_name;
    fw.close();

    filepath = "./user_friends/" + _user_name + "_friendlist.txt";
    ofstream fw2(filepath);
    fw2.close();

    filepath = "./user_liked_pages/" + _user_name + "_pagelist.txt";
    ofstream fw3(filepath);
    fw3.close();
}

void User::add_friend_list(string _user_name, Array<int>& _friends)
{
    int temp;
    string filepath = "./user_friends/" + _user_name + "_friendlist.txt";
    ifstream fr(filepath);
    while (fr >> temp)
    {
        _friends.push(temp);
    }
    fr.close();
}

void User::add_pages_list(string _user_name, Array<int>& _pages)
{
    int temp;
    string filepath = "./user_liked_pages/" + _user_name + "_pagelist.txt";
    ifstream fr(filepath);
    while (fr >> temp)
    {
        _pages.push(temp);
    }
    fr.close();
}

User::User() : id(0), user_name(""), friends(), pages()
{
}

User::User(const User& other)
{
    this->id = other.id;
    this->user_name = other.user_name;
    this->friends = other.friends;
    this->pages = other.pages;
}

User& User::operator=(const User& other)
{
    if (this != &other)
    {
        this->id = other.id;
        this->user_name = other.user_name;
        this->friends = other.friends;
        this->pages = other.pages;
    }
    return *this;
}

void User::init_user(int _id)
{
    this->id = _id;

    if (id != 0 && user_found(this->id, this->user_name))
    {
        add_friend_list(this->user_name, this->friends);
        add_pages_list(this->user_name, this->pages); 
        cout << this->user_name << endl;
    }
    else
    {
        cout << "User not found. Register user? (1 for Yes, 0 for No): ";
        bool yes;
        cin >> yes;
        if (yes) {
            cin.ignore();
            cout << "Enter username: ";
            string un;
            getline(cin, un);
            this->user_name = un;
            register_user(this->id, this->user_name);
        }
    }
}

User::User(int _id) : id(_id), friends(), pages()
{

    if (id != 0 && user_found(this->id, this->user_name))
    {
        add_friend_list(this->user_name, this->friends);
        add_pages_list(this->user_name, this->pages);
    }
    /*else
    {
        cout << "User not found. Register user? (1 for Yes, 0 for No): ";
        bool yes;
        cin >> yes;
        if (yes) {
            cin.ignore();
            cout << "Enter username: ";
            string un;
            getline(cin, un);
            this->user_name = un;
            register_user(this->id, this->user_name);
        }
    }*/
}

User::~User()
{

}

string User::get_username()
{
    return this->user_name;
}

int User::get_id()
{
    return this->id;
}

void User::add_friend(int _id)
{
    this->friends.push(_id);
    string filepath = "./user_friends/" + this->user_name + "_friendlist.txt";
    ofstream fw(filepath, ios::app);
    fw << _id << endl; 
    fw.close();
}

void User::like_page(int _id)
{
    this->pages.push(_id);
    string filepath = "./user_liked_pages/" + this->user_name + "_pagelist.txt";
    ofstream fw(filepath, ios::app);
    fw << _id << endl;
    fw.close();
}

void User::print_friend_pages(C_Array<Pages> page_list,Date*date)
{
    int length = this->pages.getlength();
    
    for (int i = 0; i < length; i++)
    {
        
        page_list[this->pages[i]].print_posts(true, date);
    }
}

void User::print_user_profile()
{
    cout << this->id << "  " << this->user_name << endl;
}



void User::view_friend_list(C_Array<User> _friends)
{
    int length = this->friends.getlength();
    cout << "The friends of " << this->user_name << " are :\n";
    for (int i = 0; i < length; i++)
    {
        cout << "___ u" << this->friends[i] << "  "
            << _friends[this->friends[i]].get_username() << endl;
    }
}

void User::UserMenu()
{
    // To be continued;;//
}