/*
 * author: jokhan
 * date: 2017年 02月 27日 星期一 20:57:11 CST
 * function: main.cpp
 */
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {
		unsigned int divid = dividend, divis = divisor;
		if( dividend < 0 ) {
			divid = - divid;
		}
		if( divisor < 0 ) {
			divis = - divis;
		}
		long result = 0;
		while( divid >= divis ) {
			unsigned int tmp = divid;
			int i = 1;
			for( i = 1; tmp >= divis; i ++ ) {
				tmp >>= 1;
			}
			result += ( (long) 1 << ( i - 2 ) );
			divid -= ( divis << ( i - 2 ) );
		}
		if( dividend > 0 ^ divisor > 0 && dividend != 0) {
			if( result <= INT_MIN) {
				return INT_MAX;
			} else {
				return -result;
			}
		} else {
			return result > INT_MAX ? INT_MAX : result;
		}
	}
};

int main()
{
	Solution slt;
	int dividend = INT_MIN;
	int divisor = -1;
	cout << slt.divide( dividend, divisor ) << endl;
	cout << "hello" << endl;
	cout << INT_MAX << endl;
	cout << INT_MIN << endl;
	return 0;
}
