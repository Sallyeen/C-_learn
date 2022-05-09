#include <iostream>
#include <string>

using namespace std;

struct hero
{
    string name;
    int age;
    string gender; 
};

void allocate (hero arr[], int len)
{   
    arr[0].name = "刘备";
    arr[0].age = 23;
    arr[0].gender = "男";
    arr[1].name = "关羽";
    arr[1].age = 22;
    arr[1].gender = "男";
    arr[2].name = "张飞";
    arr[2].age = 20;
    arr[2].gender = "男";
    arr[3].name = "赵云";
    arr[3].age = 21;
    arr[3].gender = "男";
    arr[4].name = "貂蝉";
    arr[4].age = 19;
    arr[4].gender = "女";
}

void bubble (hero arr[], int len)
{
    for (int i=0; i < len-1; i++)
    {
        for (int j=0; j<len-i-1; j++)
        {
            if (arr[j].age > arr[j+1].age)
            {
                struct hero temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printHero(hero arr[], int len)
{
    for (int i=0; i<len; i++)
    {
        cout << "第" << i << "名英雄的姓名为： " << arr[i].name << 
             ", 年龄为：　" << arr[i].age << ", 性别为： " << arr[i].gender << endl; 
    }
}

int main ()
{
    struct hero arr[5];
    int len = sizeof(arr) / sizeof(arr[0]);
    allocate(arr, len);
    printHero(arr, len);
    bubble(arr, len);
    cout << "对英雄按照年龄进行排序: " << endl;
    printHero(arr, len);
}