/**------------------------------------------
* @Author: Zhao Heln
* @Time: 2018年4月10日20:29:22
* @Software: Visual Studio Code
* @Project: CPP学习
* @Problem: 派生类属性和基类属性同名问题
* @Description：----------------------------*
* 如何访问被派生类隐藏的基类同名成员
--------------------------------------------*/
#include <iostream>
using namespace std;

class A
{
  public:
    int a;
    A(int aa = 1) { a = aa; }
    virtual void print()
    {
        cout << a << endl;
    }
};

class B : public A
{
  public:
    int a;
    B(int bb = 2) { a = bb; }
};

class C : public A
{
  public:
    int a;
    C(int cc = 3) { a = cc; }
    virtual void print()
    {
        cout << a << endl;
    }
};

int main()
{
    A ap;
    ap.print();

    B bp;
    bp.print(); //输出结果仍然为1

    C cp;
    cp.print(); //输出3

    system("PAUSE");
    return 0;
}