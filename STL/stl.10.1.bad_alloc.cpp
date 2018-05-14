#include <new>
#include <iostream>
using namespace std;

void __cdecl newhander()
{
    cout << "The new_hander is called: " << endl;
    throw bad_alloc();
    return;
}

int main()
{
    set_new_handler(newhander);
    try
    {
        while (1)
        {
            new int[500000000];
            cout << "Alloacating 500000000 ints." << endl;
        }
    }
    catch (exception e)
    {
        cout << e.what() << " xxx " << endl;
    }
    system("pause");
}