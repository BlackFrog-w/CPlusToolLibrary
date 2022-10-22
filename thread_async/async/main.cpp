/*
 * @Author: BlackFrog
 * @Date: 2022-06-26 14:57:58
 * @LastEditTime: 2022-06-26 16:17:58
 * @Description: 
 * 
 * Copyright (c) 2022 by BlackFrog, All Rights Reserved. 
 */
#include <iostream>
//future头文件中已经包含了 mutex 头文件，当包含future头文件时，可以不用再包含mutex头文件
#include <future>
#include <string>
//不用再包含mutex头文件，多余
//#include <mutex>
#include <vector>

// #include <algorithm>
//std::accumulate头文件
#include <numeric>

std::mutex m;
struct X {
    void foo(int i, const std::string& str) {
        std::lock_guard<std::mutex> lk(m);
        std::cout << str << " " << i << std::endl;
    }

    void bar(const std::string& str) {
        std::lock_guard<std::mutex> lk(m);
        std::cout << str << std::endl;
    }

    int operator()(int i) {
        std::lock_guard<std::mutex> lk(m);
        std::cout << i << std::endl;
    }
};

template<typename RandomIt> int parallel_sum(RandomIt beg, RandomIt end) {
    auto len = end - beg;
    if(len < 1000) {
        return std::accumulate(beg, end, 0);
    }

    RandomIt mid = beg + len/2;
    auto handle = std::async(std::launch::async, parallel_sum<RandomIt>, mid, end);
    int sum = parallel_sum(beg, mid);
    return sum + handle.get();
}

int main(int, char**) {

    std::future_status status;

    std::vector<int> v(10000, 1);
    std::cout << "the sum is: " << parallel_sum(v.begin(), v.end()) << std::endl;

    X  x;
    // 以默认策略调用 x.foo(42, "Hello") ：
    // 可能同时打印 "Hello 42" 或延迟执行
    //std::string s = "hello";
    //x.foo(42, s);
    auto a1 = std::async(&X::foo, x, 42, "Hello");
    
    // 以 deferred 策略调用 x.bar("world!")
    // 调用 a2.get() 或 a2.wait() 时打印 "world!"
    auto a2 = std::async(std::launch::deferred, &X::bar, x, "world!");
    
    // 以 async 策略调用 X()(43) ：
    // 同时打印 "43"
    auto a3 = std::async(std::launch::async, X(), 43);
    a2.wait();                     // 打印 "world!"
    std::cout << a3.get() << '\n'; // 打印 "53"

    
    std::cout << "Hello, world, Mr!\n";
    return 0;
}// 若 a1 在此点未完成，则 a1 的析构函数在此打印 "Hello 42"
