#include<iostream>
using namespace std;
class Point
{
    private:
        int x,y;
    public:
        Point()
        {
            this->x=0;
            this->y=0;
        }
        Point(int x, int y)
        {
            this->x = x;
            this->y = y;
        }

        void display()
        {
            cout<<"  x: "<<this->x<<"   y: "<<this->y;
        }

        friend Point operator+ (Point p1, Point p2);
};

Point operator+(Point p1, Point p2)
{
    Point temp;
    temp.x=p1.x+p2.x;
    temp.y=p1.y+p2.y;
    return temp;
}

int main()
{
    Point p1(5, 6);
    Point p2(4, 3);
    Point p3=p1+p2;
    cout<<"\n Point 1: ";
    p1.display();
    cout << "\n Point 2: ";
    p2.display();
    cout << "\n Addition: ";
    p3.display();
}
