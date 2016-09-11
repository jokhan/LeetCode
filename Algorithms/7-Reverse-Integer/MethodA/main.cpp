/*
 * author: jokhan
 * date: 2016年 09月 11日 星期日 14:47:50 CST
 * function: main.cpp
 */
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
	int reverse( int x ) {
		int result = 0;
		int symbol = 1;
		vector<int> number;
		if( x < 0 ) {
			x = -x;
			symbol = -1;
		}
		for( ; x > 0; x /= 10 ) {
			number.push_back( x % 10 );
		}
		int bit = 1;
		for( int i = number.size() - 1; i >= 0; i --) {
			if( INT_MAX / bit < number.at(i) ) {
				//检查溢出
				return 0;
			}
			int tmp = number.at(i) * bit;
			if( INT_MAX - result < tmp ) {
				//检查溢出
				return 0;
			}
			result += tmp;
			bit *= 10;
		}
		result *= symbol;
		return result;
	}
};


int main()
{
	int x = -2147483412;
	//int x = 1534236469;
	Solution slt;
	cout << slt.reverse( x ) << endl;
	cout << INT_MAX << endl;
	cout << INT_MIN << endl;
	return 0;
}
