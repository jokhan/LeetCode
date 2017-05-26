/*
 * author: jokhan
 * date: 2017年 05月 26日 星期五 19:25:20 CST
 * function: main.cpp
 */
#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteDeplicates( ListNode* head ) 
	{
		if( head == NULL ) {
			return head;
		}
		ListNode* pre = head;
		ListNode* p = head;
		p = p -> next;
		while( p != NULL ) {
			if( p -> val != pre -> val ) {
				pre -> next = p;
				pre = p;
			}
			p = p -> next;
		}
		pre->next = NULL;
		return head;
	}
};

int main()
{
	return 0;
}
