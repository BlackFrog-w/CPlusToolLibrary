/*
 * @Author: BlackFrog
 * @Date: 2022-06-20 22:46:40
 * @LastEditTime: 2022-06-25 16:27:45
 * @Description: 
 * 1.验证多线程操作基础类型是否是原子性
 * 2.std::unique_lock的使用 //https://www.cnblogs.com/lihaihui1991/p/14281117.html
 * 3.线程的创建使用
 * 4.在类内如何创建线程？？？
 * 5.原子性操作？ 
 * //https://www.cnblogs.com/lihaihui1991/p/14286812.html
 * //https://www.cnblogs.com/lihaihui1991/category/1913414.html
 * //https://www.cnblogs.com/lihaihui1991/p/14252569.html
 * 6.创建线程的不同方式 
 * //https://www.cnblogs.com/lihaihui1991/p/14272556.html
 * pthread_create
 * std::thread
 * Copyright (c) 2022 by BlackFrog, All Rights Reserved. 
 */
#include <iostream>
#include <thread>
#include <mutex>

int a = 0;
int b = 0;
std::mutex b_lock;

void fun_1() {
    for(int i = 100000; i--;) {
        a += 1;
        // std::cout << "a is: " << a << std::endl;
    }

}

void fun_2() {
    for(int i = 100000; i--;) {
        a += 1;
        // std::cout << "a is: " << a << std::endl;
    }
}

void fun_3() {
    std::unique_lock<std::mutex> lock_(b_lock);
    for(int i = 100000; i--;) {
        b += 1;
        // std::cout << "a is: " << a << std::endl;
    }
}

void fun_4() {
    std::unique_lock<std::mutex> lock_(b_lock);
    for(int i = 100000; i--;) {
        b += 1;
        // std::cout << "a is: " << a << std::endl;
    }
}

int main(int, char**) {

    std::thread t1(fun_1);
    std::thread t2(fun_2);
    std::thread t3(fun_3);
    std::thread t4(fun_4);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    std::cout << "a is: " << a << std::endl;
    std::cout << "b is: " << b << std::endl;
    std::cout << "Hello, world!\n";
}
