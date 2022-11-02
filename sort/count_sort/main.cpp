/*
 * @Author: BlackFrog
 * @Date: 2022-10-23 00:00:18
 * @LastEditTime: 2022-10-26 00:20:38
 * @Description: 
 * 计数排序
 * 参考链接：
 * https://interviewguide.cn/notes/03-hunting_job/03-algorithm/01-basic-algorithm/02-08-%E5%8D%81%E5%A4%A7%E6%8E%92%E5%BA%8F.html
 * 
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
 

// 计数排序
void CountSort(vector<int>& vecRaw, vector<int>& vecObj)
{
	// 确保待排序容器非空
	if (vecRaw.size() == 0)
		return;

	// 使用 vecRaw 的最大值 + 1 作为计数容器 countVec 的大小
	int vecCountLength = (*max_element(begin(vecRaw), end(vecRaw))) + 1;
	
	vector<int> vecCount(vecCountLength, 0);

	// 统计每个键值出现的次数
	for (int i = 0; i < vecRaw.size(); i++)
		vecCount[vecRaw[i]]++;
	
	// 后面的键值出现的位置为前面所有键值出现的次数之和
	for (int i = 1; i < vecCountLength; i++)
		vecCount[i] += vecCount[i - 1];

	// 将键值放到目标位置
	for (int i = vecRaw.size(); i > 0; i--)	// 此处逆序是为了保持相同键值的稳定性
		vecObj[--vecCount[vecRaw[i - 1]]] = vecRaw[i - 1];
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
