/*
 * author: jokhan
 * date: 2016年 09月 16日 星期五 20:26:37 CST
 * function: main.cpp
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	string longestCommonPrefix( vector<string>& strs ) {
		string result = "";
		if( strs.size() == 0 )
			return "";
		else if( strs.size() == 1 )
			return strs.at( 0 );
		int minStrIndex = 0;
		for( int i = 0; i < strs.size(); i ++ ) {
			minStrIndex = strs.at( i ).size() < strs.at( minStrIndex ).size() ? i : minStrIndex;
		}
		int mid = ( 1 + strs.at( minStrIndex ).size() ) / 2;
		string strMatch = strs.at( minStrIndex );
		while( strMatch.size() > 1 ) {
			string tmpMatch = result + strMatch.substr(0, mid);
			if( isCommonPrefix( tmpMatch, strs ) ) {
				//左侧成功匹配
				result = tmpMatch;
				//保存成功部分
				strMatch = strMatch.substr(mid,strMatch.size() - mid);
				//继续匹配右侧部分
			} else {
				//左侧失败，继续分割左侧
				strMatch = strMatch.substr(0,mid);
			}
			mid = ( strMatch.size() + 1 ) / 2;
		}
		//剩下一个单独处理
		if ( isCommonPrefix( result + strMatch, strs ) )
			result += strMatch;
		return result;
	}
private:
	bool isCommonPrefix( string str, vector<string>& strs )
	{
		if( str.size() == 0 )
			return true;
		for( int i = 0; i < strs.size(); i ++ ) {
			if( 0 != strs.at(i).find(str) ) {
				return false;
			}
		}
		return true;
	}
};


int main()
{
	vector<string> strs;
	strs.push_back( "ab" );
	strs.push_back( "ab" );
	strs.push_back( "abc" );
	Solution slt;
	cout << slt.longestCommonPrefix( strs ) << endl;
	return 0;
}
