#include "iostream"
#include "string"
#include "vector"
using namespace std;
/*
array首先向右结合，所以这个相当于 (int&)array[] array是个数组，其中的元素是引用
应该叫：引用的数组
int &array[]
array首先和&结合，所以array是引用，引用的对象是数组
应该叫作数组的引用
int (&array)[10]
而如果采用const char(&p)[a]的话，会有以下好处：

1.整个char数组不会作为指针，而是作为数组被引用 ，因而，sizeof可以获得整个数组的长度
2.template会动态编译，自动推断a的大小，由于已经知道了数组的长度，因此该函数可以自动推断出字符串的长度
3.const确保可以引用右值，同时不会修改源字符串内容
4.传入NULL会报错，避免了char*的缺陷

*/
class test
{
private:
    /* data */
public:
    template <class T, size_t N, size_t P>
    void str_buffer(const T (&data)[N], const T (&topic)[P])
    {
        cout << "N: " << N << endl;
        cout << "p: " << P << endl;
    }
};

int main()
{
    test ar;
    char p[] = "aaaa";
    ar.str_buffer(p, "bbb");
    getchar();
}