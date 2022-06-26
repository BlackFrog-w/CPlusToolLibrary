/*
 * @Author: BlackFrog
 * @Date: 2022-06-26 18:28:31
 * @LastEditTime: 2022-06-26 18:28:50
 * @Description: 
 * 
 * Copyright (c) 2022 by BlackFrog, All Rights Reserved. 
 */
#pragma once

#include <iostream>
#include <thread>

class Test
{
    public:
        Test():testThread_(print)
        {

        }

        //print函数必须为静态函数
        static void print()
        {
            std::cout<<"hello"<<std::endl;
        }

    private:
        std::thread testThread_;
};