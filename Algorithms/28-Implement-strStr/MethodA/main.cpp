/*
 * author: jokhan
 * date: 2017年 02月 28日 星期二 17:05:09 CST
 * function: main.cpp
 * KMP
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void initP(const string &str, vector<int> &P);
void funStrStr(const string& str, const string& subStr);

int main()
{
	string str = "abab";
	string subStr = "a";
	subStr = "0" + subStr;
	str = "0" + str;
	funStrStr( str, subStr );
	return 0;
}

void funStrStr(const string& str, const string& subStr)
{
	vector<int> subP(subStr.size());
	initP( subStr, subP );
	int j = 0;
	for( int i = 1; i < str.size(); i ++ ) {
		while(j > 0 && subStr[j+1] != str[i]) {
			j = subP[j];
		}
		if( subStr[j+1] == str[i] ) {
			j ++;
		}
		if( j == subStr.size() - 1 ) {
			//cout << i - j + 1 << endl;
			cout << i - j << endl;
			j = subP[j];
		}
	}
	
}

void initP(const string &str, vector<int> &P)
{
	P.at(0) = 0;
	P.at(1) = 0;
	int j = 0;
	for( int i = 2; i < str.size(); i ++ ) {
		while( j > 0 && str[j+1] != str[i] ) {
			j = P[j];
		}
		if( str[j+1] == str[i] ) {
			j ++;
		}
		P[i] = j;
	}
}
