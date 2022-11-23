//命令行解析函数getopt()
#include "iostream"
#include "stdio.h"
#include "getopt.h"
/*
(1) 单个字符，表示该选项Option不需要参数。
(2) 单个字符后接一个冒号":"，表示该选项Option需要一个选项参数Option argument。
选项参数Option argument可以紧跟在选项Option之后，或者以空格隔开。选项参数Option argument的首地址赋给optarg。
(3) 单个字符后接两个冒号"::"，表示该选项Option的选项参数Option argument是可选的。
当提供了Option argument时，必须紧跟Option之后，不能以空格隔开，
否则getopt()会认为该选项Option没有选项参数Option argument，optarg赋值为NULL。
相反，提供了选项参数Option argument，则optarg指向Option argument。
该例子的测试方法：./getopt -a -b test
*/
static int cnt = 1;
static void print(int optc, int argc, char *argv[], int optind)
{
    int i;
    printf("%02d: optc : '%c', argv: ", cnt++, optc);
    for (i = 0; i < argc; i++)
    {
        printf("%s ", argv[i]);
    }
    printf("----optind = %d\n", optind);
}
int main(int argc, char *argv[])
{
    int optc;
    print('0', argc, argv, optind);
    while ((optc = getopt(argc, argv, "ab:c:de::")) != -1)
    {
        print(optc, argc, argv, optind);
        switch (optc)
        {
        case 'a':
            printf("\nget -a\n");
            break;
        case 'b':
            printf("\nget -b\n");
            printf("optarg: %s\n",optarg);// 全局变量optarg 保存选项-b 后面的参数
        default:
            break;
        }
    }
    print('0', argc, argv, optind);
    exit(EXIT_SUCCESS);
}