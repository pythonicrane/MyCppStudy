/**------------------------------------------
* @Author: Zhao Heln
* @Time: 2018年4月10日20:29:22
* @Software: Visual Studio Code
* @Project: CPP学习
* @Problem: 派生类属性和基类属性同名问题
* @Description：----------------------------*
* 如何访问被派生类隐藏的基类同名成员
--------------------------------------------*/
#include <iostream>
using namespace std;

int main()
{
    bool status = true;
    try
    {

        throw 42;
    }

    catch(int err)
    {
        cout << "err Int!" << endl;
        status = false;
    }

    //cout << "GO" << endl;

    catch(const char * test)
    {
        cout << "TEST" << endl;
        status = false;
    }

    cout << sizeof(char *) << endl;

    int intTempM = 10;
    int intTempN = 20;
    int &b = intTempM;
    cout << b << endl;
    b = intTempN;
    cout << b << endl;
    cout << intTempM << endl;

    int *p = 0;
    if(!p)
    {
        cout << "Hello NULL" << endl;
    }

    printf("%d", printf("hello wold"));
    system("PAUSE");
    return status;
}