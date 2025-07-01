#include "Post.h"

Post::Post(int _id, string _text, Array<int> _likers, Date _date, int _likes,
    string activity_type, string activity_value,Comment _comm)
    : id(_id), text(_text), likers(_likers), date(_date), likes(_likes),
    act(activity_type, activity_value),comment_list(_comm)
{
    // Constructor body can remain empty since we've used initializer list
}

Post::Post()
{
}

Post::Post(const Post& other)
{
    this->act = other.act;
    this->comment_list = other.comment_list;
    this->date = other.date;
    this->id = other.id;
    this->likers = other.likers;
    this->likes = other.likes;
    this->text = other.text;
}

Post& Post::operator=(const Post& other)
{
    if (this != &other)
    {
        this->act = other.act;
        this->comment_list = other.comment_list;
        this->date = other.date;
        this->id = other.id;
        this->likers = other.likers;
        this->likes = other.likes;
        this->text = other.text;
    }
    return *this;
}

Post::~Post()
{
    // No explicit cleanup needed as member variables handle their own cleanup
}

int Post::get_id()
{
    return this->id;
}

int Post::getLikes()
{
    return this->likes;
}

string Post::getText()
{
    return this->text;
}

Date Post::getDate()
{
    return this->date;
}

string Post::getActivityType()
{
    return this->act.get_act_type();
}

string Post::getActivityValue()
{
    return this->act.get_act_value();
}

void Post::like_post(int user_id)
{
    // Check if the user has already liked the post
    for (int i = 0; i < likers.getlength(); i++) {
        if (likers[i] == user_id) {
            std::cout << "You have already liked this post." << std::endl;
            return;  // Exit the function if the user has already liked the post
        }
    }

    // If not liked, add the user's ID to the likers list and increase the like count
    likers.push(user_id);
    likes++;  // Increase the number of likes
    std::cout << "Post liked by user " << user_id << "!" << std::endl;
}

void Post::print_post()
{
    cout << this->id << endl << this->text << endl
        << this->likes << " <3    posted on " << this->date << endl;
    cout << act.get_act_type() << " -> " << act.get_act_value() << endl;
    //this->comment_list.print_comments();
    cout << "Liked by: ";
    int length = this->likers.getlength();
    for (int i = 0; i < length; i++)
    {
        cout << "u" << this->likers[i] << " ";
    }
    cout <<endl<< this->comment_list;
    cout << endl;
}

void Post::add_comment(string content)
{
    if (!this->comment_list.add_comment(content))
    {
        cout << "Error: Could not add comment (may have reached maximum limit)" << endl;
    }
}

bool Post::is24H(const Date& now)
{
    return this->date.is24Hr(now);
}

ofstream& operator<<(ofstream& f_out, Post& obj)
{
    // TODO: insert return statement here
    /*for (int i = 0; i < anonymous_posts.getlength(); i++)
    {
        postFile << anonymous_posts[i].get_id() << " "
            << anonymous_posts[i].getLikes() << " "
            << anonymous_posts[i].getDate().getDay() << " "
            << anonymous_posts[i].getDate().getMonth() << " "
            << anonymous_posts[i].getDate().getYear() << " "
            << anonymous_posts[i].getText() << ","
            << anonymous_posts[i].getActivityType() << ","
            << anonymous_posts[i].getActivityValue() << endl;
    }*/

    //id likes d m y text,activity_type,activity_value, l i k e r s;c,o,m,m,e,n,t,s,//
    f_out << obj.id << " "
        << obj.likes << " "
        << obj.date.getDay() << " " << obj.date.getMonth() << " " << obj.date.getYear() << " "
        << obj.text << "," << obj.act.get_act_type() << "," << obj.act.get_act_value() << ",";
    for (int i = 0; i < obj.likers.getlength(); i++)
    {
        f_out << obj.likers[i] << " ";
    }
    f_out<< ";";
    f_out << obj.comment_list;

    return f_out;
}
