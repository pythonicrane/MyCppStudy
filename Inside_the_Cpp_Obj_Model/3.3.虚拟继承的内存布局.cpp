/**-------------------------------------------------------------
* @Author       : Zhao Heln
* @Time         : 2018年6月14日16:49:00
* @Software     : Visual Studio Code
* @Project      : 深度探索C++对象模型
* @Problem      : 虚拟继承的内存布局-P118
* @Description  :
-------------------------------------------------------------**/
#include <iostream>
using namespace std;

class Point2d {
public:
	float _x, _y;
};

class Point3d:public virtual Point2d{
public:
	float _z;
};

class Vertex :public virtual Point2d {
public:
	Vertex * next;
};

class Vertex3d :public Vertex, public Point3d {
public:
	float mumble;
};




int main()
{
	Vertex3d vt3d;


	system("pause");
	return 0;
}

//命令：/d1 reportAllClassLayout