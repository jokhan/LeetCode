/*
 * author: jokhan
 * date: 2016年 09月 10日 星期六 19:30:11 CST
 * function: main.cpp
 */
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		string result = "";
		string zigZag[numRows];
		int row = 0;
		int down = 1;  //控制向下走，向上走
		for( int i = 0; i < s.length(); ++ i ) {
			zigZag[row].push_back( s.at(i) );
			if( down ) {
				if( row < numRows - 1) {
					row ++;
				} else if( row > 0 ) {
					down = 0;
					row --;
				}
			} else {
				if ( row > 0 ) {
					row --;
				} else if ( row < numRows - 1 ){
					down = 1;
					row ++;
				}
			}
		}

		for( int i = 0; i < numRows; i ++ ) {
			result += zigZag[ i ];
		}

		return result;
	}
};


int main()
{
	string s = "AB";
	int numRows = 1;
	string result = "PAHNAPLSIIGYIR";
	Solution slt;
	cout << slt.convert( s, numRows ) << endl;
	cout << result << endl;
	return 0;
}
