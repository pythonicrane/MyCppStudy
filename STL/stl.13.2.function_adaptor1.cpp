/**-------------------------------------------------------------
* @Author       : Zhao Heln
* @Time         : 2018年5月14日20:39:05
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
    virtual void print() = 0;
};

class D1 : public B
{
  public:
    void print()
    {
        cout << "I`m a D1." << endl;
    }
};

class D2 : public B
{
  public:
    void print()
    {
        cout << "I`m a D2." << endl;
    }
};

int main()
{
    vector<B *> v;
    v.push_back(new D1);
    v.push_back(new D2);
    v.push_back(new D2);
    v.push_back(new D1);
    for_each(v.begin(), v.end(), mem_fun(&B::print));//将类成员函数转换为仿函数，容器存的是指针

    vector<vector<int> *> v2;
    v2.push_back(new vector<int>(5));
    v2.push_back(new vector<int>(3));
    v2.push_back(new vector<int>(4));
    transform(v2.begin(), v2.end(), ostream_iterator<int>(cout, ","), mem_fun(&vector<int>::size));
    cout << endl;

    vector<D1> vD1;
    vD1.push_back(D1());
    vD1.push_back(D1());
    for_each(vD1.begin(), vD1.end(), mem_fun_ref(&B::print));//将类成员函数转换为仿函数，容器存的是对象
    vector<vector<int>> vint2;
    vint2.push_back(vector<int>(2));
    vint2.push_back(vector<int>(7));
    vint2.push_back(vector<int>(3));
    transform(vint2.begin(), vint2.end(), ostream_iterator<int>(cout, ","), mem_fun_ref(&vector<int>::size));
    cout << endl;


    system("pause");
}