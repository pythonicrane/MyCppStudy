/**-------------------------------------------------------------
* @Author       : Zhao Heln
* @Time         : 2018年5月14日21:21:08
* @Software     : Visual Studio Code
* @Project      : C++ STL标准程序库开发指南
* @Problem      : 仿函数-适配器
* @Description  :
* 1.绑定器；
* 2.成员函数适配器；
* 3.函数指针适配器；
* 4.取反器；
-------------------------------------------------------------**/
#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

class B
{
  public:
    virtual int add(int x) = 0;
};

class D : public B
{
  public:
    D(int x) : val(x){};
    int add(int x)
    {
        return val + x;
    }
  private:
    int val;
};

class Operation
{
    public:
        virtual double eval(double) = 0;
};

class Square:public Operation
{
    public:
     double eval(double x)
     {
         return x *x;
     }
};

class Negate:public Operation
{
    public:
     double eval(double x)
     {
         return -x;
     }
};


int main()
{
    vector<Operation *> op;//容器存放的是指针类型
    vector<double> oprands;
    op.push_back(new Square);
    op.push_back(new Square);
    op.push_back(new Negate);
    op.push_back(new Negate);
    op.push_back(new Square);
    oprands.push_back(1);
    oprands.push_back(2);
    oprands.push_back(3);
    oprands.push_back(4);
    oprands.push_back(5);
    //mem_fun()调用的是第一个容器的函数
    transform(op.begin(), op.end(), oprands.begin(), ostream_iterator<double>(cout, ","), mem_fun(&Operation::eval));
    cout << endl;

    vector<B *> vB;
    vB.push_back(new D(3));
    vB.push_back(new D(4));
    vB.push_back(new D(5));
    int A[3] = {7, 8, 9};
    transform(vB.begin(), vB.end(), A, ostream_iterator<int>(cout, " "), mem_fun(&B::add));
    cout << endl;

    vector<D> vD;
    vD.push_back(D(1));
    vD.push_back(D(2));
    vD.push_back(D(3));
    transform(vD.begin(), vD.end(), A, ostream_iterator<int>(cout, " "), mem_fun_ref(&B::add));//容器存放的是实体对象
    cout << endl;

    system("pause");
}