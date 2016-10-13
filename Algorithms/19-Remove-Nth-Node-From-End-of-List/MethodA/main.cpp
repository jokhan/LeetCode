/*
 * author: jokhan
 * date: 2016年 10月 13日 星期四 21:14:01 CST
 * function: main.cpp
 */
#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *myHead = new ListNode( 0 );
    myHead -> next = head;
    ListNode * first = myHead, * second = myHead;
    for( int i = 0; i <= n; ++ i) {
        first = first -> next;
    }
    while( first != NULL) {
        first = first -> next;
        second = second -> next;
    }
    second -> next = second -> next -> next;

    return myHead -> next;
    }
};

void printLink( ListNode *head );


int main()
{
    ListNode * head = new ListNode( 1 );
    ListNode * pList = head;
    for( int i = 2; i < 6; ++ i) {
        ListNode * pListTmp = new ListNode( i );
        pList -> next = pListTmp;
        pList = pList -> next;
    }
    Solution slt;
    printLink( slt.removeNthFromEnd( head, 5 ) );
    return 0;
}

void printLink( ListNode *head )
{
    ListNode *pList = head;
    while( pList != NULL ) {
        cout << pList -> val << "-";
        pList = pList -> next;
    }
    cout << endl;
}

