/*
 * @Author: BlackFrog
 * @Date: 2022-10-18 22:17:55
 * @LastEditTime: 2022-10-18 22:19:38
 * @Description: 
 * 内存映射
 * 参考链接：https://blog.yanjingang.com/?p=4503
 * Copyright (c) 2022 by BlackFrog, All Rights Reserved. 
 */


/*
 * 进程间通信-内存映射
 *
 * 编译:
 *      g++ mars/ipc/mmap.cc -o build/mmap
 * 
 * 运行:
 *      ./build/mmap p1
 *      ./build/mmap p2
 */
#include <fcntl.h>
#include <sys/mman.h>
#include <zconf.h>
#include <iostream>

using namespace std;

// 数据结构体
struct Persion {
    int sex;
    int age;
};

// 创建并返回内存映射指针
struct Persion* get_mmap(size_t length) {
    std::string name = ".mymmap";

    // 准备内存映射的共享文件
    //unlink(name.c_str());
    int fd = open(name.c_str(), O_CREAT | O_RDWR, 0666);
    if (fd == -1) {
        perror("open file fail!");
        exit(2);
    }

    ftruncate(fd, length);
    // 申请内存
    
    struct Persion* mm = (struct Persion*)mmap(
        nullptr,                    // 分配的首地址
        length,                     // 分配内存大小(必须是页的整数倍, 32位1页=4k)
        PROT_WRITE | PROT_READ,     // 映射区域保护权限：读|写
        MAP_SHARED,                 // 对映射区域的写入数据会复制回文件内，而且允许其他映射该文件的进程共享
        fd,                         // 要映射到内存中的文件描述符
        0);                         // 文件映射的偏移量，通常设置为0，必须是页的整数倍
    close(fd);
    if (mm == MAP_FAILED) {
        cout << "mmap error" << endl;
        return nullptr;
    }
    return mm;
}

int main(int argc,char *argv[]){
    // 参数
    std::string name = "default";
    if(argc >= 2){
	    cout << "arg: " << argc << " - " << argv[1] << endl;
        name = argv[1];
    }

    // 测试
    size_t length = 4096;
    //int pid = fork();
    //if (pid == 0) {
    while (true)
    {
        sleep(1);
        struct Persion* mm = get_mmap(length);
        cout << name <<" mm:" << mm << endl;
        // get
        cout << "mm get:  age=" << mm->age << " sex=" << mm->sex << endl;
        // set
        mm->sex = rand()%2;     //2
        mm->age = rand()%100;   //3
        cout << "mm set:  age=" << mm->age << " sex=" << mm->sex << endl;
        int mun_ret = munmap(mm, length);  // 释放指针指向的内存区域，并制定释放的内存大小(即使不释放，内容也会在文件中修改)
        if (mun_ret == -1) {
            cout << "munmap error" << endl;
        }
    }
    return 0;
}