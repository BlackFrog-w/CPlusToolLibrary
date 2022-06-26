/*
 * @Author: BlackFrog
 * @Date: 2022-06-26 18:23:34
 * @LastEditTime: 2022-06-26 19:22:05
 * @Description: 
 * //类内成员为线程
 * https://blog.csdn.net/Shreck66/article/details/50409874
 * Copyright (c) 2022 by BlackFrog, All Rights Reserved. 
 */
#include <iostream>
#include <unistd.h>
#include <test.h>
#include <test2.h>

int main(int, char**) {

    Test test;
    sleep(1000);

    std::cout << "Hello, world!\n";
}
