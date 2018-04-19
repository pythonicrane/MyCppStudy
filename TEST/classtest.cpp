#include <iostream>

using namespace std;

class Test
{
    public:
        int *p;
};



int main()
{
    Test A;
    Test B;
    int i = 10;
    A.p = &i;
    B = A;

    *(A.p) = 20;

    cout << *(B.p);
    system("PAUSE");
    return 0;
}