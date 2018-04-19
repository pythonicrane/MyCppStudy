/**------------------------------------------
* @Author: Zhao Heln
* @Time: 2018年4月17日15:32:15
* @Software: Visual Studio Code
* @Project: C++ STL标准程序库开发指南
* @Problem: string大小和容量
* @Description：----------------------------*
*
--------------------------------------------*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str("12345678");
    string str_custom;
    str_custom.reserve(5);
    str_custom = str;
    cout << "string:" << str_custom << endl;
    cout << "size = " << str_custom.size() << endl;
    cout << "length = " << str_custom.length() << endl;
    cout << "maxsize = " << str_custom.max_size() << endl;
    cout << "capacity = " << str_custom.capacity() << endl;

    str_custom.resize(5);
    cout << "string:" << str_custom << endl;
    cout << "size = " << str_custom.size() << endl;
    cout << "length = " << str_custom.length() << endl;
    cout << "maxsize = " << str_custom.max_size() << endl;
    cout << "capacity = " << str_custom.capacity() << endl;


    system("PAUSE");
}