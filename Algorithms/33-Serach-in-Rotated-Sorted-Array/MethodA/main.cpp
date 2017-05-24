/*
 * author: jokhan
 * date: 2017年 05月 22日 星期一 16:21:25 CST
 * function: main.cpp
 */
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		int len = s.size();
		int result = 0;
		int lens = 0;
		int status = 0;
		stack<int> index;
		int left = 0;
		for(int i = 0; i < len; i ++) {
			if( status == 0 ) {
				if( s[i] == '(' ) {
					status ++;
					left ++;
					index.push(left);
				} else {
					lens = result > lens ? result : lens;
				}
			} else {
				if( s[i] == ')' ) {
					result += 2;
					status --;
					index.pop();
				} else {
					status ++;
					left ++;
					index.push(left);
				}
			}
		}
		result -= status * 2;
		lens = result > lens ? result : lens;
		return lens;
	}
};


int main()
{
	string s = "()(())";
	Solution slt;
	int num = 0;
	num = slt.longestValidParentheses(s);
	cout << num << endl;
	return 0;
}
