/*
 * @Author: BlackFrog
 * @Date: 2022-06-23 15:40:36
 * @LastEditTime: 2022-06-23 15:41:11
 * @Description: 
 * https://blog.csdn.net/lemonxiaoxiao/article/details/121996477
 * Copyright (c) 2022 by BlackFrog, All Rights Reserved. 
 */
# include <eigen3/Eigen/Dense> 
# include <iostream>

using namespace std;
using namespace Eigen;

int main(int argc, char *argv[])
{
    
    Eigen::Vector3d vec(3,4,5);
    cout << "data.norm() = " << vec.norm() << endl;
    vec.normalize();
    cout << "vec.normalize() = " << vec << endl;
    cout << "vec.normalized() = " << vec.normalized() << endl;

    Eigen::Matrix3d mat;
    mat << 1,2,3,
           4,5,6,
           7,8,9;
    cout << "mat.norm() = " << mat.norm() << endl;
    mat.normalize();
    cout << "mat.normalize() = " << mat << endl;
    cout << "mat.normalized()" << mat.normalized() << endl;

    return 0;
}
