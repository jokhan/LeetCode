/*
 * author: jokhan
 * date: 2016年 09月 17日 星期六 09:59:11 CST
 * function: main.cpp
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int> > threeSum(vector<int>& nums) {
		vector<vector<int> > result;
		for( int i = 0; i < nums.size(); i ++ )
			for( int j = i + 1; j < nums.size(); j ++ )
				for( int k = j + 1; k < nums.size(); k ++ ) {
					if( nums.at( i ) + nums.at( j ) == 0 - nums.at( k ) ) {
						vector<int> triple;
						triple.push_back( nums.at(i) );
						triple.push_back( nums.at(j) );
						triple.push_back( nums.at(k) );
						result.push_back( triple );
					}
				}
		return result;
	}
};


int main()
{
	return 0;
}
