/*
 * author: jokhan
 * date: 2017年 05月 26日 星期五 15:22:58 CST
 * function: main.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

void merge(int* nums1, int m, int* nums2, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * (m+n)); 
	int index = 0;
	int i = 0, j = 0;
	while( i < m && j < n ) {
		if( nums2[j] < nums1[i] ) {
			tmp[index++] = nums2[j++];
		} else {
			tmp[index++] = nums1[i++];
		}
	}
	while( i < m ) {
		tmp[index++] = nums1[i++];
	}
	while( j < n ) {
		tmp[index++] = nums2[j++];
	}
	for( int i = 0; i < m + n; i ++ ) {
		nums1[i] = tmp[i];
	}
}

int main()
{
	return 0;
}
