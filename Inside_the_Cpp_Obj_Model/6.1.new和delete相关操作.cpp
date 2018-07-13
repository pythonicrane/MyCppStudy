/**-------------------------------------------------------------
* @Author       : Zhao Heln
* @Time         : 2018年7月13日10:29:53
* @Software     : Visual Studio Code
* @Project      : 深度探索C++对象模型
* @Problem      : new和deletec操作
* @Description  :
-------------------------------------------------------------**/
#include <iostream>
using namespace std;

class point {
public:
	point(double x= 0, double y= 0):_x(x),_y(y) {
		cout << "point constructor" << endl;
	};
	~point() {
		cout << "point destructor" << endl;
	}
private:
	double _x;
	double _y;
};

class point3D :public point{
public:
	point3D(double x = 0, double y = 0, double z = 0) :point(x,y),_z(z) {
		cout << "point3D constructor" << endl;
	};
	~point3D() {
		cout << "point3D destructor" << endl;
	};
private:
	double _z;
};


int main()
{

	cout << "1" << endl;
	point * ptr = new point3D[2];
	cout << "2" << endl;



	//delete []ptr;//只会调用point的desturctor,导致内存泄露！！！！！！！！
	delete []((point3D*)ptr);
	cout << "3" << endl<<endl;

	point * ptr2 = new point3D();
	delete ptr2;//同理，只会调用基类的destructor.

	system("PAUSE");
}

/*
1.若类无默认构造函数，new不会调用vec_new，仅仅做内存分配，调用malloc
2.delete基类的指针，只能释放相应的基类大小数据。
3.或者可以使用虚析构函数，则会正确删除派生类。
*/