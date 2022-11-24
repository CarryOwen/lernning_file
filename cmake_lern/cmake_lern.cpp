#include<iostream>
#include "swap.h"
using namespace std;
int main()
{
    int a = 1, b = 2;
    cout << "befor swap : a=" <<a<<" b="<<b<< endl;
    my_swap(a, b);
    cout << "after swap : a=" <<a<<" b="<<b<< endl;
}