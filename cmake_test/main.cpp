/*
 * @Author: BlackFrog
 * @Date: 2022-07-11 17:14:41
 * @LastEditTime: 2022-07-13 11:38:16
 * @Description: 
 * 
 * Copyright (c) 2022 by BlackFrog, All Rights Reserved. 
 */
#include <iostream>
#include "load_so.h"

int main(int, char**) {



#ifdef TEST_DEBUG
std::cout << "TEST_DEBUG" << std::endl;
#else
std::cout << "NO TEST_DEBUG" << std::endl;
#endif

    // 可以正常编译通过，但是调用 say_hello() 函数运行程序就啥也不输出了
    // say_hello();

    std::cout << "Hello, world!\n";

}
