/*
 * @Author: BlackFrog
 * @Date: 2022-07-13 14:07:49
 * @LastEditTime: 2022-07-13 14:08:14
 * @Description: 
 * 调用系统命令
 * https://zh.cppreference.com/w/cpp/utility/program/system
 * 当前只可以在linux平台下运行
 * 
 * 获取环境变量
 * https://zh.cppreference.com/w/cpp/utility/program/getenv
 * 
 * Copyright (c) 2022 by BlackFrog, All Rights Reserved. 
 */
#include <iostream>

int main(int, char**) {

    std::system("ls -l > systerm.txt");

    std::cout << "Hello, world!\n";
}
