#ifndef CIRCLE_H
#define CIRCLE_H
#include"shape.h"
#include"point.h"
#include <iostream>
using namespace std;
namespace drawing
{
    class Circle:public Shape
    {
    private:
        int radius;
        Point center;

    public:
        Circle();
        Circle(int thick, string c,int r, Point p);

        void display();
    };
}
#endif