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
    TreeNode* right;
    TreeNode* left;

    TreeNode() : val(0) , left(nullptr) , right(nullptr) {}
    TreeNode(int x) : val(x) , left(nullptr) , right(nullptr) {}
    TreeNode(int x , TreeNode* left1 , TreeNode* right1) : val(x) , right(right1) , left(left1) {}
};

class Iterative
{
    public:
    vector<int> postorder(TreeNode* root)
    {
        vector<int> ans;
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        TreeNode* node = root;
        st1.push(root);
        while (!st1.empty())
        {
            node = st1.top();
            st1.pop();
            st2.push(node);
            if (node->left!=nullptr)
            {
                st1.push(node -> left);
            }
            if (node->right != nullptr)
            {
                st1.push(node->right);
            }
        }
        while (!st2.empty())
        {
             ans.push_back(st2.top()->val);
             st2.pop();
        }
        return ans;
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
    Iterative* post = new Iterative();
    vector<int> arr = post->postorder(node);
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}