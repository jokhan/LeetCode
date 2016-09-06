/*
 * author: jokhan
 * date: 2016年 09月 06日 星期二 15:21:45 CST
 * function: main.cpp
 */
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring( string s ) {
		string subString = "";
		string longestStr = "";
		int back = 0;
		size_t found = 0;
		for( ; back < s.length(); back++ ) {
			found = subString.find( s[ back ] );
			if ( found != string::npos ) {
				// save the longest substring
				if ( subString.length() > longestStr.length() ) {
					longestStr = subString;
				}
				// delete repeat substring
				subString.erase( 0, found + 1 );
			}
			subString.push_back( s[ back ] );
		}
		return longestStr.length() > subString.length() ? longestStr.length() : subString.length();
	}
};

int main()
{
	string s = "cdd";
	int result = 0;
	Solution slt;
	result = slt.lengthOfLongestSubstring( s );
	cout << result << endl;
	return 0;
}
