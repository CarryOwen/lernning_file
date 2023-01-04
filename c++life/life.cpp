#include <iostream>
using namespace std;

#define log(x) life(x)
class life
{
private:
    /* data */
public:
    life(const char *name);
    life(){

    }
    ~life();
};

life::life(const char *name)
{
    cout<<"life structure: "<<name<<endl;
}

life::~life()
{
    cout<<"life destructure"<<endl;
}
int main()
{
    log("aaa");
    life tmp;
    tmp = life("bbb");
    /*
    实际是编译器生成了一个临时对象，是这个临时对象调用了第二个构造函数。
    前面提到了，在没有自己写拷贝构造函数和operator=这两个函数的时候，编译器会自动生成，这个时候的拷贝都是浅拷贝，
    编译器执行life("bbb");的时候创建了一个临时的对象，
    然后通过编译器自己生成的operator=函数把这个临时对象的值赋给了tmp，最后析构这个临时对象
    */
    life("ccc");//直接调用构造函数，与上面的一样，会立即调用构造和析构，销毁临时对象
    cout<<"test"<<endl;
}