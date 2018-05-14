#include <ctime>
#include <iomanip>
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int row, col;

bool isoverflow(int x, int y)
{
    if (x < 0 || x > row - 1 || y < 0 || y > col - 1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    int **people;
    int **tag;
    int count = 0;
    cin >> row >> col;
    people = new int *[row + 2];
    tag = new int *[row + 2];
    for (int i = 0; i < row+2; ++i)
    {
        people[i] = new int[col + 2];
        tag = new int *[col + 2];
    }

    for (int i = 0; i < row + 2; ++i)
    {
        for (int j = 0; j < col + 2; ++j)
        {
            if(i==0||i==row+1||j==0||j==col+1)
            {
                people[i][j] = 0;
            }
            else
            {
                cin >> people[i][j];
            }
            tag[i][j] = 0;

        }
    }

    //标记八阵图
    for (int i = 1; i < row+1;++i)
    {
        for (int j = 1; j < col+1;++j)
        {
            if(people[i][j]!=0)
            {
                if(people[i-1][j-1]!=0)
                {

                }
            }

        }
    }

    for (int k = 1; k <= 8;++k)
    {
        for (int i = 1; i < row+1;++i)
        {
            for (int j = 1; j < col+1;++j)
            {
                //检测是八邻域
                if(people[i][j]!=0)
                {
                    if(people[i-1][j-1] != 0)
                    {
                        people[i][j] += people[i - 1][j - 1];
                        people[i - 1][j - 1] = 0;
                    }
                    if(people[i-1][j] != 0)
                    {
                        people[i][j] += people[i-1][j];
                        people[i-1][j] = 0;
                    }
                    if(people[i][j-1] != 0)
                    {
                        people[i][j] += people[i][j-1];
                        people[i][j-1] = 0;
                    }
                    if(people[i-1][j+1] != 0)
                    {
                        people[i][j] += people[i-1][j+1];
                        people[i-1][j+1] = 0;
                    }
                }

            }
        }
    }

        vector<int> vt;
    for (int i = 0; i < row + 2; ++i)
    {
        for (int j = 0; j < col + 2; ++j)
        {
            if(people[i][j]!=0)
            {
                vt.push_back(people[i][j]);
            }
        }
    }

    // cout << *(vt.begin()) << endl;
    // cout << *(vt.end()) << endl;

    for (int i = 0; i < row + 2; ++i)
    {
        for (int j = 0; j < col + 2; ++j)
        {

            cout <<setw(5) <<people[i][j] << " ";
        }
        cout << endl;
    }

    system("pause");
}