#include <iostream>
using namespace std;

class A
{
  private:
    const int count = 0; // 静态整型常量成员可以在类内初始化，但是 static const float count就不行了
};

int main()
{
    const int x = 1;
    int b = 10;
    int c = 20;

    const int *a1 = &b;
    int *const a2 = &b;
    const int *const a3 = &b;

    a1 = &c;

    system("PAUSE");
}