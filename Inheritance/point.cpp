#include "point.h"
namespace drawing
{
    Point::Point()
    {
        x=y=0;
    }
    Point::Point(int xx, int yy)
    {
        x=xx;
        y=yy;

    }

    int Point::getX()
    {
        return x;
    }
    int Point::getY(){
        return y;
    }
    void Point::setX(int xx)
    {
        x=xx;
    }
    void Point::setY(int yy){
       y=yy;
    }

    void Point::display(){
        cout<<"("<<x<<","<<y<<")"<<endl;
    }
}
