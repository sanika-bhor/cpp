#include"circle.h"
namespace drawing
{
    Circle::Circle()
    {
        Point pt(0,0);
        radius=0;
       center=pt;
    }
    Circle::Circle(int thick, string c, int r, Point p):Shape(thick,c)
    {
         radius=r;
         center=p;
    }

    void Circle::display(){
        cout<<"radius: "<<radius<<endl;
        cout<<"center point x: "<<center.getX()<<endl;
        cout<<"center point Y: "<<center.getY()<<endl;
        cout<<"thickness: "<<thickness<<endl;
        cout<<"Color: "<<color<<endl;
    }
}
