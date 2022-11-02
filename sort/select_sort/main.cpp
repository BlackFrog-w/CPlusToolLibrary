/*
 * @Author: BlackFrog
 * @Date: 2022-10-23 00:00:18
 * @LastEditTime: 2022-11-02 23:36:30
 * @Description: 
 * 选择排序
 * 参考链接：
 * 
 * Copyright (c) 2022 by BlackFrog, All Rights Reserved. 
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void findMax(std::vector<int> v, int& index, int last) {

	int max = -1;
	
	for(int i = 0; i < last + 1; ++i){
		if(v[i] > max) {
			max = v[i];
			index = i;
		}
	}
	for(auto& i : v) {
		cout << i << "  ";
	}
}


void selece_sort(std::vector<int>& v) {

	int maxIndex = 0;

	for(int i = v.size() - 1; i >= 0; --i) {
		findMax(v, maxIndex, i);

		cout << "maxIndex: " << maxIndex << " i: " << i << endl;

		std::swap(v[i], v[maxIndex]);
	}

}




int main(int, char**) {

    vector<int> v1{5, 2, 6, 9, 8, 4, 1, 3, 7, 10};


	selece_sort(v1);

	// std::for_each(v1.begin(), v1.end(), [=]{
	// });

	cout << "选择排序" << endl;
	for(auto& ele : v1) {
		cout << ele << endl;
	}

    std::cout << "Hello, world!\n";
}
