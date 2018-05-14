/**-------------------------------------------------------------
* @Author       : Zhao Heln
* @Time         : 2018年5月10日16:49:38
* @Software     : Visual Studio Code
* @Project      : C++ STL标准程序库开发指南
* @Problem      : 日期和时间
* @Description  :
*
-------------------------------------------------------------**/

#include <ctime>
#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    char tempbuf[128];
    struct tm *mytime;     //结构体指针
    time_t myclock;        //long类型
    clock_t start, finish; //long类型
    time_t tstart, tfinish;
    double duration;
    long long count = 600000000L;

    time(&myclock);               //获取时间，单位秒
    mytime = localtime(&myclock); //转化成tm结构体
    cout << "myclock : " << endl;
    cout << myclock << endl;
    cout << "Usage of asctime() : " << endl;
    cout << setw(40) << left << "asctime(): Current Date and time : " << asctime(mytime) << endl; //tm结构体转换成时间字符串输出

    cout << "Usage of ctime() : " << endl;
    cout << setw(40) << left << "ctime(): Current Date and time: " << ctime(&myclock) << endl; //秒转换为时间字符串输出

    cout << "Usage of clock() : " << endl;
    start = clock(); //获取硬件嘀嗒数
    while (count--)
        ;
    finish = clock(); //获取硬件嘀嗒数
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << "clock(): Consume " << finish << " - " << start << " = " << duration << " second." << endl;
    cout << endl;

    cout << "Usage of difftime() : " << endl;
    count = 600000000L;
    time(&tstart);
    while (count--)
        ;
    time(&tfinish);
    duration = (tfinish - tstart);
    cout << "time(): Consume " << duration << " second." << endl;
    cout << endl;

    cout << "Usage of strftime() : " << endl;
    mytime = localtime(&myclock);
    strftime(tempbuf, 128, "Today is %A,day %d of %B in the year %Y.\n", mytime);
    cout << tempbuf << endl;

    strftime(tempbuf, sizeof(tempbuf), "Today is %Y%m%d %H:%M:%S.\n", mytime);
    cout << tempbuf << endl;

    cout << mytime->tm_mday << " " << mytime->tm_wday << " " << mytime->tm_yday << endl;

    system("pause");
}