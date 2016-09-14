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
		for( int i = 0; i < height.size(); i ++ ) {
			for( int j = i + 1; j < height.size(); j ++ ) {
				int area = min( height.at(i), height.at(j) ) * ( j - i );
				if( area > result )
					result = area;
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
