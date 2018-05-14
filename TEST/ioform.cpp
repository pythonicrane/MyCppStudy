#include <iostream>


using namespace std;
int main()
{
    cout.width(10);
    cout << 20 << 3.14 << endl;

    int a = 21;
    cout.setf(ios::showbase);    // 显示基数符号(0x或)
    cout << "dec:" << a << endl; // 默认以十进制形式输出
    cout.unsetf(ios::dec);       // 终止十进制格式设置,********必须先终止默认的十进制，才能更换********

    cout.setf(ios::hex); // 设置以十六进制形式输出
    cout << "hex:" << a << endl;
    cout.unsetf(ios::hex); // 终止十六进制形式输出

    cout.setf(ios::oct); // 设置以八进制形式输出
    cout << "oct:" << a << endl;
    cout.unsetf(ios::oct); // 终止八进制形式输出

    char *pt = "China";
    cout.width(10); // 指定域宽为10
    cout << pt << endl;

    cout.width(10); // 指定域宽为10
    cout.fill('*'); // 设置空白处以*号填充
    cout << pt << endl;

    double pi = 22.0 / 7.0;     // 输出PI值
    cout.setf(ios::scientific); // 设置以科学计数法形式输出
    cout << "pi=";
    cout.width(14); // 设置域宽为14
    cout << pi << endl;
    cout.unsetf(ios::scientific); // 终止科学计数法形式输出

    cout.setf(ios::fixed);    // 设置以定点形式输出
    cout.width(12);           // 指定域宽为12
    cout.setf(ios::showpos);  // 正数输出+号
    cout.setf(ios::internal); // 数符出现在左侧
    cout.precision(6);        // 保留位小数
    cout << pi << endl;

    system("pause");
    return 0;
}

/*
*对程序的几点说明：
1) 成员函数width(n)和控制符setw(n)只对其后的第一个输出项有效。如：
    cout. width(6);
    cout <<20 <<3.14<<endl;
输出结果为 203.14

在输出第一个输出项20时，域宽为6，因此在20前面有4个空格，在输出3.14时，width (6)已不起作用，此时按系统默认的域宽输出（按数据实际长度输出）。如果要求在输出数据时都按指定的同一域宽n输出，不能只调用一次width(n)，而必须在输出每一项前都调用一次width(n>，上面的程序中就是这样做的。

2) 在表13.5中的输出格式状态分为5组，每一组中同时只能选用一种（例如dec、hex和oct中只能选一，它们是互相排斥的）。在用成员函数setf和控制符setiosflags设置输出格式状态后，如果想改设置为同组的另一状态，应当调用成员函数unsetf（对应于成员函数self）或resetiosflags（对应于控制符setiosflags），先终止原来设置的状态。然后再设置其他状态，大家可以从本程序中看到这点。程序在开始虽然没有用成员函数self和控制符setiosflags设置用dec输出格式状态，但系统默认指定为dec，因此要改变为hex或oct，也应当先用unsetf 函数终止原来设置。如果删去程序中的第7行和第10行，虽然在第8行和第11行中用成员函数setf设置了hex和oct格式，由于未终止dec格式，因此hex和oct的设置均不起作用，系统依然以十进制形式输出。

同理，程序倒数第8行的unsetf 函数的调用也是不可缺少的。

3) 用setf 函数设置格式状态时，可以包含两个或多个格式标志，由于这些格式标志在ios类中被定义为枚举值，每一个格式标志以一个二进位代表，因此可以用位或运算符“|”组合多个格式标志。如倒数第5、第6行可以用下面一行代替：
    cout.setf(ios::internal I ios::showpos);  //包含两个状态标志，用"|"组合

4) 可以看到：对输出格式的控制，既可以用控制符(如例13.2)，也可以用cout流的有关成员函数(如例13.3)，二者的作用是相同的。控制符是在头文件iomanip中定义的，因此用控制符时，必须包含iomanip头文件。cout流的成员函数是在头文件iostream 中定义的，因此只需包含头文件iostream，不必包含iomanip。许多程序人员感到使用控制符方便简单，可以在一个cout输出语句中连续使用多种控制符。
*/