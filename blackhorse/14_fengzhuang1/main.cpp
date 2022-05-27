#include <iostream>

using namespace std;

// 设计立方体类，求面积与体积，用全局函数和成员函数判断两个立方体是否相等
class Cube
{
private:
    int l, w, h;
public:
    void setL(int l_new)
    {
        l = l_new;
    }

    void setW(int w_new)
    {
        w = w_new;
    }

    void setH(int h_new)
    {
        h = h_new;
    }
    
    int getL()
    {
        return l;
    }

    int getW()
    {
        return w;
    }

    int getH()
    {
        return h;
    }

    void getM()
    {
        int M = 2 * (l * w + h * w + l * h);
        cout << "面积为: " << M << endl;
    }

    void getT()
    {
        int T = l * w * h;
        cout << "体积为: " << T << endl;
    }

    void compare_byclass(Cube& c)
{
    if (h == c.getH() && w == c.getW() && l == c.getL())
    {
        cout << "一样！" << endl;
    }
    cout << "   不一样！" << endl;
}
};

void compare_(Cube& c1, Cube& c2)
{
    if (c1.getH() == c2.getH() && c1.getW() == c2.getW() && c1.getL() == c2.getL())
    {
        cout << "一样！" << endl;
    }
    cout << "   不一样！" << endl;
}

int main ()
{
    Cube cube1;
    cube1.setH(2);
    cube1.setW(3);
    cube1.setL(4);
    cube1.getM();
    cube1.getT();
    Cube cube2;
    cube2.setH(2);
    cube2.setW(4);
    cube2.setL(3);
    cube2.getM();
    cube2.getT();
    compare_(cube1, cube2);
    cube1.compare_byclass(cube2);
} 