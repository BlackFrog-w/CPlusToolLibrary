/*
 * @Author: BlackFrog
 * @Date: 2022-07-15 10:43:31
 * @LastEditTime: 2022-07-15 14:30:11
 * @Description: 
 * https://blog.csdn.net/weixin_43229348/article/details/124656388
 * 正则表达式
 * ^ 开头
 * () 组
 * [] 或
 * {} 几次
 * $ 结尾
 * Copyright (c) 2022 by BlackFrog, All Rights Reserved. 
 */
#include <iostream>
#include <regex>
#include <string>
#include <vector>

int main(int, char**) {

    std::string str = "string";
    std::string::size_type n = str.size();

    bool ret = std::regex_match("softwareTesting", std::regex("(soft)(.*)"));
    if(ret) {
        std::cout << "ret is: " << ret << std::endl;
    }


    std::string str2("soft666");
    // 匹配以 soft 开头的string？
    std::regex str_reg("(soft)(.*)");
    

    ret = std::regex_match(str2, str_reg);
    std::cout << "ret1 is: " << ret << std::endl;




    std::cout << "Hello, world!\n";
}
