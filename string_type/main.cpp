/*
 * @Author: BlackFrog
 * @Date: 2022-06-25 00:57:13
 * @LastEditTime: 2022-06-25 01:04:29
 * @Description: 
 * string操作相关函数
 * int值与字符串值互相转换
 * //https://blog.csdn.net/wangcheng_BI/article/details/124363001
 * 
 * 
 * Copyright (c) 2022 by BlackFrog, All Rights Reserved. 
 */
#include <iostream>
#include <string>

int main(int, char**) {

    int a = 110;
    //int转为string
    std::string str = std::to_string(a);
    std::cout << "str is: " << str << std::endl;

    //string转为int
    int b = atoi(str.c_str());
    std::cout << "b is: " << b << std::endl;

    std::cout << "Hello, world!\n";
}
