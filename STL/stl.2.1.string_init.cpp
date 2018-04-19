/**------------------------------------------
* @Author: Zhao Heln
* @Time: 2018年4月17日15:32:15
* @Software: Visual Studio Code
* @Project: C++ STL标准程序库开发指南
* @Problem: string初始化问题
* @Description：----------------------------*
*
--------------------------------------------*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str("12345678");
    char ch[] = "abcdefg";

    string a;//定义空符串
    string str_1(str);
    string str_2(str, 2, 5);
    string str_3(ch, 5);//复制ch字符串的前5个字符
    string str_4(5, 'x');
    string str_5(str.begin(), str.end());

    cout << str << endl;
    cout << a << endl;
    cout << str_1 << endl;
    cout << str_2 << endl;
    cout << str_3 << endl;
    cout << str_4 << endl;
    cout << str_5 << endl;

    system("PAUSE");
}