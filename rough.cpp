#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<stack>
#include<queue>
using namespace std;

class TreeNode {
	public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
	public:
		vector<vector<int>> levelOrder(TreeNode* root) {
			queue<TreeNode*> q;
			vector<vector<int>> ans;
			
			if(root == nullptr)
			{
				return ans;
			} 
			q.push(root);
			while(!q.empty())
			{
				int levelsize = q.size();
				vector<int> level;
				for (int i = 0; i < levelsize; i++)
				{
					TreeNode* node = q.front();
					q.pop();
					level.push_back(node->val);
					if(node->left != nullptr)
					{
						q.push(node->left);
					}
					if (node->right != nullptr)
					{
						q.push(node->right);
					}
				}
				ans.push_back(level);
			}
			return ans;
		}
	};

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	return 0;
}