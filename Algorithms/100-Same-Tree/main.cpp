/*
 * author: jokhan
 * date: 2017年 05月 26日 星期五 19:41:40 CST
 * function: main.cpp
 */
#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode( int x ) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if( p == NULL || q == NULL ) {
			if( p == q ) {
				return true;
			} else {
				return false;
			}
		} else {
			if( p->val != q->val ) {
				return false;
			} else {
				return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
			}
		}
	}
};


int main()
{
	return 0;
}
