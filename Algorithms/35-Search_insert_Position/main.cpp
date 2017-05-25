/*
 * author: jokhan
 * date: 2017年 05月 25日 星期四 16:22:23 CST
 * function: main.cpp
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int searchInsert( vector<int>& nums, int target ) 
	{
		return search( nums, target, 0, nums.size() - 1 );
	}
	int search( vector<int>& nums, int target, int start, int end )
	{
		if( nums[start] >= target ) {
			return start;
		}
		if( nums[end] < target ) {
			return end + 1;
		}
		if( nums[end] == target ) {
			return end;
		}
		if( end - start == 1 ) {
			return end;
		}
		int mid = ( start + end + 1 ) / 2;
		if( nums[mid] > target ) {
			end = mid;
		} else if ( nums[mid] < target ) {
			start = mid;
		} else {
			return mid;
		}
		return search( nums, target, start, end );
	}
};

int main()
{
	return 0;
}
