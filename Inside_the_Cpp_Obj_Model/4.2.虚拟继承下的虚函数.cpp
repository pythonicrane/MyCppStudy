/**-------------------------------------------------------------
* @Author       : Zhao Heln
* @Time         : 2018年6月14日17:47:34
* @Software     : Visual Studio Code
* @Project      : 深度探索C++对象模型
* @Problem      : 虚拟继承下的虚函数-P168
* @Description  :
-------------------------------------------------------------**/
#include <iostream>
using namespace std;

class Point2d {
public:
	float _x, _y;
	Point2d(float = 0.0, float = 0.0) {};
	virtual ~Point2d() {};
	virtual void mumble() {};
	virtual float z() { return 0.0; };

};

class Point3d :public virtual Point2d {
public:
	float _z;
	Point3d(float = 0.0, float = 0.0, float = 0.0) {};
	~Point3d() {};
	float z() { return _z; };
};






int main()
{
	Point3d vt3d;


	system("pause");
	return 0;
}

//命令：/d1 reportAllClassLayout


/*

1>class Point2d	size(12):
1>	+---
1> 0	| {vfptr}
1> 4	| _x
1> 8	| _y
1>	+---
1>
1>Point2d::$vftable@:
1>	| &Point2d_meta
1>	|  0
1> 0	| &Point2d::{dtor}
1> 1	| &Point2d::mumble
1> 2	| &Point2d::z
1>
1>Point2d::{dtor} this adjustor: 0
1>Point2d::mumble this adjustor: 0
1>Point2d::z this adjustor: 0
1>Point2d::__delDtor this adjustor: 0
1>Point2d::__vecDelDtor this adjustor: 0
1>
1>class Point3d	size(24):
1>	+---
1> 0	| {vbptr}
1> 4	| _z
1>	+---
1>8	| (vtordisp for vbase Point2d)
1>	+--- (virtual base Point2d)
1>12	| {vfptr}
1>16	| _x
1>20	| _y
1>	+---
1>
1>Point3d::$vbtable@:
1> 0	| 0
1> 1	| 12 (Point3dd(Point3d+0)Point2d)
1>
1>Point3d::$vftable@:
1>	| -12
1> 0	| &(vtordisp) Point3d::{dtor}
1> 1	| &Point2d::mumble
1> 2	| &(vtordisp) Point3d::z
1>
1>Point3d::{dtor} this adjustor: 12
1>Point3d::z this adjustor: 12
1>Point3d::__delDtor this adjustor: 12
1>Point3d::__vecDelDtor this adjustor: 12
1>vbi:	   class  offset o.vbptr  o.vbte fVtorDisp
1>         Point2d      12       0       4 1

*/