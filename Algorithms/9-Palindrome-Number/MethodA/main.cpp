/*
 * author: jokhan
 * date: 2016年 09月 13日 星期二 16:03:37 CST
 * function: main.cpp
 */
#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:
	bool isPalindrome( int x ) {
		if( x < 0 )
			return false;
		bool result = true;
		int length = 1;
		for( int i = 10; x / i != 0; i *= 10 ) {
			length ++;
			if( length == 10 )
				break;
		}
		int tmp = 1, tail = 0, head = 0;
		for( ; length > 0; length -= 2 ) {
			tmp = 1;
			for( int i = 1; i < length; i ++ ) {
				tmp *= 10;
			}
			tail = x % 10;
			head = x / tmp;
			if( tail == head ) {
				x = ( x % tmp ) / 10;
			} else {
				return false;
			}

		}
		return result;
	}
};


int main()
{
	int x = 0;
	x = 1410110141;
	Solution slt;
	cout << INT_MAX << endl;
	cout<<slt.isPalindrome( x )<<endl;;
	return 0;
}
