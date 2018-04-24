/**------------------------------------------
* @Author: Zhao Heln
* @Time: 2018年4月23日20:39:11
* @Software: Visual Studio Code
* @Project: C++ STL标准程序库开发指南
* @Problem: vector基础操作
* @Description：----------------------------*
------------------------------------------**/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void print(string& s)
{
    cout << s << endl;
}

int main()
{

    vector<string> myvt;/* vector定义 */
    //myvt[0] = "Hello";//容器未分配大小，不能进行下标操作；

    cout << "The size is " << myvt.size()<<endl;/* vector的大小和容量 */
    cout << "The capacity is " << myvt.capacity() << endl;
    myvt.reserve(4);
    cout << "The size is " << myvt.size()<<endl;
    cout << "The capacity is " << myvt.capacity() << endl;
    myvt.push_back("1. Beijing City");
    myvt.push_back("2. Tianjin City");
    myvt.push_back("3. Shanghai City");
    myvt.push_back("4. Chongqi City");
    for_each(myvt.begin(), myvt.end(), print);/* 容器的遍历 */
    myvt.resize(10);//多余的都是空字符串
    cout << "The size is " << myvt.size()<<endl;//会改变size值
    cout << "The capacity is " << myvt.capacity() << endl;
    for_each(myvt.begin(), myvt.end(), print);






    system("pause");
}