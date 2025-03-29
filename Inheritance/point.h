#ifndef POINT_H
#define POINT_H
#include <iostream>
using namespace std;
namespace drawing
{
    class Point
    {
    private:
        int x,y;

    public:
        Point();
        Point(int xx, int yy);

        int getX();
        int getY();
        void setX(int x);
        void setY(int y);

        void display();
    };
}
#endif