/*
 * @Author: BlackFrog
 * @Date: 2022-10-17 22:03:07
 * @LastEditTime: 2022-10-18 20:53:02
 * @Description: 
 * 参考链接：https://blog.yanjingang.com/?p=4503
 * Copyright (c) 2022 by BlackFrog, All Rights Reserved. 
 */
/*
 * 进程间通信-fifo有名管道client
 *  命名管道是一个设备文件，因此即使进程与创建FIFO的进程不存在亲缘关系，只要可以访问该路径，就能够通过FIFO相互通信
 *
 * 编译:
 *      g++ mars/ipc/fifo-client.cc -o build/ipc-fifo-client
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
    // 只读方式打开该命名管道
    int fd = open(name.c_str(), O_RDONLY);  // O_RDWR);
    if (fd == -1) {
        perror("open fifo fail!");
        exit(1);
    }
    // 接收管道数据
    char buf[1024];
    while (1) {
        printf("enter while loop\n");
        // read是阻塞的
        ssize_t s = read(fd, buf, sizeof(buf) - 1);
        printf("read size is: %d \n", s);
        if (s > 0) {
            printf("receive from fifo: %s\n", buf);
        } else {  //读失败或者是读取到字符结尾
            perror("read fifo fail!");
            exit(2);
        }
    }
    close(fd);

    return 0;
}