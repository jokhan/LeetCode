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
	//**********枚举法***********//
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result(2);
		for( int i = 0; i < nums.size(); i ++ ) {
			for( int j = i + 1; j < nums.size(); j ++ ) {
				if( nums[i] + nums[j] == target ) {
					result[0] = i;
					result[1] = j;
					return result;
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
