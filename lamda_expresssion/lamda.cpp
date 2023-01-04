#include "algorithm"
#include "cmath"
#include <vector>
#include "iostream"
using namespace std;
// std::sort函数第三个参数应该是传递一个排序规则的函数，但是这个实例中直接将排序函数的实现写在应该传递函数的位置，
// 省去了定义排序函数的过程，对于这种不需要复用，且短小的函数，直接传递函数体可以增加代码的可读性。
void abssort(float *x, unsigned n)
{
    std::sort(x, x + n,
              // lamda expression begins
              [](float a, float b)
              {
                  return (std::abs(a) < std::abs(b));
              } // end of lamda expression
    );
}
//[]表示不捕获任何变量
auto function1 = ([]
                  { std::cout << "Hello World!" << std::endl; });
// [var] 表示值传递方式捕获变量var
int nums = 100;
auto function2 = ([nums]
                  { cout << nums << endl; });
// [=]表示值传递方式捕获所有父作用域的变量（包括this）
int index = 1;
auto function3 = ([=]
                  { std::cout << "index: " << index << ", "
                              << "num: " << nums << std::endl; });
//[&var]表示引用传递捕捉变量var
int num = 111;
auto function4 = ([&num]
                  {
		num = 1000;
		std::cout << "num: " << num << std::endl; });

//[&]表示引用传递方式捕捉所有父作用域的变量（包括this）
int index6 = 1;
int num6 = 100;
auto function6 = ([&]
                  {
		num6 = 1000;
		index6 = 2;
		std::cout << "index: "<< index6 << ", " 
            << "num: "<< num6 << std::endl; });
//[this]表示值传递方式捕捉当前的this指针
class Lambda
{
public:
    void sayHello()
    {
        std::cout << "Hello" << std::endl;
    };

    void lambda()
    {
        auto function = [this]
        {
            this->sayHello();
        };

        function();
    }
};
/*
Lambda表达式工作原理
编译器会把一个Lambda表达式生成一个匿名类的匿名对象，并在类中重载函数调用运算符，实现了一个operator()方法。

auto print = []{cout << "Hello World!" << endl; };
编译器会把上面这一句翻译为下面的代码：
class print_class
{
public:
	void operator()(void) const
	{
		cout << "Hello World!" << endl;
	}
};
// 用构造的类创建对象，print此时就是一个函数对象
auto print = print_class();
*/
int main()
{
    function1();
    function2();
    function3();
    function4();
    function6();
    Lambda demo;
    demo.lambda();
    return 0;
}