/*
 * @Author: BlackFrog
 * @Date: 2022-06-23 13:56:34
 * @LastEditTime: 2022-06-23 13:58:14
 * @Description: 
 * 
 * Copyright (c) 2022 by BlackFrog, All Rights Reserved. 
 */
#include <iostream>
#include "fun.h"
#include "fun2.h"

int main(int, char**) {

    auto b = fun_1();

    auto a = fun_2();

    std::cout << "a is: " << a << std::endl;
    std::cout << "b is: " << b << std::endl;
    std::cout << "Hello, world!\n";
}