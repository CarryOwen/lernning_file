#include "stdio.h"
#include "unistd.h"
int grobal_val = 0;
int main()
{
    /*fork调用的一个奇妙之处就是它仅仅被调用一次，却能够返回两次，它可能有三种不同的返回值：
    1）在父进程中，fork返回新创建子进程的进程ID；
    2）在子进程中，fork返回0；
    3）如果出现错误，fork返回一个负值；
    这在网络服务进程中是最常见的一种处理，
    父进程等待客户端的服务请求，当达到请求到达时，父进程调用fork，使子进程处理此请求。
    父进程则等待下一个服务请求到达。
    */
    pid_t id = fork();
    if (id == 0)
    {
        int cnt = 0;
        while (1)
        {
            printf("子进程:pid=%d,ppid=%d | grobal_val=%d,&grobal_val=%p\n", getpid(), getppid(), grobal_val, &grobal_val);
            sleep(1);
            ++cnt;
            if (cnt == 10)
            {
                grobal_val = 200;
                printf("子进程已更改全局变量grobal_val\n");
            }
        }
    }
    else if(id>0)
    {
        while(1)
        {
            printf("父进程:pid=%d,ppid=%d | grobal_val=%d,&grobal_val=%p\n",getpid(),getppid(),grobal_val,&grobal_val);
            sleep(1);
        }
    }
    else 
    {
        printf("fork error\n");
        return 1;
    }
    return 0;
}