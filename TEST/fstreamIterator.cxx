/**------------------------------------------
* @Author: Zhao Heln
* @Time: 2018年3月27日20:20:33
* @Software: VScode
* @File: fstreamIterator.cxx
* @Problem: 通过输入输出流迭代器输入和输出文件,
* 将文件中的字符串排序
--------------------------------------------*/


#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <fstream>

using namespace std;

int main()
{
    ifstream in_file("input_file.txt");
    ofstream out_file("sort_output_file.txt");

    if(!in_file || !out_file)
    {
        cerr << "ERROR FILE!\n";
    }

    istream_iterator<string> is(in_file);
    istream_iterator<string> eof;

    vector<string> text;

    copy(is, eof, back_inserter(text));

    sort(text.begin(), text.end());

    ostream_iterator<string> os(out_file," ");
    copy(text.begin(), text.end(), os);

    system("pause");
}