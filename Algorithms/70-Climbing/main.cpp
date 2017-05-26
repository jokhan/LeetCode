/*
 * author: jokhan
 * date: 2017年 05月 26日 星期五 11:31:26 CST
 * function: main.cpp
 */
#include <iostream>

using namespace std;

class Solution {
public:
	int climbStairs( int n ) {
		int* num = new int[n];
		if( n == 1 ) {
			return 1;
		}
		if( n == 2 ) {
			return 2;
		}
		num[0] = 1;
		num[1] = 2;
		for( int i = 2; i < n; i ++ ) {
			num[i] = num[i-1] + num[i-2];
		}
		return num[n-1];
	}
};


int main()
{
	int num = 4;
	Solution slt;
	cout << slt.climbStairs( num ) << endl;
	return 0;
}
