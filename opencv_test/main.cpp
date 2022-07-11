/*
 * @Author: BlackFrog
 * @Date: 2022-07-01 14:13:28
 * @LastEditTime: 2022-07-01 14:28:25
 * @Description:
 *
 * Copyright (c) 2022 by BlackFrog, All Rights Reserved.
 */
#include <iostream>
// #include <CvPlot/core.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

void test(int event) {
    if(event == CV_EVENT_MBUTTONDOWN) {
        std::cout << "hello, www" << std::endl;
    }
}

int main(int, char**) {

    cv::Point arrow;

    std::cout << "Hello, world!\n";
}
