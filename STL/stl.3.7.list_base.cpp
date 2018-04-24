/**-------------------------------------------------------------
* @Author       : Zhao Heln
* @Time         : 2018年4月24日21:47:12
* @Software     : Visual Studio Code
* @Project      : C++ STL标准程序库开发指南
* @Problem      : List的基本操作
* @Description  :
* 初始化，
-------------------------------------------------------------**/
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <list>

using namespace std;


void print(int& S)
{
    cout << S << ", ";
}

int main()
{
    /*List 初始化*/
    list<int> listi_1;//空链表
    list<int> listi_2(10);//初始化size为10的链表
    list<int> listi_3(10, 0);//初始化size为10个值为0的链表
    list<int> listi_4(listi_3);//对象初始化
    list<int> listi_5(listi_3.begin(), listi_3.end());//迭代器初始化

    /*List 元素的赋值*/
    listi_1.push_front(10);//********vector在头部操作效率很低，所以没有push_front()********
    listi_1.push_back(1);
    listi_1.push_back(2);
    listi_1.push_back(3);
    listi_1.push_back(-10);
    listi_1.pop_back();
    listi_1.pop_front();

    /*List 容量操作*/
    for_each(listi_1.begin(), listi_1.end(), print);
    cout << endl;
    cout << "listi_1 size: " << listi_1.size() << endl;
    cout << "listi_1 max_size: " << listi_1.max_size() << endl;
    listi_1.resize(2);
    for_each(listi_1.begin(), listi_1.end(), print); //*******ist没有capacity();*********
    cout << endl;

    /*List 迭代器*/
    //begin(),end(),rbegin(),rend(),back(),front();


    system("pause");
}
