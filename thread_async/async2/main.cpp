/*
 * @Author: BlackFrog
 * @Date: 2022-10-23 01:11:08
 * @LastEditTime: 2022-10-23 01:11:08
 * @Description: 
 * 参考链接：
 * https://blog.csdn.net/m0_37621078/article/details/89789943
 * Copyright (c) 2022 by BlackFrog, All Rights Reserved. 
 */
//future4.cpp 使用async传递被调用线程返回结果

#include <vector>
#include <thread>
#include <future>
#include <numeric>
#include <iostream>
#include <chrono>
 
int accumulate(std::vector<int>::iterator first,
                std::vector<int>::iterator last)
{
    int sum = std::accumulate(first, last, 0);
    return sum;
}
 
int main()
{
    // 演示用 async 在线程间传递结果。
    std::vector<int> numbers = { 1, 2, 3, 4, 5, 6 };
    auto accumulate_future = std::async(std::launch::async, accumulate, numbers.begin(), numbers.end());		//auto可以自动推断变量的类型
    std::cout << "result=" << accumulate_future.get() << '\n';
 
    getchar();
    return 0;
}
