/*
 * author: jokhan
 * date: 2016年 09月 07日 星期三 09:37:38 CST
 * function: main.cpp
 */
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string longestPalindrome( string s ) {
		//**************Time Limit Exceeded*******//
		/*
		string result = "";
		string sNew = s;
		//reverse the string s
		for ( int i = 0; i < sNew.length(); i ++ ) {
			sNew.at(i) = s.at( s.length() - i - 1 );
		}
		for( int longestLengh = s.length(); longestLengh > 0; longestLengh -- ) {
			int head = 0;
			int tail = head + longestLengh - 1;
			for( ; tail < s.length(); tail = head + longestLengh - 1) {
				if( s.substr( head, longestLengh) == sNew.substr( s.length() - 1 - tail, longestLengh ) ) {
					result = s.substr( head, longestLengh);
					return result;
				}
				head ++;
			}
		}

		return result;
		*/

	}
};

int main()
{
	string s = "cabababc";
	Solution slt;
	cout << slt.longestPalindrome( s ) << endl;
	return 0;
}
