#include"Pages.h"



void Pages::add_post_list()
{

    //id likes d m y text,activity_type,activity_value, l i k e r s;c,o,m,m,e,n,t,s,//


    string filepath = "./page_posts/" + this->title + "_posts.txt";
    
    ifstream fr(filepath);
    if (!fr.is_open())
    {
        cout << "Error opening post list for page: " << title << endl;
        return;
    }

    fr >> this->like_count;
    string line;
    getline(fr, line); // consume newline after like_count

    while (getline(fr, line))
    {
        stringstream sr(line);
        //id likes d m y text,activity_type,activity_value, l i k e r s;c,o,m,m,e,n,t,s,//
        int id, likes, d, m, y;
        string text, activity_type, activity_value;
        Array<int> likers;
        sr >> id >> likes >> d >> m >> y;
        sr.ignore(); // ignore whitespace before text
        getline(sr, text, ',');
        getline(sr, activity_type, ',');
        getline(sr, activity_value, ',');


        string likers_list;
        getline(sr, likers_list, ';');
        stringstream sr_likers(likers_list);
        int liker_temp;
        while (sr_likers >> liker_temp) {
            likers.push(liker_temp);
        }

        string temp_comment;
        Comment temp_c;
        while (getline(sr, temp_comment, ','))
        {
            temp_c.add_comment(temp_comment);
        }

        posts.push(Post(id, text, likers, Date(d, m, y), likes, activity_type, activity_value,temp_c));
    }

    fr.close();
}

bool Pages::page_found(int _id,int owver_id, string& out_title) {
    ifstream fr("./existing_pages.txt");
    string line;

    while (getline(fr, line)) {
        stringstream sr(line);
        int temp_id;
        sr >> temp_id;
        if (temp_id == _id)
        {
            sr >> temp_id;
            getline(sr, out_title);
            fr.close();
            return true;
        }
    }

    fr.close();
    return false;
}

void Pages::register_page() 
{
    string filepath = "./page_posts/" + this->title + "_posts.txt";
    ofstream fw(filepath);
    if (fw.is_open()) {
        fw << 0 << endl; // like count line
        fw.close();
    }

    ofstream registerFile("./existing_pages.txt", ios::app);
    if (registerFile.is_open()) {
        //page_id owner_id title
        registerFile << this->id <<" " << this->owner->get_id() << " " << this->title << endl;
        registerFile.close();
    }
}

Pages::Pages(int _id, User* _owner) 
{
    this->owner = _owner;

    string loaded_title;
    
    if (page_found(_id,_owner->get_id(), loaded_title)) 
    {
        this->id = _id;
        this->title = loaded_title;
        add_post_list();
    }
    else 
    {
        cout << "Page not found. Do you want to create a new one? (1 = Yes, 0 = No): ";
        bool create_new = false;
        cin >> create_new;
        cin.ignore();

        if (create_new) {
            cout << "Enter title: ";
            getline(cin, this->title);

            this->id = Helper::getLastLineInteger("./existing_pages.txt") + 1;
            this->like_count = 0;
            int owner_id = _owner->get_id();
            this->register_page();
            cout << "--id of page" << this->id << "\n--name of page : " << this->title << endl;

        }
    }
}

Pages::Pages(int _id, string _title, User* _owner)
    :id(_id),title(_title),owner(_owner),like_count(0)
{
    add_post_list();
}

Pages::Pages()
{
}

Pages::~Pages() {
    //posts.clear(); // assuming Array<T> has clear()
    /*
    // Save anonymous posts to file
    ofstream postFile("./anonymous_posts.txt");
    for (int i = 0; i < anonymous_posts.getlength(); i++)
    {
        postFile << anonymous_posts[i].get_id() << " "
            << anonymous_posts[i].getLikes() << " "
            << anonymous_posts[i].getDate().getDay() << " "
            << anonymous_posts[i].getDate().getMonth() << " "
            << anonymous_posts[i].getDate().getYear() << " "
            << anonymous_posts[i].getText() << ","
            << anonymous_posts[i].getActivityType() << ","
            << anonymous_posts[i].getActivityValue() << endl;
    }
    postFile.close();
    */
    //id likes d m y text,activity_type,activity_value, l i k e r s;c,o,m,m,e,n,t,s,//
    string filepath = "./page_posts/" + this->title + "_posts.txt";
    ofstream f_post(filepath);
    f_post << this->like_count << endl;
    for (int i = 0; i < this->posts.getlength(); i++)
    {
        f_post << this->posts[i]<<endl;
    }
    f_post.close();


    owner = nullptr;
}

Pages::Pages(const Pages& other) {
    this->id = other.id;
    this->like_count = other.like_count;
    this->owner = other.owner;
    this->posts = other.posts;
    this->title = other.title;
}

Pages& Pages::operator=(const Pages& other)
{
    if (this != &other)
    {
        this->id = other.id;
        this->like_count = other.like_count;
        this->owner = other.owner;
        this->posts = other.posts;
        this->title = other.title;
    }
    return *this;
}

void Pages::add_post(int id, int likes, Date d, string text,
    string activity_type, string activity_value)
{
    

    string filepath = "./page_posts/" + this->title + "_posts.txt";
    Helper::add_post_record(filepath, id, likes, d.getDay(),d.getMonth(),d.getYear(), text, activity_type, activity_value);
    Array<int>_likers;
    Comment temp_c;
    posts.push(Post(id, text, _likers, d, likes, activity_type, activity_value,temp_c));

}

void Pages::print_profile()
{
    cout <<"title : "<< this->title << "  owner : u" << this->owner->get_id();
}

void Pages::print_posts(bool dated,Date* date)
{
    cout << "page id : " << this->id << "    title : " << this->title << "  owner : " << this->owner->get_id() << endl;
    if (!dated)
    {
        for (int i = 0; i < posts.getlength(); i++)
        {
            this->posts[i].print_post();
        }
    }
    else
    {
        bool flag = true;
        for (int i = posts.getlength() - 1; i >= 0&&flag; i--)
        {
            if (this->posts[i].is24H(*(date)))
            {
                this->posts[i].print_post();
            }
            else
            {
                flag = false;
                break;
            }
        }
    }
}

bool Pages::if_user_owns_page(int user_id)
{
    if (this->owner->get_id() == user_id)
    {
        return true;
    }
    return false;
}

void Pages::like_some_post(int liker_id)
{
    this->print_posts();
    cout << "enter id of post to like : ";
    int post_id;
    cin >> post_id;
    for (int i = 0; i < this->posts.getlength(); i++)
    {
        if (post_id == this->posts[i].get_id())
        {
            this->posts[i].like_post(liker_id);
            break;
        }
    }
}

void Pages::comment_on_some_post(int post_id, string comment_text)
{
    post_id--;
    this->posts[post_id].add_comment(comment_text);
}



