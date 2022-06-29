/*
 * @Author: BlackFrog
 * @Date: 2022-06-29 14:30:41
 * @LastEditTime: 2022-06-29 21:16:41
 * @Description: 
 * 
 * Copyright (c) 2022 by BlackFrog, All Rights Reserved. 
 */
#include <iostream>
#include <vector>
#include <algorithm>

int main(int, char**) {

    std::vector<int> v;
    for(int i = 100; i--;) {
        v.push_back(i);
    }

    while (!v.empty())
    {
        auto b = v.front();
        std::cout << b << std::endl;
    }
    
    // std::for_each()

    std::cout << "Hello, world!\n";
}
