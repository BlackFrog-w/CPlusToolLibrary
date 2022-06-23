/*
 * @Author: BlackFrog
 * @Date: 2022-06-23 14:07:36
 * @LastEditTime: 2022-06-23 14:44:26
 * @Description: 
 * 
 * Copyright (c) 2022 by BlackFrog, All Rights Reserved. 
 */
 
#include <Eigen/Dense>
#include <Eigen/Core>
#include <iostream>
using namespace std;


double angle_of_2_vector(Eigen::Vector3d v1, Eigen::Vector3d v2)
{
    if(!(v1.norm() > 0 && v2.norm() > 0))
        return std::nan("");
    v1.normalize();
    v2.normalize();
    double cos = v1.dot(v2);
    double sin = v1.cross(v2).z();
    if (cos > 1)
        cos = 1;
    if (cos < -1)
        cos = -1;
    if (sin > 1)
        sin = 1;
    if (sin < -1)
        sin = -1;
    double theta = acos(cos);
    if (sin < 0) theta = -theta;
    while (theta > M_PI) theta -= 2 * M_PI;
    while (theta < -M_PI) theta += 2 * M_PI;
    if(std::isnan(theta))
        theta = 0.0;
    return theta;
}

int main( int argc, char** argv )
{

    /*
    // Eigen 中所有向量和矩阵都是Eigen::Matrix，它是一个模板类。它的前三个参数为：数据类型，行，列
    // 声明一个2*3的float矩阵
    Eigen::Matrix<float, 2, 3> matrix_23;
 
    // 同时，Eigen 通过 typedef 提供了许多内置类型，不过底层仍是Eigen::Matrix
    // 例如 Vector3d 实质上是 Eigen::Matrix<double, 3, 1>，即三维向量
    Eigen::Vector3d v_3d;
	// 这是一样的
    Eigen::Matrix<float,3,1> vd_3d;
 
    // Matrix3d 实质上是 Eigen::Matrix<double, 3, 3>
    Eigen::Matrix3d matrix_33 = Eigen::Matrix3d::Zero(); //初始化为零
    // 如果不确定矩阵大小，可以使用动态大小的矩阵
    Eigen::Matrix< double, Eigen::Dynamic, Eigen::Dynamic > matrix_dynamic;
    // 更简单的
    Eigen::MatrixXd matrix_x;
    // 这种类型还有很多，我们不一一列举
 
    // 下面是对Eigen阵的操作
    // 输入数据（初始化）
    matrix_23 << 1, 2, 3, 4, 5, 6;
    // 输出
    cout << matrix_23 << endl;
 
    // 用()访问矩阵中的元素
    for (int i=0; i<2; i++) {
        for (int j=0; j<3; j++)
            cout<<matrix_23(i,j)<<"\t";
        cout<<endl;
    }
 
    // 矩阵和向量相乘（实际上仍是矩阵和矩阵）
    v_3d << 3, 2, 1;
    vd_3d << 4,5,6;
    // 但是在Eigen里你不能混合两种不同类型的矩阵，像这样是错的
    // Eigen::Matrix<double, 2, 1> result_wrong_type = matrix_23 * v_3d;
    // 应该显式转换
    Eigen::Matrix<double, 2, 1> result = matrix_23.cast<double>() * v_3d;
    cout << result << endl;
 
    Eigen::Matrix<float, 2, 1> result2 = matrix_23 * vd_3d;
    cout << result2 << endl;
 
    // 同样你不能搞错矩阵的维度
    // 试着取消下面的注释，看看Eigen会报什么错
    // Eigen::Matrix<double, 2, 3> result_wrong_dimension = matrix_23.cast<double>() * v_3d;
 
    // 一些矩阵运算
    // 四则运算就不演示了，直接用+  -  * 或 /即可。
    matrix_33 = Eigen::Matrix3d::Random();      // 随机数矩阵
    cout << matrix_33 << endl << endl;
 
    cout << matrix_33.transpose() << endl;      // 转置
    cout << matrix_33.sum() << endl;            // 各元素和
    cout << matrix_33.trace() << endl;          // 迹
    cout << 10*matrix_33 << endl;               // 数乘
    cout << matrix_33.inverse() << endl;        // 逆
    cout << matrix_33.determinant() << endl;    // 行列式
 
    // 特征值
    // 实对称矩阵可以保证对角化成功
    Eigen::SelfAdjointEigenSolver<Eigen::Matrix3d> eigen_solver ( matrix_33.transpose()*matrix_33 );
    cout << "Eigen values = \n" << eigen_solver.eigenvalues() << endl;
    cout << "Eigen vectors = \n" << eigen_solver.eigenvectors() << endl;
 
    // 解方程
    // 我们求解 matrix_NN * x = v_Nd 这个方程
    // N的大小在前边的宏里定义，它由随机数生成
    // 直接求逆自然是最直接的，但是求逆运算量大
    
    const int MATRIX_SIZE = 10;

    Eigen::Matrix< double, MATRIX_SIZE, MATRIX_SIZE > matrix_NN;
    matrix_NN = Eigen::MatrixXd::Random( MATRIX_SIZE, MATRIX_SIZE );
    Eigen::Matrix< double, MATRIX_SIZE,  1> v_Nd;
    v_Nd = Eigen::MatrixXd::Random( MATRIX_SIZE,1 );
 
    // 直接求逆
    Eigen::Matrix<double,MATRIX_SIZE,1> x = matrix_NN.inverse()*v_Nd;
 
    
	// 通常用矩阵分解来求，例如QR分解，速度会快很多
    x = matrix_NN.colPivHouseholderQr().solve(v_Nd);
    */
   
    Eigen::Vector3d v3dX = Eigen::Vector3d::UnitX();
    cout << v3dX(0) << v3dX(1) << v3dX(2) << endl; 

    Eigen::Vector3d v3dY = Eigen::Vector3d::UnitY();
    cout << v3dY(0) << v3dY(1) << v3dY(2) << endl; 

    Eigen::Vector3d v3dZ = Eigen::Vector3d::UnitZ();
    cout << v3dZ(0) << v3dZ(1) << v3dZ(2) << endl; 


    auto diff_1 = angle_of_2_vector(v3dX, v3dY);
    cout << "diff_1 is: " << diff_1 << endl;

    return 0;
}