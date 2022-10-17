/*
 * @Author: BlackFrog
 * @Date: 2022-10-17 22:15:42
 * @LastEditTime: 2022-10-17 22:21:32
 * @Description: 
 * 
 * Copyright (c) 2022 by BlackFrog, All Rights Reserved. 
 */
/**
 * @file	share-memory-get.cc
 * @brief   进程间通信-共享内存get测试
 *              共享内存创建之后，一直存在于内核中，读完之后，内容还存在，直到被删除或系统关闭
 * @author	yanjingang
 * @note    编译：g++ mars/ipc/share-memory-get.cc -std=c++11 -Wall -o build/ipc-share-memory-get
 */
#include "shared_mem.h"

using namespace std;

int main() {
    mars::ipc::ShareMemory shm; //(4096);

    while (true) {
        sleep(1);
        cout << "get share memory content: " << strlen(shm.mem) << " - " << shm.mem << endl;
    }

    return 0;
}
