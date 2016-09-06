/*
 * author: jokhan
 * date: 2016年 09月 05日 星期一 20:49:44 CST
 * function: main.cpp
 */
#include <iostream>
#include <cstdio>

using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode( int x ): val( x ), next(NULL) {}
};

void printListNode( ListNode* list );

class Solution {
public:
	ListNode* addTwoNumbers( ListNode* l1, ListNode* l2 ) {
		//************数据溢出********//
		/*
		ListNode* result, *pList;
		unsigned long long num1 = 0;
		unsigned long long num2 = 0;
		for( int i = 1; l1 != NULL; l1 = l1 -> next ) {
			num1 += i * l1 ->val;
			i *= 10;
		}
		for( int i = 1; l2 != NULL; l2 = l2 -> next ) {
			num2 += i * l2 ->val;
			i *= 10;
		}
		unsigned long long sum = num1 + num2;
		int val = sum % 10;
		sum /= 10;
		result = new ListNode( val );
		pList = result;
		for( ; sum != 0; sum /= 10 ) {
			val = sum % 10;
			ListNode* pNext = new ListNode( val );
			pList->next = pNext;
			pList = pNext;
		}
		return result;
		*/
		ListNode* result;
		ListNode *pCur, *pNext;
		int tmp = l1->val + l2->val;
		int val = tmp % 10;
		int bit = tmp / 10;
		result = new ListNode( val );
		pNext = pCur = result;
		for( l1 = l1->next, l2 = l2 -> next; l1 != NULL || l2 != NULL; ) {
			int num1, num2;
			if( l1 != NULL ) {
				num1 = l1 -> val;
				l1 = l1 -> next;
			} else {
				num1 = 0;
			}
			if( l2 != NULL ) {
				num2 = l2 -> val;
				l2 = l2 -> next;
			} else {
				num2 = 0;
			}
			tmp = num1 + num2 + bit;
			val = tmp % 10;
			pNext = new ListNode( val );

			pCur->next = pNext;
			pCur = pNext;

			bit = tmp / 10;
		}
		if( bit > 0 ) {
			pNext = new ListNode( bit);
			pCur -> next = pNext;
			pCur = pNext;
		}

		return result;
	}
};

int main()
{
	ListNode *l1, *l2, *pCur, *pNext;
	int list1[] = { 9 };
	int list2[] = { 1, 9, 9, 9, 9, 9, 9, 9, 9, 9 };
	int length1 = sizeof( list1 ) / sizeof( list1[0] );
	int length2 = sizeof( list2 ) / sizeof( list2[0] );
	//********init list1******//
	l1 = new ListNode( list1[0] );
	pNext = pCur = l1;
	for( int i = 1; i < length1; i ++ ) {
		pNext = new ListNode( list1[i] );
		pCur->next = pNext;
		pCur = pNext;
	}
	//********init list1******//
	l2 = new ListNode( list2[0] );
	pNext = pCur = l2;
	for( int i = 1; i < length2; i ++ ) {
		pNext = new ListNode( list2[i] );
		pCur->next = pNext;
		pCur = pNext;
	}

	printListNode( l1 );
	printListNode( l2 );

	ListNode* result;
	Solution slt;
	result = slt.addTwoNumbers( l1, l2 );
	printListNode( result );
	return 0;
}

void printListNode( ListNode* list ) 
{
	ListNode* pTmp;
	pTmp = list;
	for( ; pTmp != NULL; pTmp = pTmp -> next ) {
		cout << pTmp->val << "->";
	}
	cout << endl;
}
