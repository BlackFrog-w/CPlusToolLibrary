#! /bin/bash
###
 # @Author: BlackFrog
 # @Date: 2022-06-25 16:45:42
 # @LastEditTime: 2022-06-26 18:25:31
 # @Description: 
 # 
 # Copyright (c) 2022 by BlackFrog, All Rights Reserved. 
### 
cd build
echo "---------------当前目录-----------------"
pwd
echo "--------------------------------"
ls
rm -rf *
echo "--------------清空------------------"
ls
###
 # && 的作用是保证上一条命令执下一条命令，如果上一条命令执行报错，那么将终止执行
###
echo "--------------编译&&运行------------------"
cmake ../thread_class/ \
&& make \
&& ./thread_class