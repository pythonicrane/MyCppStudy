/**------------------------------------------
* @Author: Zhao Heln
* @Time: 2018年4月10日19:36:01
* @Software: Visual Studio Code
* @Project: CPP学习
* @Problem: 派生类属性和基类属性同名问题
* @Description：----------------------------*
* 如何访问被派生类隐藏的基类同名成员
--------------------------------------------*/

#include <iostream>
using namespace std;

class Base
{
  public:
    int a = 10;

    void print()
    {
        cout << "Base: a=" << a << endl;
    }
};

class Derive : public Base
{
  public:
    int a = 20;
    void print()
    {
        cout << "DERIVE: a=" << a << endl;
        cout << "DERIVE TO Base: a=" << Base::a << endl; //使用域名限定
    }
};

int main()
{
    Base bc;
    Derive dc;

    bc.print();
    dc.print();
    cout << dc.Base::a << endl;
    system("PAUSE");
}