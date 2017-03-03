/*
 * author: jokhan
 * date: 2017年 03月 03日 星期五 15:44:05 CST
 * function: main.cpp
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int i = nums.size() - 1;
		bool noFound = true;   
		int insertPos = 0;
		for(i = nums.size() - 1; i > 0 && noFound; i --) {
			if(nums[i-1] < nums[i]) {
				insertPos = i - 1;
				noFound = false;
			}
		}
		if( noFound || nums.size() == 2 ) {
			//reserve this vector
			int head = 0, tail = nums.size() - 1;
			for( ; head < tail; head ++, tail -- ) {
				swapVector(nums, head, tail);
			}
		} else {
			int numPos = insertPos + 1;
			for(int j = nums.size() - 1; j > insertPos; j --) {
				if(nums[j] > nums[insertPos]) {
					numPos = j ;
					break;
				}
			}
			swapVector(nums, numPos, insertPos);
			sort(nums.begin() + insertPos + 1, nums.end());
		}

	}
	void swapVector(vector<int>& nums, int pos1, int pos2)
	{
		if(pos1 != pos2 && pos1 < nums.size() && pos2 < nums.size()) {
			int tmp = nums[pos2];
			nums[pos2] = nums[pos1];
			nums[pos1] = tmp;
		}
	}
};

int main()
{
	Solution slt;
	int a[] = {2,3,1,4,5};
	int b[] = {2,2,7,5,4,3,2,2,1};
	int c[] = {4,2,0,2,3,2,0};
	vector<int> nums(a, a+3);
	//slt.replaceVector(nums, 5, 0);
	slt.nextPermutation(nums);
	cout << "hello" << endl;
	for(int i = 0; i < nums.size(); i ++) {
		cout << nums[i] << endl;
	}
}
