/*
 * @Author: BlackFrog
 * @Date: 2022-10-23 00:00:18
 * @LastEditTime: 2022-10-24 23:58:13
 * @Description: 
 * 快速排序
 * 参考链接：
 * https://interviewguide.cn/notes/03-hunting_job/03-algorithm/01-basic-algorithm/02-04-%E5%8D%81%E5%A4%A7%E6%8E%92%E5%BA%8F.html
 * 
 * Copyright (c) 2022 by BlackFrog, All Rights Reserved. 
 */
#include <iostream>
#include <vector>

using namespace std;

static int num = 1;

void quickSort(vector<int>& a, int low, int high) {
	if (low >= high)		// 结束标志
		return;
	int first = low;		// 低位下标
	int last = high;		// 高位下标
	int key = a[first];		// 设第一个为基准

	while (first < last)
	{
		// 从后往前走，将比第一个小的移到前面
		while (first < last && a[last] > key)
			last--;
		if (first < last)
			a[first++] = a[last];





        if(num == 1) {
            cout << "-------------------------------------------------------" << endl;
            for(auto i = a.begin(); i != a.end(); ++i) {
                cout << *i << endl;
            }
            ++num;
        }


		//从前往后走， 将比第一个大的移到后面
		while (first < last && a[first] <= key)
			first++;
		if (first < last)
			a[last--] = a[first];

        if(num == 2) {
            cout << "-------------------------------------------------------" << endl;
            for(auto i = a.begin(); i != a.end(); ++i) {
            cout << *i << endl;
            }
            ++num;
        }

        cout << "first is: " << first << ", last is: " << last << endl;    
	}

	a[first] = key;
    if(num == 3) {
        cout << "-------------------------------------------------------" << endl;
        for(auto i = a.begin(); i != a.end(); ++i) {
        cout << *i << endl;
        }
        ++num;
    }  
	// 前半递归
	quickSort(a, low, first - 1);
	// 后半递归
	quickSort(a, first + 1, high);
	



}

int main(int, char**) {

    vector<int> v{5, 2, 6, 9, 8, 4, 1, 3, 7, 10};

    quickSort(v, 0, 9);

    for(auto i = v.begin(); i != v.end(); ++i) {
        // cout << *i << endl;
    }

    std::cout << "Hello, world!\n";
}
