/*
 * author: jokhan
 * date: 2017年 05月 26日 星期五 16:59:53 CST
 * function: main.cpp
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxSubArray( vector<int>& nums ) 
	{
		int len = nums.size();
		int* dp = new int[len];
		dp[0] = nums[0];
		int result = dp[0];
		for( int i = 1; i < len; i ++ ) {
			dp[i] = nums[i] + (dp[i-1] > 0 ? dp[i-1] : 0);
			result = max( result, dp[i] );
		}
		return result;
	}
};

int main()
{
	return 0;
}
