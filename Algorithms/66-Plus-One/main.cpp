/*
 * author: jokhan
 * date: 2017年 05月 25日 星期四 19:20:52 CST
 * function: main.cpp
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>&digits) 
	{
		vector<int> result;
		int bit = 0;
		vector<int> tmp;
		int i = digits.size() - 1;
		for( i = digits.size() - 1; i >= 0; i -- ) {
			int numTmp = ( digits[i] + 1 ) ;
			int num = numTmp % 10;
			tmp.push_back( num );
			bit = numTmp / 10;
			if( bit == 0 ) {
				break;
			}
		}
		if( bit > 0 ) {
			tmp.push_back( bit );
		}
		for( int j = 0; j < i; j ++ ) {
			result.push_back( digits[j] );
		}
		for( int j = tmp.size() - 1; j >= 0; j -- ) {
			result.push_back( tmp[j] );
		}
		return result;
	}
};

int main()
{
	int a[] = {9,9};
	vector<int> num(a,a+2);
	Solution slt;
	slt.plusOne( num );
	return 0;
}
