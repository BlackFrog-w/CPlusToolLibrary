/*
 * @Author: BlackFrog
 * @Date: 2022-08-20 12:56:02
 * @LastEditTime: 2022-08-20 13:17:01
 * @Description: 
 * 1.测试共享指针是否是线程安全
 * Copyright (c) 2022 by BlackFrog, All Rights Reserved. 
 */
#include<stdio.h>
#include<iostream>
#include <string.h>
#include <memory>
#include <mutex>
#include <thread>
using namespace std;

shared_ptr<long> global_instance = make_shared<long>(0);
std::mutex g_i_mutex;

void thread_fcn()
{
    // 只有加锁时，才能保证线程安全
    // std::lock_guard<std::mutex> lock(g_i_mutex);

    shared_ptr<long> local = global_instance; // thread-safe
    // cout << "*global_instance ref-num2 is " << global_instance.use_count() << endl;
    for(int i = 0; i < 100000000; i++)
    {
        //*global_instance = *global_instance + 1;
        *local = *local + 1;
    }
}

//g++ -std=c++11 thead_01.cpp -lpthread 
int main(int argc, char** argv)
{
    thread thread1(thread_fcn);
    thread thread2(thread_fcn);

    thread1.join();
    thread2.join();

    cout << "*global_instance is " << *global_instance << endl;
    cout << "*global_instance ref-num is " << global_instance.use_count() << endl;

    return 0;
}