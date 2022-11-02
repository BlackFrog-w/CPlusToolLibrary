/*
 * @Author: BlackFrog
 * @Date: 2022-10-23 00:00:18
 * @LastEditTime: 2022-10-26 00:20:15
 * @Description: 
 * 堆排序
 * 参考链接：
 * https://interviewguide.cn/notes/03-hunting_job/03-algorithm/01-basic-algorithm/02-07-%E5%8D%81%E5%A4%A7%E6%8E%92%E5%BA%8F.html
 * Copyright (c) 2022 by BlackFrog, All Rights Reserved. 
 */
#include <iostream>
#include <vector>

using namespace std;


void heapify(vector<int>& nums, int n, int i)//对有一定顺序的堆，
//当前第i个结点取根左右的最大值（这个操作称heapfiy）
{
	int l = i * 2 + 1, r = i * 2 + 2;
	
    int max = i;
	
    //得出左右子树中最大的那个
    if (l<n && nums[l]>nums[max])
		max = l;
	if (r<n && nums[r]>nums[max])
		max = r;
	
    if (max != i)
	{
		swap(nums[max], nums[i]);
		heapify(nums, n, max);
	}

}

void heapify_build(vector<int>& nums, int n)//建立大根堆，从树的倒数第二层第一个结点开始，
//对每个结点进行heapify操作，然后向上走
{
    //这里减去2的原因是因为，在容器存储时，索引是0-9，而在堆中，每个元素的编号是从 1 开始的
	int temp = (n - 2) / 2;
    cout << "temp is: " << temp << endl;

	for (int i = temp; i >= 0; i--) {
        heapify(nums, n, i);
    }
		

	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
	cout << endl;

}

void heapify_sort(vector<int>& nums, int n)//建立大根堆之后，每次交换最后一个结点和根节点（最大值），
//对交换后的根节点继续进行heapify（此时堆的最后一位是最大值，因此不用管他，n变为n-1）
{

	heapify_build(nums, n);


	for (int i = 0; i < n; i++)
	{
		swap(nums.front(), nums[n - i - 1]);
		heapify(nums, n - i - 1, 0);
	}


}
 

int main(int, char**) {

    vector<int> v{5, 2, 6, 9, 8, 4, 1, 3, 7, 10};

    // quickSort(v, 0, 9);
    heapify_sort(v, 10);

    cout << "-----------------------------" << endl;
    for(auto i = v.begin(); i != v.end(); ++i) {
        cout << *i << endl;
    }

    std::cout << "Hello, world!\n";
}
