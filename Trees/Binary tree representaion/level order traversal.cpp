#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<stack>
#include<queue>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    public:
    TreeNode() : val(0) , right(nullptr) , left(nullptr) {}
    TreeNode(int x) : val(x) , right(nullptr) , left(nullptr) {}
    TreeNode(int x , TreeNode* left1 , TreeNode* right1) : val(x) , left(left1) , right(right1) {} 
};

class Level{
    public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        if (root == nullptr)
        {
            return ans;
        }
        while (!q.empty())
        {
            vector<int> level;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if (node->right != nullptr)
                {
                    q.push(node->right);
                }
                if (node->left != nullptr)
                {
                    q.push(node->left);
                }
                level.push_back(node->val);
            }
            ans.push_back(level);
        }
        return ans;
    }

    void print(vector<vector<int>> ans)
    {
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
};

int main(){
    
    return 0;
}