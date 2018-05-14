#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;
int main()
{
    //距离时间戳2两秒
    chrono::time_point<chrono::system_clock, chrono::seconds> tp(chrono::seconds(2));
    cout << "to epoch : " <<tp.time_since_epoch().count() << "s" <<endl;
    //转化为ctime，打印输出时间点
    time_t tt = chrono::system_clock::to_time_t(tp);
    char a[50];
    ctime_s(a, sizeof(a), &tt);
    cout << a;
    system("pause");
    return 0;
}