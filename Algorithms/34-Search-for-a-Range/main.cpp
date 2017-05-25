/*
 * author: jokhan
 * date: 2017年 05月 24日 星期三 21:04:19 CST
 * function: main.cpp
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> result;
		int head = -1;
		int tail = -1;
		int start = 0;
		int end = nums.size() - 1;
		int mid = ( start + end ) / 2;
		bool find = false;
		while( start <= end ) {
			if( nums[mid] == target ) {
				find = true;
				break;
			} else if( nums[mid] > target ) {
				end = mid - 1;
				mid = ( start + end ) / 2;
			} else {
				start = mid + 1;
				mid = ( start + end ) / 2;
			}
		}
		if( find ) {
			head = searchLeft( nums, target, start, mid );
			tail = searchRight( nums, target, mid, end);
			cout << head << "--" << tail << endl;
		}

		result.push_back( head );
		result.push_back( tail );
		return result;
	}
	int searchLeft( vector<int>& nums, int target, int start, int end) 
	{
		if( nums[end] != target) {
			return -1;
		}
		if( start == end ) {
			return start;
		}
		if( nums[start] == nums[end] ) {
			return start;
		}
		if( end - start == 1) {
			return end;
		}
		int mid = ( start + end + 1) / 2;
		if( nums[mid] == target ) {
			end = mid;
		} else {
			start = mid;
		}
		return searchLeft( nums, target, start, end );
	}
	int searchRight( vector<int>& nums, int target, int start, int end) 
	{
		if( nums[start] != target) {
			return -1;
		}
		if( start == end ) {
			return end;
		}
		if( nums[start] == nums[end] ) {
			return end;
		}
		if( end - start == 1) {
			return start;
		}
		int mid = ( start + end ) / 2;
		if( nums[mid] == target ) {
			start = mid;
		} else {
			end = mid;
		}
		return searchRight( nums, target, start, end);
	}
};

int main()
{
	int a[] = {5,7,7,8,8,10};
	int target = 8;
	vector<int> nums(a, a + 6);
	Solution slt;
	slt.searchRange( nums, target );
	return 0;
}
