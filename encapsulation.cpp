// Encapsulation: Encapsulation in C++ is defined as the wrapping up of data  and information in a single unit.
#include<iostream>
using namespace std;

class point
{
    private:
        int x, y;

    public:
// constructor 
        point()
        {
            this->x=0;
            this->y=0;
        }

        point(int x, int y)
        {
            this->x = x;
            this->y = y;
        }
//getter
        int getX()
        {
            return this->x;
        }
        int getY()
        {
            return this->y;
        }
//setter
        void setX(int x)
        {
            this->x = x;
        }
        void setY(int y)
        {
            this->y = y;
        }
//destructor
~point()
{
    cout<<"\noperation complete";
}
};

int main()
{

//using default constructor
    point p2;
    //default values
    cout << "\nx: " << p2.getX();
    cout << "\ny: " << p2.getY();
    // setter
    p2.setX(5);
    p2.setY(10);
    //getter
    cout << "\nx: " << p2.getX();
    cout << "\ny: " << p2.getY();
    cout<<endl;

// using parameterized constructor
    point p1(20,10);
    // default values
    cout << "\nx: " << p1.getX();
    cout << "\ny: " << p1.getY();
    // setter
    p1.setX(15);
    p1.setY(56);
    // getter
    cout << "\nx: " << p1.getX();
    cout << "\ny: " << p1.getY();
    cout << endl;

// using dynamic memory allocation
    point *p3 = new point(30, 40);
    // default values
    cout << "\nx: " << p3->getX();
    cout << "\ny: " << p3->getY();
    // setter
    p3->setX(12);
    p3->setY(35);
    // getter
    cout << "\nx: " << p3->getX();
    cout << "\ny: " << p3->getY();
    delete p3;
    cout << endl;
}