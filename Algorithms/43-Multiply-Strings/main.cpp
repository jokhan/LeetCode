/*
 * author: jokhan
 * date: 2017年 05月 26日 星期五 19:54:53 CST
 * function: main.cpp
 */
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string multiply(string num1, string num2)
	{
		string result = "0";
		int len1 = num1.size();
		int len2 = num2.size();
		for( int i = len2 - 1; i >= 0; i -- ) {
			string str1 = num1;
			int bit = 0;
			for( int j = len1 - 1; j >= 0; j -- ) {
				int tmp = (num1[j] - '0') * (num2[i] - '0') + bit; 
				bit = tmp / 10;
				char ch = tmp % 10 + '0';
				str1[j] = ch;
			}
			if( bit > 0 ) {
				char ch = bit + '0';
				str1 = ch + str1;
			}
			for( int k = 0; k < len2 - 1 - i; k ++ ) {
				str1 += '0';
			}
			result = plus( result, str1 );
		}
		return result;
	}
	string plus( string num1, string num2 )
	{
		string result = "";
		int len1 = num1.size();
		int len2 = num2.size();
		int len = min( len1, len2 );
		int bit = 0;
		for( int i = 0; i < len; i ++ ) {
			int tmp = num1[ len1 - 1 - i ] - '0' + num2[ len2 - 1 - i ] - '0' + bit;
			bit = tmp / 10;
			char ch = tmp % 10 + '0';
			result = ch + result;
		}
		for( int i = len; i < len1; i ++ ) {
			int tmp = num1[ len1 - 1 - i ] - '0' + bit ;
			bit = tmp / 10;
			char ch = tmp % 10 + '0';
			result = ch + result;
		}
		for( int i = len; i < len2; i ++ ) {
			int tmp = num2[ len2 - 1 - i ] - '0' + bit ;
			bit = tmp / 10;
			char ch = tmp % 10 + '0';
			result = ch + result;
		}
		if( bit > 0 ) {
			char ch = bit + '0';
			result = ch + result;
		}
		string str = "";
		bool zero = true;
		int i = 0;
		for( i = 0; i < result.size() - 1; i ++ ) {
			if( result[i] == '0' && zero ) {
				continue;
			} else {
				zero = false;
				str += result[i];
			}
		}
		str += result[i];
		return str;
	}
};

int main()
{
	string str1 = "123";
	string str2 = "456";
	Solution slt;
	cout << slt.multiply(str1, str2) << endl;
	return 0;
}
