/*
 * author: jokhan
 * date: 2017年 05月 25日 星期四 18:50:52 CST
 * function: main.cpp
 */
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		int len = 0;
		int lastLen = 0;
		for( int i = 0; i < s.size(); i ++  ) {
			if( s[i] == ' ' ) {
				if( len > 0 ) {
					lastLen = len;
				}
				len = 0;
			} else {
				len ++;
			}
		}
		len = len > 0 ? len : lastLen;
		return len;
	}
};

int main()
{
	string str = "hello world";
	string s = "Today is a nice day ";
	Solution slt;
	cout << slt.lengthOfLastWord(s) << endl;
	return 0;
}
