/**-------------------------------------------------------------
* @Author       : Zhao Heln
* @Time         : 2018年4月24日21:47:12
* @Software     : Visual Studio Code
* @Project      : C++ STL标准程序库开发指南
* @Problem      : List的基本操作
* @Description  :
*
-------------------------------------------------------------**/
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <list>

using namespace std;


template<typename T> void print(T& S)
{
    cout << S << ", ";
}

int main()
{
    /*List 初始化*/
    list<int> listi_1;//空链表
    list<int> listi_2(10);//初始化size为10的链表
    list<int> listi_3(10, 0);//初始化size为10个值为0的链表
    list<int> listi_4(listi_3);//对象初始化
    list<int> listi_5(listi_3.begin(), listi_3.end());//迭代器初始化

    /*List 元素的赋值*/
    //push_back(),push_front(),pop_back(),pop_front();
    listi_1.push_front(10);//********vector在头部操作效率很低，所以没有push_front()********
    listi_1.push_back(1);
    listi_1.push_back(2);
    listi_1.push_back(3);
    listi_1.push_back(-10);
    listi_1.pop_back();
    listi_1.pop_front();

    /*List 容量操作*/
    //size(),max_size(),resize();
    for_each(listi_1.begin(), listi_1.end(), print<int>);
    cout << endl;
    cout << "listi_1 size: " << listi_1.size() << endl;
    cout << "listi_1 max_size: " << listi_1.max_size() << endl;
    listi_1.resize(2);
    for_each(listi_1.begin(), listi_1.end(), print<int>); //*******ist没有capacity();*********
    cout << endl;

    /*List 迭代器*/
    //begin(),end(),rbegin(),rend(),back(),front();

    /*List 判断是否为空函数*/
    //empty()
    if(!listi_1.empty())
    {
        listi_1.pop_back();
    }

    /*List 元素存取*/
    //List不支持随机存取，不存在下标操作[]和.at()函数访问，只能使用迭代器;

    /*List 元素重置*/
    //assign();
    //void assign(const_iterator first,const_iterator last);
    //void assign(size_type n, const T& x=T());
    list<double> listd_1, listd_2, listd_3;
    for (int i = 0; i < 10;i++)
    {
        listd_1.push_back(i+i/10.0);
    }
    for_each(listd_1.begin(), listd_1.end(), print<double>);
    cout << endl;
    listd_2.assign(5, 5.6);
    for_each(listd_2.begin(), listd_2.end(), print<double>);
    cout << endl;
    listd_3.assign(listd_1.begin(), --listd_1.end());
    for_each(listd_3.begin(), listd_3.end(), print<double>);
    cout << endl;

    /*List 交换*/
    //swap();
    //List有swap函数，只能同类型交换，也可以用算法中的swap
    cout << "swap listd_1 listd_2:" << endl;
    listd_1.swap(listd_2);
    for_each(listd_1.begin(), listd_1.end(), print<double>);
    cout << endl;
    for_each(listd_2.begin(), listd_2.end(), print<double>);
    cout << endl;
    cout << "swap listd_2 listd_3:" << endl;
    swap(listd_2,listd_3);
    for_each(listd_2.begin(), listd_2.end(), print<double>);
    cout << endl;
    for_each(listd_3.begin(), listd_3.end(), print<double>);
    cout << endl;

    /*List 插入删除*/
    //push_back(),push_front(),pop_back(),pop_front();
    //insert(),erase(),clear();
    //iterator insert(iterator it,const T& x = T());
    //void insert(iterator it,size_type n,const T& x = T());
    //void insert(iterator it,const_iterator first,const_iterator last);
    //iterator erase(iterator it);
    //iterator erase(iterator first,iterator last);
    cout << "--------insert && erase-------"<<endl;
    list<int> mylt;
    for (int i = 0; i < 10;++i)
    {
        mylt.push_back(i);
    }
    for_each(mylt.begin(),mylt.end(),print<int>);
    cout << endl;
    if(!mylt.empty())
    {
        mylt.pop_back();
    }
    for_each(mylt.begin(),mylt.end(),print<int>);
    cout << endl;
    mylt.clear();
    for (int i = 0; i < 13;++i)
    {
        mylt.push_back(i);
    }
    for_each(mylt.begin(),mylt.end(),print<int>);
    cout << endl;
    while(!mylt.empty())
    {
        mylt.erase(mylt.begin());
        for_each(mylt.begin(),mylt.end(),print<int>);
        cout << endl;
    }

    /*List 运算符*/
    //operator==,operator<,operator>,operator!=,operator<=,operator>=;

    /*List 融合和排序*/
    //merge(),sort();
    //void merge(list& x);
    //void merge(list& x,greater<T> pr);
    //void sort();
    //void sort(greater<T> pr);
    //********List 没有find()函数********
    list<int> L1, L2, L3;
    L1.push_back(1);
    L1.push_back(5);
    L2.push_back(2);
    L2.push_back(3);
    L3.push_back(7);
    L3.push_back(8);
    cout << "L1: ";
    for_each(L1.begin(),L1.end(),print<int>);
    cout << endl;
    cout << "L2: ";
    for_each(L2.begin(),L2.end(),print<int>);
    cout << endl;
    cout << "L3: ";
    for_each(L3.begin(),L3.end(),print<int>);
    cout << endl;
    cout << "L1 merge L2: ";
    L1.merge(L2);//********merge函数会进行比较，若原来的链表是无序的，在未比较完的时候，一部分直接在链表后面,被融合的链表为空了*******
    for_each(L1.begin(),L1.end(),print<int>);
    cout << endl;
    for_each(L2.begin(),L2.end(),print<int>);
    cout << endl;
    cout << "L1 merge L3: ";
    L1.merge(L3,greater<int>());
    for_each(L1.begin(),L1.end(),print<int>);
    cout << endl;
    L1.sort();
    for_each(L1.begin(),L1.end(),print<int>);
    cout << endl;
    L1.sort(greater<int>());
    for_each(L1.begin(),L1.end(),print<int>);
    cout << endl;

    /*List 移除操作*/
    //remove(),remove_if();
    //void remove(const Type& _val);
    //template<typename Pred> remove_if(Pred pr);//仿函数
    list<int> L4;
    for (int i = 0; i < 10;++i)
    {
        L4.push_back(i);
    }
    L4.push_back(3);
    L4.push_back(2);
    L4.push_back(3);
    cout << "L4: ";
    for_each(L4.begin(),L4.end(),print<int>);
    cout << endl;
    L4.remove(3);
    cout << "L4: ";
    for_each(L4.begin(),L4.end(),print<int>);
    cout << endl;
    L4.remove_if(bind2nd(less<int>(), 5));//删除小于5的内容
    for_each(L4.begin(),L4.end(),print<int>);
    cout << endl;

    /*List 拼接操作*/
    //splice()
    //void splice(iterator it ,list& x);
    //void splice(iterator it ,list& x,iterator first);
    //void splice(iterator it ,list& x,iterator first,iterator last);
    cout << "-----List::splice()------------------" << endl;
    list<int> L5, L6, L7, L8;
    L5.push_back(1);
    L5.push_back(5);
    L6.push_back(2);
    L6.push_back(3);
    L7.push_back(7);
    L7.push_back(8);
    L8.push_back(9);
    L8.push_back(-1);
    cout << "L5: ";
    for_each(L5.begin(),L5.end(),print<int>);
    cout << endl;
    cout << "L6: ";
    for_each(L6.begin(),L6.end(),print<int>);
    cout << endl;
    cout << "L7: ";
    for_each(L7.begin(),L7.end(),print<int>);
    cout << endl;
    cout << "L8: ";
    for_each(L8.begin(),L8.end(),print<int>);
    cout << endl;
    cout << "L5 splice L6: " << endl;
    L5.splice(L5.end(),L6);//********splice()拼接后，被拼接的list会相应减少元素，且不会进行排序********
    cout << "L5: ";
    for_each(L5.begin(),L5.end(),print<int>);
    cout << endl;
    cout << "L6: ";
    for_each(L6.begin(),L6.end(),print<int>);
    cout << endl;
    cout << "L5 splice L8: " << endl;
    L5.splice(L5.end(), L8, (++L8.begin()));
    cout << "L5: ";
    for_each(L5.begin(),L5.end(),print<int>);
    cout << endl;
    cout << "L8: ";
    for_each(L8.begin(),L8.end(),print<int>);
    cout << endl;
    cout << "L5 splice L7: " << endl;
    L5.splice(L5.begin(), L7, L7.begin(), L7.end());
    cout << "L5: ";
    for_each(L5.begin(),L5.end(),print<int>);
    cout << endl;
    cout << "L7: ";
    for_each(L7.begin(),L7.end(),print<int>);
    cout << endl;

    /*List 唯一化操作*/
    //unique()
    //void unique();
    //template<class BinaryPredicate> void unique(BinaryPredicate _Pred);
    cout << "-----List::unique()------------------" << endl;
    list<int> L9, L10;
    L9.push_back(1);
    L9.push_back(2);
    L9.push_back(3);
    L9.push_back(1);
    L9.push_back(2);
    L9.push_back(3);
    L9.push_back(5);
    L9.push_back(7);
    L10.assign(L9.begin(), L9.end());
    cout << "L9: ";
    for_each(L9.begin(),L9.end(),print<int>);
    cout << endl;
    cout << "L10: ";
    for_each(L10.begin(),L10.end(),print<int>);
    cout << endl;
    L9.unique();//********该操作仅仅用作两个邻近的元素比较，若相同，则剔除一个，反之则保留，因此要保持唯一性，先排序********
    cout << "L9: ";
    for_each(L9.begin(),L9.end(),print<int>);
    cout << endl;
    L9.sort();
    L9.unique();
    cout << "L9: ";
    for_each(L9.begin(),L9.end(),print<int>);
    cout << endl;
    not_equal_to<int> Pred;
    L10.sort();
    L10.unique(Pred);//********提供谓词，也仅仅是比较邻近的两个元素********
    cout << "L10: ";
    for_each(L10.begin(),L10.end(),print<int>);
    cout << endl;

    /*List 反转操作*/
    //reverse();
    cout << "--------Reverse List--------" << endl;
    L9.reverse();
    cout << "L9: ";
    for_each(L9.begin(),L9.end(),print<int>);
    cout << endl;

    system("pause");
}
