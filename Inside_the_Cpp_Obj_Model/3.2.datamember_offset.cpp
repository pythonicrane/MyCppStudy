/**-------------------------------------------------------------
* @Author       : Zhao Heln
* @Time         : 2018年6月8日20:51:25
* @Software     : Visual Studio Code
* @Project      : 深度探索C++对象模型
* @Problem      : nonstatic data member存取操作偏移问题-P98
* @Description  :
-------------------------------------------------------------**/
/* offsetof example */
#include <iostream>
#include <list>
#include <vector>
#include <stdio.h>      /* printf */
#include <stddef.h>     /* offsetof */

using namespace std;

struct foo {
	char a;
	char b[10];
	char c;
};

class Point3d
{
public:
	double x;
	static std::list<Point3d*> * freeList;
	char c;
	double y;
	static const int chunkSize = 250;
	double z;
};

int main()
{
	printf("offsetof(struct foo,a) is %d\n", (int)offsetof(struct foo, a));
	printf("offsetof(struct foo,b) is %d\n", (int)offsetof(struct foo, b));
	printf("offsetof(struct foo,c) is %d\n", (int)offsetof(struct foo, c));
	cout << (int)offsetof(Point3d, x) << endl;
	cout << (int)offsetof(Point3d, c) << endl;
	cout << (int)offsetof(Point3d, y) << endl;
	cout << (int)offsetof(Point3d, z) << endl;

	system("pause");
	return 0;
}