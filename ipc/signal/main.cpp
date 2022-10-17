/*
 * 进程间通信-信号
 *  使用内核中已经存在的信号对象
 *  kill -l  OR /usr/include/sys/signal.h 查看内核中支持多少种信号
 *      HUP INT QUIT ILL TRAP ABRT EMT FPE KILL BUS SEGV SYS PIPE ALRM TERM URG STOP TSTP CONT CHLD TTIN TTOU IO XCPU XFSZ VTALRM PROF WINCH INFO USR1 USR2
 *
 * 编译:
 *      g++ mars/ipc/signal.cc -o build/signal
 */
#include <signal.h>
#include <zconf.h>
#include <iostream>

using namespace std;

// 信号触发自定义回调函数
void process(int signum) {
    cout << "process signum=" << signum << endl;
    int i = 0;
    while (i < 6) {
        i++;
        sleep(1);
        cout << "process:" << i << endl;
    }
}

int main() {
    signal(14, process);  //接收到14的信号后，执行process
    //signal(14, SIG_IGN);  //接收到14的信号后,忽略
    //signal(14, SIG_DFL);  //接收到14的信号后，安装默认方式处理
    cout << "before get signal." << endl;
    //raise(SIGALRM);  // 模拟信号（SIGINT：程序终止(interrupt)信号；SIGABRT：程序的异常终止，如调用 abort；SIGSEGV：非法访问内存；SIGILL：检测非法指令；SIGFPE：错误的算术运算，比如除以零或导致溢出的操作；SIGTERM：发送到程序的终止请求.）
    alarm(10);  // 10s之后终止当前进程，触发SIGALRM
    cout << "after get signal." << endl;
    int i = 0;
    while (i < 20) {
        i++;
        sleep(1);
        cout << "main:" << i << endl;
    }
    return 0;
}