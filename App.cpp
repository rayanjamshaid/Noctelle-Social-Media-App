#include "App.h"

void App::initialise_users()
{
    ifstream fr("./registered_users.txt");
    string line;
    while (getline(fr, line))
    {
        int id;
        stringstream sr(line);
        sr >> id;
        this->users.push(User(id));
    }
    fr.close();
}

void App::initialise_pages()
{
    ifstream fr("./existing_pages.txt");
    string line;
    while (getline(fr, line))
    {
        //page_id owner_id title//
        stringstream ss(line);
        int id, owner_id;
        string title;
        ss >> id >> owner_id;
        getline(ss >> std::ws, title);
        getline(ss, title);
        owner_id--;
        this->all_pages.push(Pages(id,title,&(this->users[owner_id])));
    }
    fr.close();
}

void App::initialise_anonymous_posts()
{
    string filepath = "./anonymous_posts.txt";
    ifstream fr(filepath);
    string line;
    while (getline(fr, line))
    {
        stringstream sr(line);
        //id likes d m y text,activity_type,activity_value, l i k e r s;c,o,m,m,e,n,t,s,//
        /*
        *
        */
        int id;
        string text, activity_type, activity_value;
        int likes;
        Array<int> likers;
        int d, m, y;
        sr >> id >> likes >> d >> m >> y;
        getline(sr, text, ',');
        getline(sr, activity_type, ',');
        getline(sr, activity_value, ',');
        /* string likers_list;
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
        }*/


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

        this->anonymous_posts.push(Post(id, text, likers, Date(d, m, y), likes, activity_type, activity_value, temp_c));
    }
    fr.close();
}

void App::save_data()
{
    /*
    // Save users to file
    ofstream userFile("./registered_users.txt");
    for (int i = 0; i < users.getlength(); i++)
    {
        userFile << users[i].get_id() << endl;  // assuming User class has getUserId()
    }
    userFile.close();
    */

    // Save anonymous posts to file
    //id likes d m y text,activity_type,activity_value, l i k e r s;c,o,m,m,e,n,t,s//
    ofstream postFile("./anonymous_posts.txt");
    for (int i = 0; i < anonymous_posts.getlength(); i++)
    {
        postFile << this->anonymous_posts[i] << endl;
    }
    postFile.close();
}

App::App() : current(), users(), anonymous_posts(), all_pages(), today()
{
    cout << "Enter date (day/month/year/hour/min): ";
    int d, m, y,h,min;
    cin >> d >> m >> y>>h>>min;

    today.init_date(d, m, y,h,min);


    cout << "Enter your user unique id\nif you want to add a new user, input 0: ";
    cin >> d;
    current.init_user(d);

    initialise_users();
    initialise_pages();
    initialise_anonymous_posts();

    
}

App::~App()
{
    save_data();  // Save data when app closes
}

void App::run()
{
    while (true)
    {

        static bool posts_printed = false;
        if (!posts_printed)
        {
            cout << "\n\n\n____________MAIN PAGE_____________\n";
            int length = this->anonymous_posts.getlength();
            bool flag = true;
            for (int i = length-1; i >=0&&true; i--)
            {
                if (this->anonymous_posts[i].is24H(today))
                {
                    cout << "\n\n-------Post " << i + 1 << "--------\n";
                    this->anonymous_posts[i].print_post();
                    cout << "\n--------End Post---------\n\n";
                }
                else
                {
                    flag = false;
                    break;
                }
            }

            this->current.print_friend_pages(this->all_pages,&today);
            posts_printed = true;
            cout << "__________END MAIN PAGE___________\n";
        }

        cout << "\n0. view yourself"
            << "\n1. View user profile\n"
            << "2. View friend list of a user\n"
            << "3. View page\n"
            << "4. Make a page\n"
            << "5. View anonymous posts\n"
            << "6. Share memory\n"
            << "7. Like a post\n"
            << "8. Comment on a post\n"
            << "9. Exit\n"
            << "10. view list of users\n"
            << "11. make friends\n"
            << "12. add a post to some page\n"
            << "13. add a anonymous post\n"
            << "14. like a page\n"
            << "15. view list of all pages along with owners\n"
            << "16. view all users\n";
        /*
            cout<<"\n\n-----------------------------------\n\n";
        */
        int option = 0;
        cin >> option;
        switch (option)
        {
        case 0: 
        {
            cout << "\n\n-----------------------------------\n\n";
            cout << "you are : \nid : " << this->current.get_id() 
                << "   \tuser_name : " << this->current.get_username() << endl;
            this->current.view_friend_list(this->users);
            cout << "\n\n-----------------------------------\n\n";
        }
        break;
        case 1:
        {
            cout << "\n\n-----------------------------------\n\n";
            cout << "Enter user id: ";
            int id;
            cin >> id;
            id--;
            this->users[id].print_user_profile();
            this->users[id].view_friend_list(this->users);
            this->users[id].print_friend_pages(this->all_pages);
            cout << "\n\n-----------------------------------\n\n";
        }break;

        case 2:
        {
            cout << "\n\n-----------------------------------\n\n";
            cout << "Enter user id: ";
            int id;
            cin >> id;
            id--;
            this->users[id].view_friend_list(this->users);
            cout << "\n\n-----------------------------------\n\n";
        }
        break;

        case 3:
        {
            cout << "\n\n-----------------------------------\n\n";
            cout << "Enter page id: ";
            int id;
            cin >> id;
            id--;
            this->all_pages[id].print_posts();
            cout << "\n\n-----------------------------------\n\n";
        }
        break;

        case 4: {
            cout << "\n\n-----------------------------------\n\n";
            this->all_pages.push(Pages(0,&current));
            cout << "\n\n-----------------------------------\n\n";
        }
            break; 
        case 5:
        {
            cout << "\n\n-----------------------------------\n\n";
            int length = this->anonymous_posts.getlength();
            for (int i = 0; i < length; i++)
            {
                this->anonymous_posts[i].print_post();
                cout << endl;
            }
            cout << "\n\n-----------------------------------\n\n";
        }
        break;

        case 6:  // Share Memory
        {
            cout << "\n\n-----------------------------------\n\n";
            cout << "Share a memory (Enter post ID): ";
            int postId;
            cin >> postId;
            if (postId < anonymous_posts.getlength())
            {
                Memory mem(&this->anonymous_posts[postId]);
                mem.show_memory();
            }
            else
            {
                cout << "Invalid post ID!\n";
            }
            cout << "\n\n-----------------------------------\n\n";
        }
        break;

        case 7:  // Like Post
        {
            cout << "\n\n-----------------------------------\n\n";
            bool is_page_post;
            cout << "Enter if it is a Post inside a Page(1) or an anonymous post(0)?\n(yes==1, no==0  : ";
            cin >> is_page_post;
            if (is_page_post)
            {
                cout << "enter page id : ";
                int page_id;
                cin >> page_id;
                page_id--;
                this->all_pages[page_id].like_some_post(this->current.get_id());
            }
            else
            {
                cout << "Enter post ID to like: ";
                int postId;
                cin >> postId;
                postId--;

                if (postId < anonymous_posts.getlength())
                {
                    anonymous_posts[postId].like_post(this->current.get_id());
                    cout << "Post liked!\n";
                }
                else
                {
                    cout << "Invalid post ID!\n";
                }
            }
            cout << "\n\n-----------------------------------\n\n";
        }
        break;

        case 8:  // Comment on Post
        {
            cout << "\n\n-----------------------------------\n\n";
            cout << "is the post anonyomous(0) or in some page(1)? : ";
            bool opt;
            cin >> opt;
            if (opt)
            {
                cout << "enter page id : ";
                int page_id;
                cin >> page_id;
                page_id--;
                this->all_pages[page_id].print_posts();
                cout << "Enter id of post : ";
                int post_id;
                cin >> post_id;
                cout << "enter comment : ";
                cin.ignore();
                string comment_text;
                getline(cin, comment_text);
                this->all_pages[page_id].comment_on_some_post(post_id, comment_text);

            }
            else {
                cout << "Enter post ID to comment on: ";
                int postId;
                cin >> postId;
                postId--;
                if (postId < anonymous_posts.getlength())
                {
                    string commentText;
                    cout << "Enter comment: ";
                    cin.ignore();
                    getline(cin, commentText);
                    anonymous_posts[postId].add_comment(commentText);
                }
                else
                {
                    cout << "Invalid post ID!\n";
                }
            }
            cout << "\n\n-----------------------------------\n\n";
        }
        break;

        case 9:return;
        case 10:
        {
            cout << "\n\n-----------------------------------\n\n";
            for (int i = 0; i < this->users.getlength(); i++)
            {
                this->users[i].print_user_profile();
            }
            cout << "\n\n-----------------------------------\n\n";
        }
        break;
        case 11:
        {
            cout << "\n\n-----------------------------------\n\n";
            for (int i = 0; i < this->users.getlength(); i++)
            {
                this->users[i].print_user_profile();
            }
            cout << "Who do you want as your friend? :\nEnter his/her user id : ";
            int id = 0;
            cin >> id;
            this->current.add_friend(id);
            cout << "\n\n-----------------------------------\n\n";
        }
        break;
        case 12:
        {
            cout << "\n\n-----------------------------------\n\n";
            int page_id;
            cout << "enter page_id :";
            cin >> page_id;
            page_id--;
            if (this->all_pages[page_id].if_user_owns_page(this->current.get_id()))
            {
                cout << "enter id : ";
                int post_id;
                cin >> post_id;
                cout << "enter text of post : ";
                string text, activity_type, activity_value;
                cin >> text;
                cout << "Enter activity type : ";
                cin >> activity_type;
                cout << "Enter activity value : ";
                cin >> activity_value;
                this->all_pages[page_id].add_post(post_id, 0, this->today, text, activity_type, activity_value);
                /*void add_post(int id, int likes, Date d, std::string text,
        std::string activity_type, std::string activity_value,Array<int>& likers);*/
            }
            else
                cout << "You do not own this page\n";
            //continue it from here tomorrow, so that we can add post functionality, along with date thing..

            //this->all_pages[page_id].add_post()
            cout << "\n\n-----------------------------------\n\n";
        }
        break;
        case 13:
        {
            cout << "\n\n-----------------------------------\n\n";
            cout << "enter id : ";
            int post_id;
            cin >> post_id;
            cout << "enter text of post : ";
            string text, activity_type, activity_value;
            cin >> text;
            cout << "Enter activity type : ";
            cin >> activity_type;
            cout << "Enter activity value : ";
            cin >> activity_value;
            Array<int>likeers;
            Comment temp_c;
            this->anonymous_posts.push(Post(post_id, text, likeers, today, 0, activity_type, activity_value,temp_c));

            //string filepath = "./anonymous_posts.txt";
            /*Helper::add_post_record(filepath, post_id, 0, 
                today.getDay(), today.getMonth(), today.getYear(),
                text, activity_type, activity_value);*/
            cout << "\n\n-----------------------------------\n\n";
        }
        break;
        case 14:
        {
            cout << "\n\n-----------------------------------\n\n";
            cout << "Enter the id of page to like : ";
            int id;
            cin >> id;
            this->current.like_page(id);
            cout << "\n\n-----------------------------------\n\n";
        }
        break;
        case 15:
        {
            int length = this->all_pages.getlength();
            for (int i = 0; i < length; i++)
            {
                cout <<"id : "<< i+1 << "   ";
                this->all_pages[i].print_profile();
                cout << endl;
            }
        }
        break;
        case 16:
        {
            int length = this->users.getlength();
            for (int i = 0; i < length; i++)
            {
                this->users[i].print_user_profile();
                
            }
        }
        break;
        
        default:
            cout << "Invalid option. Please try again.\n";
        }
    }
}
