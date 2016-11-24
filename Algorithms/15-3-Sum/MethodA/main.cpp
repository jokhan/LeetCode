/*
 * author: jokhan
 * date: 2016年 09月 17日 星期六 09:59:11 CST
 * function: main.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int> > threeSum(vector<int>& nums) {
		vector<vector<int> > result;
		sort(nums.begin(), nums.end());
		for( int i = 0; i < nums.size(); i ++ ) {
			if ( i > 0 && nums[i] == nums[i-1] ) {
				// 防止重复
				continue;
			}
			// two sum
			int start = i + 1, end = nums.size() - 1;
			int target = -nums[i];
			while( start < end ) {
				if ( start > i + 1 && nums[start - 1] == nums[start] ) {
					// 防止重复
					start ++;
					continue;
				}
				if ( nums[start] + nums[end] < target ) {
					start ++;
				} else if ( nums[start] + nums[end] > target ) {
					end --;
				} else {
					vector<int> triple;
					triple.push_back( nums[i] );
					triple.push_back( nums[start] );
					triple.push_back( nums[end] );
					result.push_back( triple );
					start ++;
				}
			}
		}
		return result;
	}
};


int main()
{
	return 0;
}
