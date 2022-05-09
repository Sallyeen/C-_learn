#include <iostream>
#include <cstdlib>
#include <string>
#define MAX 1000

using namespace std;

// 菜单功能: 写一个showmenu封装好的函数，在main调用
void showMenu()
{
    cout << "*************************" << endl;
    cout << "*****  1、添加联系人  *****" << endl;
    cout << "*****  2、显示联系人  *****" << endl;
    cout << "*****  3、删除联系人  *****" << endl;
    cout << "*****  4、查找联系人  *****" << endl;
    cout << "*****  5、修改联系人  *****" << endl;
    cout << "*****  6、清空联系人  *****" << endl;
    cout << "*****  0、退出通讯录  *****" << endl;
    cout << "*************************" << endl;
}

// 联系人结构体
struct person
{
    string name;
    int gender;
    int age;
    string phone;
    string address;
};

// 通讯录结构体
struct mailList
{
    struct person personArr[MAX];
    int size;
};

// 添加联系人
void addPerson(mailList * mlt)
{
    // 首先判断通讯录是否已满，满了不再添加
    if (mlt->size == MAX)
    {
        cout << "通讯录已满，不可继续添加！" << endl;
    }
    else
    {
        string name_in;
        cout << "请输入姓名： " << endl;
        cin >> name_in;
        mlt->personArr[mlt->size].name = name_in;
        
        int gender_in;
        cout << "请输入性别： " << endl;
        cout << "1 --- 男： " << endl;
        cout << "2 --- 女： " << endl;
        while (true)
        {
            cin >> gender_in;
            if (gender_in != 1 && gender_in != 2)
            {
                cout << "输入不合法，请输入 1 或者 2 ： " << endl;
            }
            else{
                mlt->personArr[mlt->size].gender = gender_in;
                break;
            }
        }
        
        int age_in;
        cout << "请输入年龄： " << endl;
        while (true)
        {
            cin >> age_in;
            if (age_in >= 0 && age_in <= 120)
            {
                mlt->personArr[mlt->size].age = age_in;
                break;
            }
            cout << "请输入合理的年龄！" << endl;
        }
                
        string phone_in;
        cout << "请输入电话： " << endl;
        cin >> phone_in;
        mlt->personArr[mlt->size].phone = phone_in;
        
        string address_in;
        cout << "请输入地址： " << endl;
        cin >> address_in;
        mlt->personArr[mlt->size].address = address_in;

        // 更新通讯录人数
        mlt->size++;

        cout << "添加成功!" << endl;

        system("pause");
        system("cls");
    }
}

// 显示联系人
void showPerson(mailList * mlt)
{
    if (mlt->size == 0)
    {
        cout << "通讯录中没有任何联系人!" << endl;
    }
    for (int i=0; i<mlt->size; i++)
    {
        cout << "姓名：" << mlt->personArr[i].name << "\t";
        cout << "性别：" << (mlt->personArr[i].gender == 1 ? "男":"女") << "\t";
        cout << "年龄：" << mlt->personArr[i].age<< "\t";
        cout << "电话：" << mlt->personArr[i].phone << "\t";
        cout << "住址：" << mlt->personArr[i].address << "\t";
    }
    system("pause");
    system("cls");
}
 
//判断联系人是否存在？返回位置：返回-1
int isExist(mailList * mlt, string name_)
{
    for (int i=0; i<mlt->size; i++)
    {
        if (mlt->personArr[i].name == name_)
        {
            return i;
        }
        else
        {
            return -1;
        }
    }
}

void delPerson (mailList * mlt)
{
    cout << "请输入要删除的联系人姓名：" << endl;
    string name_in;
    cin >> name_in;
    int ret = isExist(mlt, name_in);
    if (ret == -1)
    {
        cout << "查无此人！" << endl;
    }
    else
    {
        cout << "找到此人!" << endl;
        for (int i = ret; i<mlt->size; i++)
        {
            //数据前移
            mlt->personArr[i] = mlt->personArr[i+1];
        }
        mlt->size--;
        cout << "删除成功！" << endl;
    }
    system("pause");
    system("cls");
}

void findPerson(mailList * mlt)
{
    cout << "请输入您要查找的联系人：" << endl;
    string name_;
    cin >> name_;
    int ret = isExist(mlt, name_);
    if (ret != -1)
    {
        cout << "姓名：" << mlt->personArr[ret].name << "\t";
        cout << "性别：" << mlt->personArr[ret].gender << "\t";
        cout << "年龄：" << mlt->personArr[ret].age << "\t";
        cout << "电话：" << mlt->personArr[ret].phone << "\t";
        cout << "地址：" << mlt->personArr[ret].address << "\t";
    }
    else
    {
        cout << "查无此人" << endl;
    }
    system("pause");
    system("cls");
}

void modifyPerson (mailList * mlt)
{
    cout << "请输入您要修改的联系人：" << endl;
    string name_;
    cin >> name_;
    int ret = isExist(mlt, name_);
    if (ret != -1)
    {
        string name_;
        cout << "请输入姓名：" << endl;
        cin >> name_;
        mlt->personArr[ret].name = name_;
        int gender_;
        cout << "请输入性别：" << endl;
        cout << "1 --- 男" << endl;
        cout << "2 --- 女" << endl;
        while (true)
        {
            cin >> gender_;
            if (gender_ == 1 || gender_ == 2)
            {
                mlt->personArr[ret].gender;
                break;
            }
            cout << "输入有误，请重新输入：" << endl;
        }
        string age_;
        cout << "请输入年龄：" << endl;
        cin >> age_;
        mlt->personArr[ret].age ;
        string phone_;
        cout << "请输入电话：" << endl;
        cin >> phone_;
        mlt->personArr[ret].phone ;
        string address_;
        cout << "请输入地址：" << endl;
        cin >> address_;
        mlt->personArr[ret].address ;
    }
    else
    {
        cout << "查无此人" << endl;
    }
    system("pause");
    system("cls");
}

void cleanPerson(mailList * mlt)
{
    mlt->size = 0;
    cout << "通讯录已清空：" << endl;
    system("pause");
    system("cls");
}

int main ()
{
    // 创建通讯录,并初始化人员个数
    mailList mlt;
    mlt.size = 0;
    
    int select; //用户选择输出的变量

    while (true)
    {
        // 菜单调用
        showMenu();

        cin >> select;
        switch (select)
        {
        case 1: // 添加
            addPerson(&mlt); // 利用地址传递可修改实参
            break;
        case 2: // 显示
            showPerson(&mlt);
            break;
        case 3: // 删除
            delPerson(&mlt);
            break;
        case 4: // 查找
            findPerson(&mlt);
            break;
        case 5: // 修改
            /* code */
            break;
        case 6: // 清空
            /* code */
            break;
        case 0: // 退出
            cout << "欢迎下次使用" << endl;
            system("pause");
            return 0;
            break;    
        default:
            break;
        }
    }
} 