/**-------------------------------------------------------------
* @Author       : Zhao Heln
* @Time         : 2018年6月8日15:32:47
* @Software     : Visual Studio Code
* @Project      : 深度探索C++对象模型
* @Problem      : NRV编译器优化问题-P67
* @Description  :
-------------------------------------------------------------**/
#include<iostream>

using namespace std;

class Test
{
public:
	Test()
		: m_x(0), m_y(0) {
		std::cout << "Test structor" << std::endl;
	}


	Test(const Test &tst)
		: m_x(tst.m_x), m_y(tst.m_y) {
		std::cout << "Test copy structor" << std::endl;
	}


	~Test()
	{
		std::cout << "Test destructor" << std::endl;
	}



	void setX(int x) { m_x = x; }
	void setY(int y) { m_y = y; }

private:
	int m_x;
	int m_y;
};

Test func(int x, int y)
{
	Test xx;



	xx.setX(x);
	xx.setY(y);



	return xx;
}


int main()
{
	int x = 10;
	int y = 20;
	Test tt = func(x, y);//********GCC会优化，只产生一次对象，VS会产生临时变量


	system("pause");
	return 0;
}