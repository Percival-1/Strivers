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
                if (node->left != nullptr)
                {
                    q.push(node->left);
                }
                if (node->right != nullptr)
                {
                    q.push(node->right);
                }
                
                level.push_back(node->val);
            }
            ans.push_back(level);
        }
        return ans;
    }

    public:
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
    TreeNode* node = new TreeNode(1);
    node->left = new TreeNode(2);
    node->right = new TreeNode(3);
    node->left->left = new TreeNode(4);
    node->left->right = new TreeNode(5);
    node->left->right->left = new TreeNode(6);
    node->left->right->right = new TreeNode(7);
    Level* l = new Level();
    vector<vector<int>> arr = l->levelOrder(node);
    l->print(arr);
    return 0;
}