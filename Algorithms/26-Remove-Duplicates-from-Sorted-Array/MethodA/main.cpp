/*
 * author: jokhan
 * date: 2016年 11月 23日 星期三 09:40:23 CST
 * function: main.cpp
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int removeDuplicates( vector<int>& nums ) {
		if ( nums.size() < 2 )
			return nums.size();
		auto iter = nums.begin();
		int tmpNum = *iter;
		for( ++ iter; iter != nums.end(); ) {
			if ( *iter != tmpNum ) {
				tmpNum = *iter;
				iter ++;
			} else {
				nums.erase( iter );
			}
		}
		return nums.size();
	}
};


int main()
{
	Solution slt;
	vector<int> nums = {1,1,2,3,3,4};
	cout << slt.removeDuplicates( nums ) << endl;
	for(auto iter = nums.begin() ; iter != nums.end(); ++ iter ) {
		cout << *iter << endl;
	}
	return 0;
}
