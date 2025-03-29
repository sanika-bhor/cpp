#ifndef SHAPE_H
#define SHAPE_H
#include<iostream>
using namespace std;
namespace drawing
{
    class Shape
    {
        protected:
            int thickness;
            string color;

        public:
            Shape();
            Shape(int thick, string color);
    };
}
#endif