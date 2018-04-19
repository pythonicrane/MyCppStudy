/**------------------------------------------
* @Author: Zhao Heln
* @Time: 2018年3月27日20:33:11
* @Software: VScode
* @File: vector_exercise1.cxx
* @Problem:
* vector容器的5种初始化
--------------------------------------------*/
#include <vector>
#include <string>

using namespace std;

int main()
{
    string pooh[4] = {"winnie", "robin", "eeyore", "piglet"};
    vector<string> svec1;
    vector<string> svec2(4);
    vector<string> svec3(4,"dummy");
    vector<string> svec4(pooh, pooh + 4);
    vector<string> svec5(svec4);
}
