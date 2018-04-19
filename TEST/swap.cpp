#include <iostream>

using namespace std;

void swap1(int& val1,int& val2)
{
    int temp = val1;
    val1 = val2;
    val2 = temp;
}

void display( const int vec[])
{
    for (int i = 0; i < 8;++i)
    {
        cout << vec[i] << " ";
    }
    cout<<endl;
}

int main()
{
    int vec[8] = {8, 32, 3, 13, 1, 21, 5, 2};
    display(vec);
    swap1(vec[0],vec[1]);
    display(vec);

    system("pause");
}