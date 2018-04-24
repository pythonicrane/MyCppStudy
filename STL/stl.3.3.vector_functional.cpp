/**------------------------------------------
* @Author: Zhao Heln
* @Time: 2018年4月24日15:50:42
* @Software: Visual Studio Code
* @Project: C++ STL标准程序库开发指南
* @Problem: vector+仿函数
* @Description：----------------------------*
------------------------------------------**/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Student
{
    public:
      int id;
      double score;
};

template<typename T> void Origin(T& vt)
{
    Student temp;
    temp.id = 1;
    temp.score = 90;
    vt.push_back(temp);
    temp.id = 2;
    temp.score = 95;
    vt.push_back(temp);
    temp.id = 3;
    temp.score = 98;
    vt.push_back(temp);
    temp.id = 4;
    temp.score = 97;
    vt.push_back(temp);
    temp.id = 5;
    temp.score = 95;
    vt.push_back(temp);
    temp.id = 6;
    temp.score = 90;
    vt.push_back(temp);

}

void output(const Student& stu)
{
    cout << "id: " << stu.id << " , score: " << stu.score << endl;
}

bool greater95(const Student& stu)
{
    if(stu.score>=95.0)
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
    vector<Student>::iterator iter;
    int countV = 0;
    Origin(myvt);
    for_each(myvt.begin(), myvt.end(), output);
    countV = count_if(myvt.begin(), myvt.end(), greater95);
    cout << "The number of the elements > 95.0: " << countV << endl;


    system("pause");
}