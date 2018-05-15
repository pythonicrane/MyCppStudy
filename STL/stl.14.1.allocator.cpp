/**-------------------------------------------------------------
* @Author       : Zhao Heln
* @Time         : 2018年5月15日16:35:58
* @Software     : Visual Studio Code
* @Project      : C++ STL标准程序库开发指南
* @Problem      : 配置器
* @Description  :
-------------------------------------------------------------**/
#include <algorithm>
#include <memory>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

// template<typename T> void myprint(vector<T>& vv)
// {
//     vector<T>::iterator it;
//     for (it = vv.begin(); it != vv.end();++it)
//     {
//         cout << *it <<',';
//     }
//     cout << endl;
// }

void myPrintA(allocator<int>::pointer vv,size_t num)
{
    int i;
    for (i = 0; i < num;++i)
    {
        cout << vv[i] << ",";
    }
    cout << endl;
}

int main()
{
    cout << "allocator test." << endl;
    vector<int> vl;
    vector<int>::iterator vlIt;
    vector<int>::allocator_type vlA;
    allocator<int>::const_pointer cvlp;
    allocator<int>::pointer vlp;
    allocator<int> AL;

    int i;
    for (i = 1; i < 9;++i)
    {
        vl.push_back(i);
    }
    cout << "The Original Vector vl:" << endl;
    copy(vl.begin(), vl.end(), ostream_iterator<int>(cout, ","));
    cout << endl;

    int kk = 6;
    cvlp = vlA.address(*find(vl.begin(), vl.end(), kk));//通过allocator取地址
    cout << "find an element by address. " << endl;
    cout << *cvlp << endl;

    vlp = AL.allocate(10);//通过Allocator类分配地址
    int ar[6] = {0, 9, 8, 7, 6, 5};
    copy(ar, ar + 6, vlp);
    cout << "array vlp:" << endl;
    myPrintA(vlp, 6);

    kk = 6;
    int kb = 12;
    vlp = vlA.address(*find(vl.begin(), vl.end(), kk));
    vlA.destroy(vlp);
    vlA.construct(vlp, kb);
    copy(vl.begin(), vl.end(), ostream_iterator<int>(cout, ","));
    cout << endl;


    system("pause");
}