#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int arr[10] = {1, 22, 13, 4, 56, 6, 27, 18, 91, 10};
    vector<int> vec= {1, 22, 13, 4, 56, 6, 27, 18, 91, 10};
    sort(arr, arr + 10);
    sort(vec.begin(), vec.end(), [](int a, int b) ->bool { return a > b; });
    for (int i = 0; i < 10;++i)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
    vector<int>::iterator vecBegin = vec.begin();
    for (; vecBegin != vec.end();vecBegin++)
    {
        cout << *vecBegin << ' ';
    }
    cout << endl;
    system("pause");
}