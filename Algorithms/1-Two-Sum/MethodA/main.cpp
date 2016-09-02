/*
 * author: jokhan
 * date: 2016年 09月 02日 星期五 20:04:04 CST
 * function: main.cpp
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
			vector<int> result(2);
				int flag = 1;
				for( int i = 0; i < nums.size() && flag; i ++ ) {
					for( int j = i + 1; j < nums.size() && flag; j ++ ) {
						if( nums[i] + nums[j] == target ) {
							flag = 0;
							result[0]=i;
						}
					}
				}
			return result;
	}
};

int main()
{
	vector<int> nums;
	Solution solution;
	int target;

	return 0;
}
