/*
 * author: jokhan
 * date: 2017年 05月 28日 星期日 21:08:50 CST
 * function: main.cpp
 */
#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode( int x ) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
	string serialize(TreeNode* root)
	{
		/*
		string result = "";
		queue<TreeNode*> nodes;
		nodes.push( root );
		while( !nodes.empty() ) {
			TreeNode* tmp = nodes.front();
			nodes.pop();
			if( tmp != NULL ) {
				nodes.push( tmp->left );
				nodes.push( tmp->right );
				char ch = tmp->val + '0';
				result += ch;
			} else {
				char ch = 'n';
				result += ch;
			}
		}
		return result;
		*/
		if( root == NULL ) {
			return "#";
		}
		return to_string(root->val) + "," + serialize( root->left ) + "," + serialize( root->right );
	}
	TreeNode* deserialize(string data)
	{
		return myDeserialize(data);
		/*
		int len = data.size();
		if( len <= 0 ) {
			return NULL;
		}
		int val = data[0] - '0';
		TreeNode* root = new TreeNode(val);
		queue<TreeNode*> leef;
		leef.push(root);
		int i = 2;
		while( i < len ) {
			TreeNode* tmp = leef.front();
			if( data[i - 1] != 'n' ) {
				TreeNode* leftCh = new TreeNode( data[i-1] - '0' );
				leef.push( leftCh );
				tmp -> left = leftCh;
			} else {
				tmp->left = NULL;
			}
			if( data[i] != 'n' ) {
				TreeNode* rightCh = new TreeNode( data[i] - '0' );
				leef.push( rightCh );
				tmp->right = rightCh;
			} else {
				tmp->right = NULL;
			}
			i += 2;
			leef.pop();
		}
		return root;
		*/
	}
	TreeNode* myDeserialize( string& data )
	{
		if( data[0] == '#' ) {
			if( data.size() > 2 ) {
				data = data.substr(2);
			}
			return NULL;
		}
		TreeNode* node = new TreeNode( dealData( data ) );
		node->left = myDeserialize( data );
		node->right = myDeserialize(data);
		return node;
	}
	int dealData( string& data )
	{
		int pos = data.find(",");
		int result = stoi(data.substr(0,pos));
		data = data.substr(pos+1);
		return result;
	}
};

int main()
{
	Codec slt;
	string str = "1,2,3,#,#,4,5,#,#,#,#";
	TreeNode* root = slt.deserialize(str);
	cout << slt.serialize(root) << endl;
	return 0;
}
