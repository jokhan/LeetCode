/*
 * author: jokhan
 * date: 2016年 09月 12日 星期一 09:28:30 CST
 * function: main.cpp
 */
#include <iostream>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
	int myAtoi( string str ) {
		//****取出首部空格****//
		while( str[0] == ' ' ) {
			str.erase(0, 1);
		}

		if( str.empty() ) {
			return 0;
		}

		int result = 0;
		int head = 0;
		int symbol = 1;
		bool overflow = false;
		//*****判断符号*****//
		if( str.at( 0 ) == '-' ) {
			head = 1;
			symbol = -1;
		} else if ( str.at( 0 ) == '+' ) {
			head = 1;
			symbol = 1;
		}

		int bit = 1;
		for( int i = str.size() - 1; i >= head; i -- ) {
			if( str.at(i) < '0' || str.at(i) > '9' ) {
				//非法字符
				result = 0;
				bit = 1;
				overflow = false;
				continue;
			}
			if ( !overflow ) {
				//未溢出时继续转换
				int num = str.at(i) - '0';
				if( INT_MAX / bit < num ) {
					overflow = true;
					continue;
				}
				int tmp = num * bit;
				if( INT_MAX - result < tmp ) {
					overflow = true;
					continue;
				}
				result += tmp;
				if( i > head && INT_MAX / bit < 10 ) {
					overflow = true;
					continue;
				}
				bit *= 10;
			}

		}
		if ( overflow ) {
			return symbol > 0 ? INT_MAX : INT_MIN;
		}
		result *= symbol;
		return result;
	}
};


int main()
{
	//string str = "  +023 45";
	//string str = "-2147483647";
	//string str = "  +b12102370352";
	//string str = "1234567890123456789012345678901234567890";
	//string str = "    10522545459";
	string str = "-2147483647";
	Solution slt;
	cout << slt.myAtoi( str ) << endl;
	cout << str << endl;
	return 0;
}
