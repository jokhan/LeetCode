/*
 * author: jokhan
 * date: 2017年 05月 25日 星期四 19:45:41 CST
 * function: main.cpp
 */
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string addBinary(string a, string b)
	{
		string result = "";
		int bit = 0;
		int len = min( a.size(), b.size() );
		int i = 0;
		for( i = 0; i < len; i ++) {
			int numTmp = a[a.size() - 1 - i] - '0' + b[ b.size() - 1 - i] - '0' + bit;
			char num = numTmp % 2 + '0';
			result = num + result;
			bit = numTmp / 2;
		}
		for( int j = a.size() - len - 1; j >= 0; j -- )  {
			int numTmp = a[j] - '0' + bit;
			char num = numTmp % 2 + '0';
			result = num + result;
			bit = numTmp / 2;
		}
		for( int j = b.size() - len - 1; j >= 0; j -- )  {
			int numTmp = b[j] - '0' + bit;
			char num = numTmp % 2 + '0';
			result = num + result;
			bit = numTmp / 2;
		}
		if( bit > 0 ) {
			result = "1" + result;
		}
		return result;
	}
};

int main()
{
	string a = "100";
	string b = "110010";
	Solution slt;
	cout << slt.addBinary(a,b) << endl;
	return 0;
}
