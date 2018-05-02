#include <iostream>
using namespace std;

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

void ShellSort(int arr[],int lenght)
{
    if(lenght==0||arr ==NULL)
    {
        return;
    }
    for (int gap = lenght / 2; gap > 0;gap /= 2 )
    {
        for (int i = gap; i < lenght;++i)
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


int main()
{
    int arr[10] = {1,3,2,4,10,8,9,5,7,6};
    ShellSort(arr, 10);

    for (int i = 0; i < 10;++i)
    {
        cout << arr[i] << ",";
    }

    system("pause");
}