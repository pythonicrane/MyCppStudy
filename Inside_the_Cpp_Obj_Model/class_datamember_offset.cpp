/**-------------------------------------------------------------
* @Author       : Zhao Heln
* @Time         : 2018年6月12日20:05:13
* @Software     : Visual Studio Code
* @Project      : 深度探索C++对象模型
* @Problem      : 类datamember offset问题-P131
* @Description  :
-------------------------------------------------------------**/
#include <iostream>
using namespace std;

class Point3d {
public:
	//virtual ~Point3d();
	float x, y, z;

};




int main(int argc, char const *argv[])
{
	float Point3d::*p1 = 0;
	float Point3d::*p2 = &Point3d::x;//
	float Point3d::*p3 = &Point3d::z;

	Point3d origin;

	cout << &origin << endl;
	cout << &origin.z << endl;
	cout << &Point3d::z << endl;

	printf("Point3d::x: %p\n", &Point3d::x);//为了区分p1和p2,实际上p2会主动+1，但编译器做了特殊处理

	printf("oringin: %p\n", &origin);
	printf("oringin.z: %p\n", &origin.z);
	printf("Point3d::z: %p\n", &Point3d::z);//&origin = &origin.z +　&Point3d::z

	system("pause");
	return 0;
}