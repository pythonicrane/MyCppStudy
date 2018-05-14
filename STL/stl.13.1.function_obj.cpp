/**-------------------------------------------------------------
* @Author       : Zhao Heln
* @Time         : 2018年5月14日16:35:52
* @Software     : Visual Studio Code
* @Project      : C++ STL标准程序库开发指南
* @Problem      : 仿函数-字符串长度筛选
* @Description  :
* 1.仿函数判断式返回bool;
* 2.仿函数内容返回；
* 3.仿函数对象作为for_each返回对象；
* 4.lamda表达式；
-------------------------------------------------------------**/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <functional>
#include <iterator>
using namespace std;

//函数，用于筛选字符串长度
bool LenghtLessThanFive(const string& str)
{
    return str.length() < 5;
}

//不支持二元参数
bool LenghtLessThan(const string& str,int len)
{
    return str.length() < len;
}

//函数对象，解决多个参数问题
class ShorterThan
{
    public:
        explicit ShorterThan(int MaxLength):length(MaxLength){}

        bool operator()(const string& str) const
        {
            return str.length() < length;
        }


    private:
      const int length;
};

//函数对象，用于生成数字序列
class Sequence
{
    public:
      Sequence(int val) : value(val){};

      int operator()()
      {
          return ((value++) * 2 + 1);
      }

    private:
      int value;
};

//作为for_each()的返回值
class meanV
{
    private:
      long num;
      long sum;

    public:
      meanV() : num(0), sum(0){};
      void operator()(long val)
      {
          num++;
          sum += val;
      }
      long value()
      {
          return sum / num;
      }
};


int main()
{
    vector<string> vct;
    vct.push_back("Hello");
    vct.push_back("I");
    vct.push_back("am");
    vct.push_back("pythonic");
    vct.push_back("nice");
    vct.push_back("to");
    vct.push_back("meet");
    vct.push_back("you");

    cout << count_if(vct.begin(), vct.end(), LenghtLessThanFive) << endl;
    cout << count_if(vct.begin(), vct.end(), ShorterThan(3)) << endl;
    int x = 3;
    cout << count_if(vct.begin(), vct.end(), [x](string str) { return str.length() < x; })<<endl;//lamda表达式

    vector<int> vcti;
    generate_n(back_inserter(vcti),5,Sequence(0));
    copy(vcti.begin(),vcti.end(),ostream_iterator<int>(cout,","));
    cout << endl;

    meanV mv = for_each(vcti.begin(), vcti.end(), meanV()); //meanV()产生临时对象，并复制给mv;
    cout <<"value: "<< mv.value() << endl;

    system("pause");
}
