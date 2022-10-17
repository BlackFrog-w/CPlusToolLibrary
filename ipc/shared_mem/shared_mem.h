/**
 * @file	share-memory.h
 * @brief   进程间通信-共享内存头文件封装
 *              共享内存创建之后，一直存在于内核中，读完之后，内容还存在，直到被删除或系统关闭
 * @author	yanjingang
 */
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#include <unistd.h>
#include <iostream>

// 共享文件路径，client和server必须指向同一个路径
#define PATHNAME "."
#define PROCID 'b' //0x6666
#define MEMSIZE 4096*1

using namespace std;

namespace mars {
namespace ipc {
    // 共享内存类
    class ShareMemory{
        private:
            // key
            int key_;
            // 共享内存ID
            int shmid_;
            // 共享内存大小
            int size_;
            // 创建共享内存
            int create_share_memory();
        public:
            ShareMemory();
            ShareMemory(const size_t m_size);
            virtual ~ShareMemory();
            // 变量返回
            int key(){return key_;}
            int shmid(){return shmid_;}
            int size(){return size_;}
            // 共享内存指针
            char* mem;
    };


    // 构造函数
    ShareMemory::ShareMemory(){
        this->size_ = MEMSIZE;
        int ret = this->create_share_memory();
        if(ret != 0){
            cout << "create_share_memory fail!" << endl;
        }
    }
    // 构造函数
    ShareMemory::ShareMemory(const size_t m_size){
        this->size_ = m_size;
        int ret = this->create_share_memory();
        if(ret != 0){
            cout << "create_share_memory fail!" << endl;
        }
    }
    
    // 创建共享内存
    int ShareMemory::create_share_memory(){
        // 创建key, 以实现非亲缘关系进程间通信
        key_ = ftok(PATHNAME, PROCID);  
        if (key_ == -1) {
            cout << "create key file..." << endl;
            FILE* fp;
            if ((fp=fopen(PATHNAME,"a")) == nullptr){
                cout << "keyfile created failed" << endl;
                return -2;
            }
            fclose(fp);
            key_ = ftok(PATHNAME, PROCID);  
            if (key_ == -1) {
                cout << "key created failed" << endl;
                return -1;
            }
        }
        cout << "mq key:" << key_ << endl;

        // 创建共享内存
        shmid_ = shmget(key_, this->size(), IPC_CREAT | 0777);    // 以ftok创建的key，需要IPC_CREAT参数 
        //shmid_ = shmget(IPC_PRIVATE, 128, 0777);   // 在内核中生成共享内存的对象；相当于缓存，只能实现有亲缘关系进程间通信
        if (shmid_ == -1) {
            cout << "shmget create share memory fail!" << endl;
            return -3;
        }
        cout << "shmget create share memory success! shmid:" << shmid() << " size:" << size() << endl;
        
        // 返回这块内存的虚拟地址（将申请的共享内存挂接在该进程的页表上，是将虚拟内存和物理内存相对应）
        mem = (char*)shmat(shmid_, NULL, 0);
        if (mem == nullptr) {
            cout << "shmat share memory mapping fail!" << endl;
            return -4;
        }

        return 0;
    }


    // 析构函数
    ShareMemory::~ShareMemory()
    {
        // 将用户空间的内存释放
        shmdt(mem);
        // 将内核空间的内存释放
        shmctl(shmid_, IPC_RMID, NULL);
    }

}
}