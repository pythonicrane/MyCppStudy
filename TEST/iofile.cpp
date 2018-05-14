#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream file;
    file.open("hello.txt",ios_base::out);
    if(file.is_open())
    {
        string buffer;
        while(getline(cin,buffer)&&buffer.size()>0)
        {
            file << buffer << endl;
        }
    }
    file.clear();
    file.close();

    ifstream ifile;
    ifile.open("hello.txt",ios_base::in);
    if(ifile.is_open())
    {
        cout << "Out put file:" << endl;
        cout << ifile.rdbuf();
        cout << endl;
    }
    file.clear();
    file.close();
    system("pause");
}