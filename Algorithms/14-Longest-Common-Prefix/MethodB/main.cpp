/*
 * author: jokhan
 * date: 2016年 09月 16日 星期五 12:29:45 CST
 * function: main.cpp
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	string longestCommonPrefix( vector<string>& strs ) {
		string result = "";
		if ( strs.size() == 0 )
			return "";
		else if ( strs.size() == 1 )
			return strs.at( 0 );
		string strNew = prefixTwoStr( strs.at( 0 ), strs.at( 1 ) );
		strs.erase( strs.begin(), strs.begin() + 2 );
		strs.push_back( strNew );
		return longestCommonPrefix( strs );
	}
	string prefixTwoStr( string str1, string str2 ) {
		int len = 0;
		for( int i = 0; i < min( str1.size(), str2.size() ); i ++ ) {
			if ( str1.at( i ) == str2.at( i ) )
				len ++;
			else
				break;
		}
		return str1.substr( 0, len );
	}
};


int main()
{
	Solution slt;
	vector<string> a;
	a.push_back( "" );
	cout << slt.longestCommonPrefix( a ) << endl;
	return 0;
}
