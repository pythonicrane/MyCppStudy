/**------------------------------------------
* @Author: Zhao Heln
* @Time: 2018年4月24日15:18:18
* @Software: Visual Studio Code
* @Project: C++ STL标准程序库开发指南
* @Problem: vector遍历
* @Description：----------------------------*
------------------------------------------**/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct ST
{
    int id;
    double db;
};

using namespace std;

void print(ST& s)
{
    cout << "id: " << s.id << ", db: " << s.db << endl;
}

void Iter_for(vector<ST>& vt)//不能加const，迭代器必须具备复制，修改属性！！！！！！
{
    for (vector<ST>::iterator iter=vt.begin(); iter != vt.end();iter++)
    {
        cout << "id: " << (*iter).id << ", db: " << (*iter).db << endl;
    }
}

void at_for(const vector<ST>& vt)
{
    int size = vt.size();
    for (int i = 0; i < size;i++)
    {
        cout << "id: " << vt.at(i).id << ", db: " << vt.at(i).db << endl;
    }
}

void br_for(const vector<ST>& vt)
{
    int size = vt.size();
    for (int i = 0; i < size;i++)
    {
        cout << "id: " << vt[i].id << ", db: " << vt[i].db << endl;
    }
}

void Origin(int num,vector<ST>& vt)
{
    ST temp;
    for (int i = 0; i <num;i++)
    {
        temp.id = i+1;
        temp.db = (i + 1) * 10;
        vt.push_back(temp);
    }
}

int main()
{
    ST temp;
    vector<ST> myvt;
    Origin(5, myvt);
    cout << "size: " << myvt.size() << endl;
    cout << "Iterator output!" << endl;
    Iter_for(myvt);
    cout << "at() output!" << endl;
    at_for(myvt);
    cout << "br output!" << endl;
    br_for(myvt);
    cout << "empty() usage:" << endl;
    while (!myvt.empty())
    {
        temp = myvt.back();
        print(temp);
        myvt.pop_back();
    }

    system("pause");
}