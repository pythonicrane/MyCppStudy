/**-------------------------------------------------------------
* @Author       : Zhao Heln
* @Time         : 2018年5月14日13:56:19
* @Software     : Visual Studio Code
* @Project      : 算法
* @Problem      : 合数的因式分解
* @Description  :
*
-------------------------------------------------------------**/
#include <iostream>
#include <iterator>
#include <vector>
#include <cmath>

using namespace std;

void fun(int num,vector<int>& result)
{
    int i = 2;
    int k = num;
    while (i < sqrt(k)) //注意保存副本，而不是直接num;
    {
        if(num%i == 0)
        {
            result.push_back(i);
            num /= i;
        }else
        {
            ++i;
        }
    }
}

int main()
{
    int num;
    vector<int> result;
    cin >> num;
    fun(num, result);

    copy(result.begin(), result.end(), ostream_iterator<int>(cout, ","));
    system("pause");
}