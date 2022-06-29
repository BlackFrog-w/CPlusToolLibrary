/*
 * @Author: BlackFrog
 * @Date: 2022-06-29 23:19:38
 * @LastEditTime: 2022-06-29 23:52:29
 * @Description:
 * reference link 
 * https://en.cppreference.com/w/cpp/algorithm
 * Copyright (c) 2022 by BlackFrog, All Rights Reserved. 
 */
#include <iostream>
#include <algorithm>
#include <vector>

int main(int, char**) {

    std::vector<int> v;
    for(int i = 20; i -= 2;) {
        v.push_back(i);
    }
    std::cout << "v size is: " << v.size() << std::endl;

    // 迭代器为什么可以复制给引用？
    auto print = [](const int& n) {std::cout << " " << n << std::endl;};
    std::cout << "begin" << std::endl;
    // std::for_each实现原理？与for循环有什么区别？效率如何
    //
    std::for_each(v.begin(), v.end(), print);



    


    std::cout << "Hello, world!\n";
}
