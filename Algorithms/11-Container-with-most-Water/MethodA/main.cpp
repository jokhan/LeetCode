/*
 * author: jokhan
 * date: 2016年 09月 14日 星期三 16:17:54 CST
 * function: main.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxArea( vector<int>& height ) {
		int result = 0;
		int head = 0, tail = height.size() - 1;
		while ( tail > head ) {
			int area = ( tail - head ) * min( height.at( head ), height.at( tail ) );
			result = max( area, result );
			if( height.at( head ) < height.at( tail ) ) {
				head ++;
			} else {
				tail --;
			}
		}
		return result;
	}
};


int main()
{
	vector<int> height;
	height.push_back(3);
	height.push_back(2);
	height.push_back(3);
	height.push_back(4);
	
	Solution slt;
	cout << slt.maxArea( height ) << endl;

	return 0;
}
