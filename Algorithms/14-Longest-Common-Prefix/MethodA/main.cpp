/*
 * author: jokhan
 * date: 2016年 09月 15日 星期四 08:50:52 CST
 * function: main.cpp
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	string longestCommonPrefix( vector<string>& strs ) {
		string result = "";
		if( strs.size() <= 0 )
			return result;
		int minStrIndex = 0;
		for( int i = 0; i < strs.size(); i ++ ) {
			minStrIndex = strs.at( i ).size() < strs.at( minStrIndex ).size() ? i : minStrIndex;
		}
		for( int length  = strs.at( minStrIndex ).size(); length >= 0; length -- ) {
			int num = 0;
			result = strs.at( minStrIndex ).substr( 0, length );
			for( int i = 0; i < strs.size(); i ++ ) {
				if( i == minStrIndex )
					continue;
				if( 0 == strs.at( i ).find( result ) )
					num ++;
				else
					break;
			}
			if( num == strs.size() - 1 )
				break;
		}
		return result;
	}
};


int main()
{
	vector<string> strs;
	strs.push_back( "abcd" );
	strs.push_back( "cbd" );

	Solution slt;
	cout << slt.longestCommonPrefix( strs ) << endl;

	return 0;
}
