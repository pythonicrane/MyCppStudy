/**--------------------------------------------------------
* @Author: Zhao Heln
* @Time: 2018年4月24日20:49:06
* @Software: Visual Studio Code
* @Project: C++ STL标准程序库开发指南
* @Problem: vector的插入，删除
* @Description：------------------------------------------*
* push_back()，insert(),pop_back(),erase(),clear(),算法remove()
--------------------------------------------------------**/
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


void print(int& S)
{
    cout << S << ", ";
}

int main()
{
    vector<int> myvt;
    for (int i = 0; i < 10;++i)
    {
        myvt.push_back(i);
    }
    myvt.insert(myvt.begin(), -1);
    for_each(myvt.begin(), myvt.end(), print);
    cout << endl;
    myvt.insert(myvt.end(), -2);
    for_each(myvt.begin(), myvt.end(), print);
    cout << endl;
    vector<int> vec2;
    vec2.push_back(-8);
    vec2.push_back(-9);
    myvt.insert(myvt.end(), vec2.begin(), vec2.end());
    for_each(myvt.begin(), myvt.end(), print);
    cout << endl;
    myvt.insert(myvt.begin(), 3, 0);
    for_each(myvt.begin(), myvt.end(), print);
    cout << endl;

    cout << "-------Erase!:--------" << endl;
    myvt.pop_back();//一般使用pop_back()要用empty()进行检测
    myvt.pop_back();
    for_each(myvt.begin(), myvt.end(), print);
    cout << endl;
    myvt.erase(myvt.end() - 2, myvt.end());
    for_each(myvt.begin(), myvt.end(), print);
    cout << endl;
    myvt.erase(myvt.begin());
    for_each(myvt.begin(), myvt.end(), print);
    cout << endl;



    system("pause");
}