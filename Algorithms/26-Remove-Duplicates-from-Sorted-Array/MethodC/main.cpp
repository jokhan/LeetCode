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
		int head = 0;
		for( int i = 1; i < nums.size(); ++ i ) {
			if( nums[i] != nums[head] ) {
				head ++;
				nums[head] = nums[i];
			}
		}
		nums.erase(nums.begin() + head + 1, nums.end() );
		/*
		auto iter = nums.begin();
		auto headIter = nums.begin();
		int delCount = 0;
		for( ++ iter; iter != nums.end(); ) {
			if ( *iter == *headIter ) {
				delCount ++;
				iter ++;
			} else {
				auto tmpIter = iter;
				nums.erase(headIter, iter - 1);
				//nums.erase(headIter, headIter + delCount);
				delCount = 0;
				headIter = tmpIter;
			}
		}
		*/
		return nums.size();
	}
};


int main()
{
	Solution slt;
	vector<int> nums = {1,1,2,2,2,3};
	slt.removeDuplicates( nums );
	//cout << slt.removeDuplicates( nums ) << endl;
	//nums.erase(nums.begin(), nums.begin() + 3);
	for(auto iter = nums.begin() ; iter != nums.end(); ++ iter ) {
		auto tmp = iter;
		//cout << "tmp:" << *tmp << endl;
		cout << *iter << endl;
	}
	return 0;
}
