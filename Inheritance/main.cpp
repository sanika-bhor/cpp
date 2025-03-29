#include"point.h"
#include"circle.h"
using namespace drawing;
int main()
{
   Point p1(10,20);
   Circle circle(2,"yellow",20,p1);
   circle.display();
}