/*
 * @Author: BlackFrog
 * @Date: 2022-06-26 19:20:38
 * @LastEditTime: 2022-06-26 19:31:21
 * @Description: 
 * 
 * Copyright (c) 2022 by BlackFrog, All Rights Reserved. 
 */

#include <thread>
#include <iostream>

//线程函数操作成员变量错误示例
class Test2
{
    public:
        Test2(int m):n(m),testThread_(print)
        {

        }
        
        static void print(void)
        {
            //无法直接操作普通成员变量n
            //std::cout<<n<<std::endl;
        }

    private:
        int n;
        std::thread testThread_;
};

//线程函数操作成员变量正确示例
class Test3
{
    public:
        
        Test3(int m) : testThread_(print)
        {

        }

        //print作为线程函数，必须为static才可以
        //如果想操作成员变量n，那么n必须为static
        static void print(void)
        {
            std::cout<<n<<std::endl;
        }

    private:
        static int n;
        std::thread testThread_;
};


class Test4
{
    public:
        Test4(int m):n(m),testThread_(print,this)
        {

        }

        static void print(Test4 *pt)
        {
            std::cout<<pt->n<<std::endl;
        }
        
    private:
        int n;
        std::thread testThread_;
};


#include <functional>

class Test5
{
    public:
        Test5(int m):n(m),testThread_(std::bind(&Test5::print,this))
        {

        }

        void print(void)
        {
            std::cout<<n<<std::endl;
        }

    private:
        int n;
        std::thread testThread_;
};