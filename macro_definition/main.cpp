/*
 * @Author: BlackFrog
 * @Date: 2022-06-15 23:14:16
 * @LastEditTime: 2022-06-15 23:18:43
 * @Description: 
 * 
 * Copyright (c) 2022 by BlackFrog, All Rights Reserved. 
 */
#include <iostream>
#include <string>

//宏定义1
#define test_macro_def(inner_str) #inner_str
//宏定义2
#define test_macro_def2(inner_str) inner_str

int main(int, char**) {

    std::string str = "abcdefg";
    std::cout << "macro 1 is: " << test_macro_def(str) << std::endl;
    std::cout << "macro 2 is: " << test_macro_def2(str) << std::endl;

    std::cout << "Hello, world!\n";
}
