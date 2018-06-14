/**-------------------------------------------------------------
* @Author       : Zhao Heln
* @Time         : 2018年6月8日17:06:10
* @Software     : Visual Studio Code
* @Project      : 深度探索C++对象模型
* @Problem      : 类对象的大小问题-P82
* @Description  :
* 1.GCC会对空类插入一个字节，边界对齐会加三个字节
* 2.VS编译器只有在X类的情况才会插入一个字节，并对齐
* 3.空类指的是没有 data member，B2类GCC会插入空字节
* 4.64位系统，指针是8个字节，8*8 = 64位
* 5.虚函数和虚继承会产生指针，GCC是一个，VS编译器会分开
* 6.成员函数保存在代码区，不单独分配内存
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


class A {
	int x, y, z;
};
class B1 : public virtual X {

};
class B2 : public virtual X {
	virtual void f() {
        cout << "Hello" << endl;
    }
public:
    void print()
    {
        cout << "Print"<<endl;
    }
};
class C : public B1, public B2 {
};

void p(){}

int main(int argc, char const *argv[])
{
    cout << sizeof(X)<<endl;//空类会产生一个字节的占位符
    cout << sizeof(Y)<<endl;//虚继承，会产生VPTR指针，4个字节(32位系统)
    cout << sizeof(Z)<<endl;
    cout << sizeof(W)<<endl;

    double *p;
    cout << sizeof(p) << endl;

	cout << "int:" << sizeof(int) << endl;
	cout << "A:" << sizeof(A) << endl;
	cout << "B1:" << sizeof(B1) << endl;
	cout << "B2:" << sizeof(B2) << endl;
	cout << "C:" << sizeof(C) << endl;


    system("pause");
    return 0;
}



