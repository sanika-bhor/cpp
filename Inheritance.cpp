/*PROBLEM STATEMENT 3:
 Imagine a publishing company which does marketing for book and audiocassette versions.
  Create a class publication that stores the title (a string) and price (type float) of a publication. From this class derive two classes: book, 
which adds a page count (type int), and tape, which adds a playing time in minutes (type float).
 Write a program that instantiates the book and tape class, allows user to enter data and displays
the data members.
 If an exception is caught, replace all the data member values withzero values.*/

#include <iostream>
using namespace std;

class Company
{
public:
    char title[30];
    float price;

public:
    void getAccess()
    {
        cout << "Enter the title of the book:" << endl;
        cin >> title;
        cout << "Enter the price of the book:" << endl;
        cin >> price;
    }

    void getDisplay()
    {
        cout << "Title of the book is:" << title << endl;
        cout << "Price of the book is:" << price << endl;
    }
};

class Book : public Company
{
public:
    int n;
    void getpage()
    {
        cout << "Enter the number of page:" << endl;
        cin >> n;
    }
    void show()
    {
        cout << "Number of pages:" << n << endl;
    }
};

class Tape : public Company
{
public:
    float min;
    void getmin()
    {
        cout << "Enter the Reading time of the book:" << endl;
        cin >> min;
    }
    void getDis()
    {
        cout << "Reading time of the book:" << min << endl;
    }
};
int main()
{
    Book b1;
    b1.getAccess();
    b1.getDisplay();
    b1.getpage();
    b1.show();
    Tape t1;
    t1.getAccess();
    t1.getDisplay();
    t1.getmin();
    t1.getDis();

    return 0;
}