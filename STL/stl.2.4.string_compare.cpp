/**------------------------------------------
* @Author: Zhao Heln
* @Time: 2018年4月19日11:04:59
* @Software: Visual Studio Code
* @Project: C++ STL标准程序库开发指南
* @Problem: string的compare()和比较运算符
* @Description：----------------------------*
*
------------------------------------------**/
#include <iostream>
#include <string>
using namespace std;

void TrueOrFalse(int x)
{
    cout << (x ? "True" : "False") << endl;
}

int main()
{
    string A("aBcdef");
    string B("AbcdEf");
    string C("123456");
    string D("123dfg");

    int m = A.compare(B);
    int n = A.compare(1, 5, B);
    int p = A.compare(1, 5, B, 4, 2); //参数列表(调用对象的起始位置，个数，比较的字符串，比较的字符串起始位，个数)
    int q = C.compare(0, 3, D, 0, 3); //相等的时候返回值为0

    cout << "m = " << m << ",n = " << n << ",p = " << p << ",q = " << q << endl;

    string S1 = "DEF";
    string CP1 = "ABC";
    string CP2 = "DEF";
    string CP3 = "DEFG";
    string CP4 = "def";

    cout << "S1<=CP1 returned ";
    TrueOrFalse(S1 <= CP1);
    cout << "S1<=CP2 returned ";
    TrueOrFalse(S1 <= CP2);
    cout << "S1<=CP3 returned ";
    TrueOrFalse(S1 <= CP3);
    cout << "CP3<=CP4 returned ";
    TrueOrFalse(CP3 <= CP4); //ASCII码值

    system("PAUSE");
}