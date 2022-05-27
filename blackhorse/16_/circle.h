#pragma once
#include<iostream>
#include"point.h"

using namespace std;

class Circle
{
private:
    Point center ;
    int r;

public:
    void setCenter(Point center_new);
    Point getCenter();
    void setR(int r_new);
    int getR();
};