#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s("abcde");
    cout << s << endl;

    char &r = s[2];
    char *p = &s[3];//s是对象，不是数组名，所以不能直接代表地址(指针)
    r = 'X';
    *p = 'Y';
    cout<<s<<endl;

    s = "12345678";
    r = 'X';//指针和引用依旧可以修改
    *p = 'Y';
    cout<<s<<endl;
    system("PAUSE");

}