/**------------------------------------------
* @Author: Zhao Heln
* @Time: 2018年4月23日20:39:11
* @Software: Visual Studio Code
* @Project: C++ STL标准程序库开发指南
* @Problem: string的查找
* @Description：----------------------------*
*
*
*
------------------------------------------**/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str("Hi,Peter,I`m Sick.Please bought some drugs for me.");
    string str_ch("for");

    cout << "str.find()" << endl;
    cout << str.find('P') << endl;
    cout << str.find('P', 5)<<endl;
    cout << str.find("m") << endl;
    cout << str.rfind("m") << endl;//返回从后搜索遇到的第一个匹配的位置
    cout << str.rfind("Pe") << endl;
    cout << str.rfind("ep") << endl;//逆序查找仅仅是从后搜索，并不是将源字符串反序了
    cout << str.find(str_ch)<<endl;
    cout << str.find("form", 0, 3) << endl;//第三个参数查找待查字符串的前n个
    cout << str.find("form", 0, 6) << endl;//第三个参数超过第一个参数长度直接查找失败
    cout << str.find("zhao") << endl;//未查找到返回str.npos,size_type类型，无符号。
    if(str.find("zhao")== -1)
    {
        cout << "not find this" << endl;
    }

    cout << "str.find_first_of()" << endl;
    cout << str.find("some") << endl;
    cout << str.find_first_of("some") << endl;//查找返回匹配到的第一个待查字符串中的任意一个字符
    cout << str.find_last_of("some") << endl;//查找返回匹配到的最后一个待查字符串中的任意一个字符
    cout << str.find_last_of("some",str.size()-1,3) << endl;

    cout << "str.find_first_not_of()" << endl;
    cout << str.find_first_not_of("some") << endl;//查找返回匹配到的第一个不是待查字符串中的任意一个字符
    cout << str.find_last_not_of("some") << endl;//查找返回匹配到的最后一个不是待查字符串中的任意一个字符
    cout << str.find_last_not_of("some",str.size()-1,3) << endl;



    system("pause");
}