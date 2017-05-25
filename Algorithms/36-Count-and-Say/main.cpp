/*
 * author: jokhan
 * date: 2017年 05月 25日 星期四 17:27:21 CST
 * function: main.cpp
 */
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:
	string countAndSay( int n ) 
	{
		string org = "1";
		count( org, n-1 );
		return org;

	}
	void count( string& strOrg, int n )
	{
		if( n <= 0 ) {
			return ;
		}
		string str = "";
		char tmp = strOrg[0];
		int num = 1;
		for( int i = 1; i < strOrg.size(); i ++ ) {
			if( tmp == strOrg[i] ) {
				num ++;
			} else {
				changeStr( str, num, tmp );
				tmp = strOrg[i];
				num = 1;
			}
		}
		changeStr( str, num, tmp );
		strOrg = str;
		count( strOrg, n - 1 );
	}
	void changeStr( string& str, int num, char ch )
	{
		char tmp[255];
		sprintf( tmp, "%d%c", num, ch);
		string tmpStr;
		tmpStr = tmp;
		str += tmpStr;
	}
};

int main()
{
	Solution slt;
	string str;
	str = slt.countAndSay(55);
	cout << str << endl;
	return 0;
}
