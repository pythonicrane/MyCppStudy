/**------------------------------------------
* @Author: Zhao Heln
* @Time: 2018年3月27日21:13:50
* @Software: VScode
* @File: stack.hpp
* @Problem:
* 以vector<string>为基础创建Stack类
--------------------------------------------*/
#include <vector>
#include <string>

using namespace std;

class Stack
{
public:
    Stack();
    bool push(const string &);
    bool pop(string &elem);
    bool top(string &elem);

    bool empty();
    bool full();
    int size() { return _stack.size(); }

    ~Stack();

private:
  vector<string> _stack;
};

Stack::Stack()
{
}

Stack::~Stack()
{
}

inline bool Stack::empty()
{
   return _stack.empty();
}

inline bool Stack::full()
{
    return _stack.size() == _stack.max_size();
}

bool Stack::push(const string &elem)
{
    if(full())
        return false;
    _stack.push_back(elem);
    return true;
}

bool Stack::pop(string &elem)
{
    if(empty())
        return false;
    elem = _stack.back();
    _stack.pop_back();
    return true;
}

bool Stack::top(string &elem)
{
    if(empty())
    {
        return false;
    }
    elem = _stack.back();
    return true;
}
