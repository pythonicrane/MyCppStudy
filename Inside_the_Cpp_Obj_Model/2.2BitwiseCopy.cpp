/**-------------------------------------------------------------
* @Author       : Zhao Heln
* @Time         : 2018年6月8日15:32:42
* @Software     : Visual Studio Code
* @Project      : 深度探索C++对象模型
* @Problem      : Bitwise Copy Semantics问题-P50
* @Description  :
-------------------------------------------------------------**/
#include <iostream>
#include<cstring>
using namespace std;

class Word
{
public:
    Word(const char* s){
        str = new char[strlen(s)+1]; // 开辟空间
        strcpy(str,s);
        cnt = strlen(s)+1;
    }
    ~Word(){
        delete[] str; // 释放空间
    }

public:
    int cnt;
    char *str;
};


int main()
{
    Word noun("book");//调用构造函数
    Word verb = noun;// 不会产生copy constructors，通过Bitwise Copy
    cout<<verb.str<<endl;
    cout<<verb.cnt<<endl;

    cout<<"noun.str address = "<<static_cast<void*>(noun.str)<<endl;
    cout<<"verb.str address = "<<static_cast<void*>(verb.str)<<endl;
    system("pause");
    return 0;
    //退出的时候会报错，verb 和 nunn的str指向同一块内存，不能delete两次
}