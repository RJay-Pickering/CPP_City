#include <iostream>
#include<list>  

// use this so you do not have to type std:: before "cout" and "endl"
using namespace std;

string action;
list<string> BookList;
list<string> CheckList;
list<string> PersonList;
// the list below contains the people that checked out a book
list<string> HumanList;

string continued_checkout_function(string book, string user)
{
   if (find(HumanList.begin(), HumanList.end(), user) != HumanList.end())
   {
      cout << "This user has checked out a book already" << endl;
      return "";
   } 
   else if (find(PersonList.begin(), PersonList.end(), user) != PersonList.end()) {
      cout << "Congratulations, you have successfully checked out a book" << endl;
      HumanList.__emplace_back (user);
      CheckList.__emplace_back (book);
      PersonList.remove(user);
      BookList.remove(book);
      return "";
   } 
   else {
      cout << "This user does not exist!" << endl;
      return "";
   }
}

int main() 
{   
    cout << "\nHello, welcome to Book-Galore!\n" << endl << "How may we help you today?" << endl;
    while (true)
    {
        cout << "\n[donate] book, [available] books, view [all] a book, view [customers], [checkout] book, [register] customer, or [q]uit!" << endl;
        // collects input
        cin >> action;
        if (action == "donate")
        {
            string book;
            cout << "What is the name of the book: " << endl;
            cin >> book;
            BookList.__emplace_back (book);
        } 
        else if (action == "available")
        {
            string book;
            cout << "What is the name of the book: " << endl;
            cin >> book;
            if (find(CheckList.begin(), CheckList.end(), book) != CheckList.end())
            {
               cout << "This book has been checked out" << endl;
            } 
            else if (find(BookList.begin(), BookList.end(), book) != BookList.end()) {
               cout << book << " is currently available!" << endl;
            } 
            else {
               cout << "This book does not exist!" << endl;
            }
        }
        else if (action == "all")
        {
            int counter = 1;
            for (string v : BookList)
            {
               cout << counter << ". " << v << endl;
               counter++;
            }
        }
        else if (action == "customers")
        {
            int counter = 1;
            for (string v : PersonList)
            {
               cout << counter << ". " << v << endl;
               counter++;
            }
        }
        else if (action == "checkout")
        {
            string book;
            cout << "What is the name of the book: " << endl;
            cin >> book;
            if (find(CheckList.begin(), CheckList.end(), book) != CheckList.end())
            {
               cout << "This book has been checked out already" << endl;
            } 
            else if (find(BookList.begin(), BookList.end(), book) != BookList.end()) {
               string user;
               cout << "What is the name of the customer: " << endl;
               cin >> user;
               continued_checkout_function(book, user);
            } 
            else {
               cout << "This book does not exist!" << endl;
            }
        }
        else if (action == "register")
        {
            string user;
            cout << "What is the name of the customer: " << endl;
            cin >> user;
            PersonList.__emplace_back (user);
        }
        else if (action == "q")
        {
           break;
        }
        else
        {
           cout << "Wrong Input, please check your spelling or try typing what is in the brackets ( [] )" << endl;
        }
    }
}