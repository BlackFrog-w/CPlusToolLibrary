/*
 * @Author: BlackFrog
 * @Date: 2022-06-25 16:35:51
 * @LastEditTime: 2022-06-26 01:05:19
 * @Description: 
 * 知识点1：
 * 当一个while循环不退出时，会占用多少CPU？测试发现占用一个核的100%，当前可能会运行在不同的核上，但是总的占用率是一个
 * 核的100%
 * https://blog.csdn.net/lyndon_li/article/details/123223652
 * 知识点2：
 * //https://blog.csdn.net/xyblog/article/details/50495025
 * std::this_thread含有多个成员函数：sleep_for()、get_id()、yield()
 * 
 * 
 * Copyright (c) 2022 by BlackFrog, All Rights Reserved. 
 */
#include <iostream>
#include <thread>
//sleep休眠函数头文件
#include <unistd.h>
#include <string>

//计时
std::chrono::system_clock::time_point start_time1, end_time1;

void add(int a, int t_id) {
    /*
    //CPU占用一个核的100%，假设笔记本是4个核，那么就会占用1个核的100%，四个核总的25%
    while (1)
    {
        a++;
    }*/

    //CPU占用接近0%
    while (1)
    {
        //休眠单位：S
        //sleep(1);

        //休眠单位：ms
        std::chrono::milliseconds dura(2000);
        std::this_thread::sleep_for(dura);
        
        //get_id()返回类型为thread::id，无法转换到基础类型int
        std::thread::id id = std::this_thread::get_id();
        std::cout << "thread id is: " << id << ", " << std::to_string(t_id) << std::endl;

        //让CPU来调度，和sleep类似
        //std::this_thread::yield();

        a++;
        std::cout << "a is: " << a << std::endl;
        end_time1 = std::chrono::system_clock::now();
        auto dura2 = (std::chrono::duration_cast<std::chrono::milliseconds>(end_time1 - start_time1)).count();
        std::cout << "示例1 耗时(time): " << dura2 << " ms" << std::endl;
    }
    
}

int main(int, char**) {
    start_time1 = std::chrono::system_clock::now();
    static int a = 0;
    //一个线程只会运行在一个核上
    std::thread t1(add, a, 1);
    //t1.join();

    std::thread t2(add, a, 2);
    t1.join();
    t2.join();

    std::cout << "Hello, world!\n";
}
