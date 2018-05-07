#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;


int main()
{
    vector<int> vt(10, 1);
    if(vt.size()>1)
    {
        sort(++vt.begin(), vt.end());
    }
    copy(vt.begin(), vt.end(), ostream_iterator<int>(cout,","));
    system("PAUSE");
}