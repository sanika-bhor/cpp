#include <iostream>
#include"shape.h"
using namespace std;
namespace drawing
{
        Shape::Shape()
        {
            thickness = 1;
            color = "Black";
        }

        Shape::Shape(int thick, string color)
        {
            thickness=thick;
            color=color;
        }
}