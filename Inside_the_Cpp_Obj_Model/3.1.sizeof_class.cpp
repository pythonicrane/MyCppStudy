/**-------------------------------------------------------------
* @Author       : Zhao Heln
* @Time         : 2018年6月8日17:06:10
* @Software     : Visual Studio Code
* @Project      : 深度探索C++对象模型
* @Problem      : 类对象的大小问题-P82
* @Description  :
-------------------------------------------------------------**/
#include <iostream>
using namespace std;

class X{
};

class Y:virtual public X{
};

class Z:virtual public X{
};

class W:public Y,public Z{
};

int main(int argc, char const *argv[])
{
    cout << sizeof(X)<<endl;//空类会产生一个字节的占位符
    cout << sizeof(Y)<<endl;//虚继承，会产生VPTR指针，4个字节(32位系统)
    cout << sizeof(Z)<<endl;
    cout << sizeof(W)<<endl;

    double *p;
    cout << sizeof(p) << endl;

    system("pause");
    return 0;
}

