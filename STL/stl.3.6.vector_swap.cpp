/**-------------------------------------------------------------
* @Author       : Zhao Heln
* @Time         : 2018年4月24日20:49:06
* @Software     : Visual Studio Code
* @Project      : C++ STL标准程序库开发指南
* @Problem      : vector的swap
* @Description  :
* !不同类型的vector不能交换，例如：vector<int>和vector<string>
-------------------------------------------------------------**/
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
    vector<int> ci,cd;
    for (int i = 0; i < 10;++i)
    {
        ci.push_back(i);
        cd.push_back(i * 3);
    }
    ci.push_back(10);
    cout << "vector-ci-below:" << endl;
    for_each(ci.begin(), ci.end(), print);
    cout << endl;
    cout << "vector-cd-below:" << endl;
    for_each(cd.begin(), cd.end(), print);
    cout << endl;
    cout << "--------swap--------" << endl;
    ci.swap(cd);
    cout << "vector-ci-below:" << endl;
    for_each(ci.begin(), ci.end(), print);
    cout << endl;
    cout << "vector-cd-below:" << endl;
    for_each(cd.begin(), cd.end(), print);



    system("pause");
}