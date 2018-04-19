/**------------------------------------------
* @Author: Zhao Heln
* @Time: 2018年4月19日15:33:46
* @Software: Visual Studio Code
* @Project: C++ STL标准程序库开发指南
* @Problem: string的赋值，修改，替换，插入，删除
* @Description：----------------------------*
*
------------------------------------------**/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    //赋值
    string str1("123456789");
    string str;
    str.assign(str1);
    cout << str << endl;
    str.assign(str1, 3, 3); //复制对象,起始位置，字符个数
    cout << str << endl;
    str.assign(str1, 3, 300); //个数超过最大个数时候就整体复制
    cout << str << endl;
    cout << str1.npos << endl;
    str.assign(str1, 2, str1.npos); //最大个数
    cout << str << endl;
    str.assign(5, 'x'); //不写做('x',5);
    cout << str << endl;
    str.assign(str1.begin(), str1.end()); //迭代器赋值,左右边界都不能超，否则乱码
    cout << str << endl;

    //删除
    str.erase(3); //从下标为3开始删除到最后:str.erase(3,str.npos)
    cout << str << endl;
    str = str1;
    str.erase(str.begin() + 2);
    cout << str << endl;
    str = str1;
    str.erase(str.begin(), str.end() - 4);
    cout << str << endl;

    //交换
    string strSwap1 = "Hello the world"; //复制
    string strSwap2("Luky for you");     //移动操作，少产生内存消耗
    strSwap1.swap(strSwap2);
    cout << strSwap1 << " - " << strSwap2 << endl;

    //插入
    string A("ello");
    string B("H");
    B.insert(1, A);
    cout << B << endl;
    A.assign("ello");
    B.assign("H");
    B.insert(1, "yanchy", 3);
    cout << B << endl;
    A.assign("ello");
    B.assign("H");
    B.insert(1, A, 2, 2); //插入位置，插入字符串，插入字符串起始点，个数
    cout << B << endl;
    A.assign("ello");
    B.assign("H");
    B.insert(1, 5, 'x');
    cout << B << endl;
    A.assign("ello");
    B.assign("H");
    B.insert(B.begin() + 1, A.begin(), A.end()); //不能混合下表操作,第一个参数不能是int
    cout << B << endl;

    //追加
    A.assign("ello");
    B.assign("H");
    B.append(A);
    cout << B << endl;
    A.assign("ello");
    B.assign("H");
    B.append("12345", 2); //参数：字符串，字符串的前n个
    cout << B << endl;
    A.assign("ello");
    B.assign("H");
    B.append("12345", 2, 3); //参数：字符串，起始位，字符串的前n个
    //B.append(A,A.begin(),A.end());不支持
    cout << B << endl;
    A.assign("ello");
    B.assign("H");
    B.append(10, 'o'); //参数：字符串，字符串的前n个
    cout << B << endl;
    A.assign("ello");
    B.assign("H");
    B.append(A.begin(), A.end() - 1);

    //替换
    string var("abcdefghijklmn");
    const string dest("1234");
    string dest2("567891234");
    var.replace(3, 3, dest);//参数：起始位置，个数，替换字符串
    cout << "1: " << var << endl;
    var.assign("abcdefghijklmn");
    var.replace(3, 1, dest.c_str(), 1, 3);//参数：起始位置，个数，替换字符串，替换字符串起始位置，个数
    cout << "2: " << var << endl;
    var.assign("abcdefghijklmn");
    var.replace(3, 1, 5,'x');
    cout << "3: " << var << endl;
    var.assign("abcdefghijklmn");
    var.replace(var.begin(),var.end(),dest);
    cout << "4: " << var << endl;
    var.assign("abcdefghijklmn");
    var.replace(3,1,dest.c_str(),3);//最后一个参数不能越界,会产生乱码，如果直接传的dest，越界则会运行报错
    cout << "5: " << var << endl;
    var.assign("abcdefghijklmn");
    var.replace(var.begin(),var.end(),dest.begin(),dest.end());
    cout << "6: " << var << endl;

    var.assign("123456789");
    string::iterator itBegin = var.begin();
    string::iterator itEnd = var.end();
    var.assign("abcdefghijklmn");//重新赋值，并不意味着，itBegin,itEnd为新的容器的首尾
    var.replace(itBegin, itEnd, dest);
    cout << "7: " << var << endl;

    //字符串连接
    A.assign("Hello");
    B.assign("world");
    string C = A+' '+B+'!';
    cout << C << endl;

    //字符串输入
    string s1, s2,s3;
    cin >> s1;//会保存回车符
    getline(cin, s2);//不会保存回车符
    getline(cin, s3, ' ');//第三个参数指定分界符
    cout << s1 << endl
         << s2 << endl
         << s3 << endl;
    cout << sizeof(s1) << endl;


    system("pause");
}