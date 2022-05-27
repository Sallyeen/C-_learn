#include <iostream>
#include "circle.h"
#include "point.h"

using namespace std;

// 设计圆类和点类，计算二者关系

int relation(Circle& c, Point& p)
{   
    if ((c.getCenter().getX()-p.getX()) * (c.getCenter().getX()-p.getX()) + (c.getCenter().getY()-p.getY()) * (c.getCenter().getY()-p.getY()) < c.getR() * c.getR())
    {
        return 0;
    }
    else if ((c.getCenter().getX()-p.getX()) * (c.getCenter().getX()-p.getX()) + (c.getCenter().getY()-p.getY()) * (c.getCenter().getY()-p.getY()) > c.getR() * c.getR())
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

int main ()
{
    Point p;
    p.setX(2);
    p.setY(3);

    Point center;
    center.setX(12);
    center.setY(13);
    Circle c;
    c.setCenter(center);
    c.setR(55);

    int ret = relation(c, p);
    if (ret == 0)
    {
        cout << "点在圆内!" << endl;
    }
    else if (ret == 1)
    {
        cout << "点在圆外!" << endl;
    }
    else
    {
        cout << "点在圆上内!" << endl;
    }
} 