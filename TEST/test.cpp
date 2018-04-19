#include <iostream>
using namespace std;
class base1
{
public:
    void same_name_fun()
    {
        cout<<"in base1 same_name_fun"<<endl;
    }
    virtual ~base1(){}
};
class base2
{
public:
    void ba2_fun()
    {
        cout<<"base2_fun"<<endl;
    }
};
class derived : public base1,base2
{
public:
    void same_name_fun()
    {
        cout<<"in derived same_name_fun"<<endl;
    }
    void de_fun()
    {
        cout<<"de_fun"<<endl;
    }
};
int main()
{
    derived obj;
    obj.same_name_fun();
    (static_cast<base1>(obj)).same_name_fun();

    getchar();
    return 0;
}