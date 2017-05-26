/*
 * author: jokhan
 * date: 2017年 05月 26日 星期五 14:49:42 CST
 * function: main.cpp
 */
#include <iostream>

using namespace std;

class Solution {
public:
	int mySqrt(int x) 
	{
		if( x == 0 ) {
			return 0;
		}
		int left = 1;
		int right = x;
		int mid = ( left + right ) / 2;
		while( true ) {
			if( x / mid < mid ) {
				right = mid - 1;
			} else {
				if( x / ( mid + 1 ) < (mid + 1) ) {
					return mid;
				}
				left = mid + 1;
			}
			mid = ( left + right ) / 2;
		}
		return mid;
	}
};

int main()
{
	Solution slt;
	cout << slt.mySqrt( 5) << endl;
	return 0;
}
