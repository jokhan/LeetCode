/*
 * author: jokhan
 * date: 2017年 05月 24日 星期三 20:32:19 CST
 * function: main.cpp
 */
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		int len = s.size();
		stack<int> index;
		for( int i = 0; i < len; i ++ ) {
			if( s[i] == '(' ) {
				index.push( i );
			} else {
				if( !index.empty() && s[ index.top() ] == '(' ) {
					index.pop();
				} else {
					index.push(i);
				}
			}
		}
		int result = 0;
		int tail = len;
		int head = 0;
		if( index.empty() ) {
			result = len;
			return result;
		}
		while( !index.empty() ) {
			head = index.top();
			index.pop();
			result = max( tail - head - 1, result );
			tail = head;
		}
		result = max( result, head );
		return result;
	}
};

int main()
{
	return 0;
}
