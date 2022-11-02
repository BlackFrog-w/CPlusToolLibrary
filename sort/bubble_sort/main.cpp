/*
 * @Author: BlackFrog
 * @Date: 2022-10-23 00:00:18
 * @LastEditTime: 2022-11-02 23:12:37
 * @Description: 
 * 冒泡排序
 * 参考链接：
 * 
 * Copyright (c) 2022 by BlackFrog, All Rights Reserved. 
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void bubble_sort(std::vector<int>& v) {
	for(int i = v.size() - 1; i >= 0; --i) {
		for(int j = 0; j < i; ++j) {
			if(v[j] > v[j+1]) {
				std::swap(v[j], v[j+1]);
			}
		}
	}
}


int main(int, char**) {

    vector<int> v1{5, 2, 6, 9, 8, 4, 1, 3, 7, 10};


	bubble_sort(v1);

	// std::for_each(v1.begin(), v1.end(), [=]{
	// });

	cout << "冒泡排序" << endl;
	for(auto& ele : v1) {
		cout << ele << endl;
	}

    std::cout << "Hello, world!\n";
}
