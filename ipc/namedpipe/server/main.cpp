/*
 * @Author: BlackFrog
 * @Date: 2022-10-17 21:59:07
 * @LastEditTime: 2022-10-18 20:56:38
 * @Description: 
 * 参考链接：https://blog.yanjingang.com/?p=4503
 * Copyright (c) 2022 by BlackFrog, All Rights Reserved. 
 */

/*
 * 进程间通信-fifo有名管道server
 *  命名管道是一个设备文件，因此即使进程与创建FIFO的进程不存在亲缘关系，只要可以访问该路径，就能够通过FIFO相互通信
 *
 * 编译:
 *      g++ mars/ipc/fifo-server.cc -o build/ipc-fifo-server
 */
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>

int main() {
    std::string name = "/home/blackfrog/cplus/CPlusToolLibrary/ipc/myfifo";

    // 刪除文件
    unlink(name.c_str());
    // 创建一个存取权限为0666的命名管道
    int namepipe = mkfifo(name.c_str(), S_IFIFO | 0666);  
    if (namepipe == -1) {
        perror("mkfifo fail!");
        exit(1);
    }

    // 只写方式打开该命名管道
    int fd = open(name.c_str(), O_WRONLY);  // O_RDWR);
    if (fd == -1) {
        perror("open fifo fail!");
        exit(2);
    }
    // 向fifo管道发送数据
    char buf[1024];
    while (1) {
        //为什么只有当client进程运行时，才会打印“sendto fifo:”？？？
        // 阻塞的？
        printf("sendto fifo: ");
        fflush(stdout);
        ssize_t n = read(0, buf, sizeof(buf) - 1);  //从标准输入获取消息
        if (n > 0) {
            buf[n - 1] = '\0';  //过滤掉从标准输入中获取的换行
            if (write(fd, buf, n) == -1) {  //把该消息写入到命名管道中
                perror("write fifo fail!");
                exit(3);
            }
        }
    }
    close(fd);

    return 0;
}