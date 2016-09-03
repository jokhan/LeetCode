/*
 * author: jokhan
 * date: 2016年 09月 03日 星期六 20:15:07 CST
 * function: main.cpp
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	vector<int> twoSum( vector<int>& nums, int target ) {
		vector<int> result(2);
		map<int, int> mapNums;
		for( int i = 0; i < nums.size(); ++ i ) {
			int complement = target - nums[i];
			map<int, int>::iterator iter;
			iter = mapNums.find( complement );
			if( iter != mapNums.end() && mapNums[complement] != i ) {
				result[1] = i;
				result[0] = mapNums[complement];
				return result;
			} else {
				mapNums[ nums[i] ] = i;
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

	//******data for testing******//
	nums.push_back( 3 );
	nums.push_back( 2 );
	nums.push_back( 4 );
	target = 6;

	vector<int> result;
	result = solution.twoSum( nums, target );
	cout << "[" << result[0] << "," << result[1] << "]" << endl;

	return 0;
}
