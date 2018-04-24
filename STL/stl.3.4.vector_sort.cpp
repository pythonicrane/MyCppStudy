/**------------------------------------------
* @Author: Zhao Heln
* @Time: 2018年4月24日19:28:35
* @Software: Visual Studio Code
* @Project: C++ STL标准程序库开发指南
* @Problem: vector的排序
* @Description：----------------------------*
* vector自身没有sort成员函数
* sort(开始，结束，放函数)
------------------------------------------**/
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student
{
  public:
    Student(const string &a, double b) : name(a), score(b) {}
    string name;
    double score;
    bool operator<(const Student &m) const
    {
        return score < m.score;
    }
};

void Origin(vector<Student> &vt)
{
    Student st1("Tom", 4);
    vt.push_back(st1);
    st1.name = "Jimy";
    st1.score = 56;
    vt.push_back(st1);
    st1.name = "Mary";
    st1.score = 92;
    vt.push_back(st1);
    st1.name = "Jessy";
    st1.score = 85;
    vt.push_back(st1);
    st1.name = "Jone";
    st1.score = 56;
    vt.push_back(st1);
    st1.name = "Bush";
    st1.score = 52;
    vt.push_back(st1);
    st1.name = "Winter";
    st1.score = 77;
    vt.push_back(st1);
    st1.name = "Ander";
    st1.score = 63;
    vt.push_back(st1);
    st1.name = "Lily";
    st1.score = 76;
    vt.push_back(st1);
    st1.name = "Maryia";
    st1.score = 89;
    vt.push_back(st1);
}

bool name_sort_less(const Student &m, const Student &n)
{
    return m.name < n.name;
}

bool name_sort_greater(const Student &m, const Student &n)
{
    return m.name > n.name;
}

bool score_sort(const Student &m, const Student &n)
{
    return m.score > n.score;
}

void print(Student &S)
{
    cout.width(10);
    cout << left << S.name << "    " << S.score << endl;
}

bool greater95(const Student &stu)
{
    if (stu.score >= 95.0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{

    vector<Student> myvt;
    Origin(myvt);
    cout << myvt.size() << endl;
    cout << "----Before sorted.----" << endl;
    for_each(myvt.begin(), myvt.end(), print);
    sort(myvt.begin(), myvt.end());
    cout << "----After sorted by score.----" << endl;
    for_each(myvt.begin(), myvt.end(), print);
    sort(myvt.begin(), myvt.end(), name_sort_less);
    cout << "----After sorted by name.----" << endl;
    for_each(myvt.begin(), myvt.end(), print);
    sort(myvt.begin(), myvt.end(), name_sort_greater);
    cout << "----After sorted by name.----" << endl;
    for_each(myvt.begin(), myvt.end(), print);
    sort(myvt.begin(), myvt.end(), score_sort);
    cout << "----After sorted by score.----" << endl;
    for_each(myvt.begin(), myvt.end(), print);

    system("pause");
}