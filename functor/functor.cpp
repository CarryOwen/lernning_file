// 仿函数（functor）又称为函数对象（function object）是一个能行使函数功能的类。
// 仿函数的语法几乎和我们普通的函数调用一样，不过作为仿函数的类，都必须重载operator()运算符，
// 仿函数与Lamdba表达式的作用是一致的,lamdba 表达式也是编译器默认生成一个匿名类，重载了()运算符。举个例子：

#include <iostream>
#include <string>
using namespace std;
 
class Functor
{
public:
    void operator() (const string& str) const
    {
        cout << str << endl;
    }
};
 
int main()
{
    Functor myFunctor;
    myFunctor("Hello world!");
    return 0;
}