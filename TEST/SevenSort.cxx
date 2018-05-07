/**-------------------------------------------------------------
* @Author       : Zhao Heln
* @Time         : 2018年5月2日21:56:33
* @Software     : Visual Studio Code
* @Project      : C++ 数据结构+算法
* @Problem      : 七种基本排序
* @Description  :
*
-------------------------------------------------------------**/
#include <iostream>
using namespace std;

//冒泡排序
void BubbleSort(int arr[],int lenght)
{
    int tmp;
    for (int i = 0; i < lenght - 1;++i)
    {
        for (int j = 0; j < lenght - 1 - i;++j)
        {
            if(arr[j]>arr[j+1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }

        }
    }
}

//插入排序
void InsertSort(int arr[],int lenght)
{
    int tmp;
    for (int i = 1; i < lenght;++i)
    {
        tmp = arr[i];
        int j;
        for (j = i-1; j >= 0 && tmp<arr[j];--j)
        {
            arr[j+1] = arr[j];
        }
        arr[j+1] = tmp;
    }
}

//希尔排序
void ShellSort(int arr[],int lenght)
{
    if(lenght==0||arr ==NULL)
    {
        return;
    }
    for (int gap = lenght / 2; gap > 0;gap /= 2 )//多一层循环，表示间隔分组
    {
        for (int i = gap; i < lenght;++i)//类似于插入排序
        {
            int inserted = arr[i];
            int j;
            for (j = i - gap; j >= 0 && inserted < arr[j];j -= gap)
            {
                arr[j+gap] = arr[j];
            }
            arr[j+gap] = inserted;
        }
    }
}

//快速排序
void QuietSort(int arr[],int left,int right)
{
    if(left>=right)//********注意=号********
        return;
    int i = left;
    int j = right;
    int key = arr[i];//与partition算法思路一样，把小于Key的值放左边，把大于Key的值放右边；
    while (i<j)
    {
        while(i<j&&key<=arr[j])//注意有两个条件，先得到小于的值
            --j;
        arr[i] = arr[j];//得到的第一个小于Key值，存到前面去
        while(i<j&&key>=arr[i])
            --i;
        arr[j] = arr[i];//得到的第一个大于Key值，存到后面去
    }
    arr[i] = key;//把Key放到中间
    QuietSort(arr, left, i - 1);//左边子序列递归快排
    QuietSort(arr, i + 1, right);;//右边子序列递归快排
}


int main()
{
    int arr[10] = {1,3,2,4,10,8,9,5,7,6};
    QuietSort(arr, 0,9);

    for (int i = 0; i < 10;++i)
    {
        cout << arr[i] << ",";
    }

    system("pause");
}