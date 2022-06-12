/*
 * @Author: BlackFrog
 * @Date: 2022-06-12 17:22:52
 * @LastEditTime: 2022-06-12 18:16:26
 * @Description: 
 * 
 * Copyright (c) 2022 by BlackFrog, All Rights Reserved. 
 */
#include <iostream>
#include <chrono>


// using namespace std::chrono;
// using namespace std;


int main(int, char**) {

    auto t1=std::chrono::steady_clock::now();
    //run code
    auto t2=std::chrono::steady_clock::now();
    
    //秒
    double dr_s=std::chrono::duration<double>(t2-t1).count();
    //毫秒级
    double dr_ms=std::chrono::duration<double,std::milli>(t2-t1).count();
    //微妙级
    double dr_us=std::chrono::duration<double,std::micro>(t2-t1).count();
    //纳秒级
    double dr_ns=std::chrono::duration<double,std::nano>(t2-t1).count(); 


    std::chrono::system_clock::time_point start_time1 = std::chrono::system_clock::now();
    int a = 0;
    for(int i = 0; i < 10000000; i++) {
        a += 1;
    }
    std::chrono::system_clock::time_point end_time1 = std::chrono::system_clock::now();

    auto dura2 = (std::chrono::duration_cast<std::chrono::milliseconds>(end_time1 - start_time1)).count();
    std::cout << "示例1 耗时(time): " << dura2 << " ms" << std::endl;


    auto dura1 = (std::chrono::duration_cast<std::chrono::microseconds>(end_time1 - start_time1)).count();
    std::cout << "示例1 耗时(time): " << dura1 << " μs" << std::endl;

    auto dura3 = (std::chrono::duration_cast<std::chrono::nanoseconds>(end_time1 - start_time1)).count();
    std::cout << "示例1 耗时(time): " << dura3 << " ns" << std::endl;

}
