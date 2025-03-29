#include"shape.h"
namespace drawing
{
        Shape::Shape()
        {
            thickness = 1;
            color = "Black";
        }

        Shape::Shape(int thick, string c)
        {
            thickness=thick;
            color=c;
        }
}