/**-------------------------------------------------------------
* @Author       : Zhao Heln
* @Time         : 2018年6月14日17:33:50
* @Software     : Visual Studio Code
* @Project      : 深度探索C++对象模型
* @Problem      : 多重继承vftable的内存布局-P118
* @Description  :
-------------------------------------------------------------**/
#include <iostream>
using namespace std;

class Base1 {
public:
	Base1();
	virtual ~Base1() {};
	virtual void speakClearly() {};
	virtual Base1 *clone() const {};
protected:
	float data_Base1;
};

class Base2 {
public:
	Base2();
	virtual ~Base2() {};
	virtual void mumble() {};
	virtual Base2* clone() const {};
protected:
	float data_Base2;
};

class Derived :public Base1, public Base2 {
public:
	Derived();
	virtual ~Derived() {};
	virtual Derived *clone(Derived* b1) const { return b1; };
protected:
	float data_Derived;
};




int main()
{
	Derived drobj;


	system("pause");
	return 0;
}

//命令：/d1 reportAllClassLayout

/*

1>class Derived	size(20):
1>	+---
1> 0	| +--- (base class Base1)
1> 0	| | {vfptr}
1> 4	| | data_Base1
1>	| +---
1> 8	| +--- (base class Base2)
1> 8	| | {vfptr}
1>12	| | data_Base2
1>	| +---
1>16	| data_Derived
1>	+---
1>
1>Derived::$vftable@Base1@:
1>	| &Derived_meta
1>	|  0
1> 0	| &Derived::{dtor}
1> 1	| &Base1::speakClearly
1> 2	| &Derived::clone
1>
1>Derived::$vftable@Base2@:
1>	| -8
1> 0	| &thunk: this-=8; goto Derived::{dtor}
1> 1	| &Base2::mumble
1> 2	| &thunk: this-=8; goto Base2* Derived::clone//thunk机制，会根据返回类型生成多种
1> 3	| &thunk: this-=8; goto Derived* Derived::clone

*/