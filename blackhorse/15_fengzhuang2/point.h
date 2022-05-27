# pragma once
# include<iostream>
using namespace std;

class Point
{
private:
    int x;
    int y;
public:
    void setX(int x_new);
    int getX();

    void setY(int y_new);
    int getY();
};