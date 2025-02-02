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

    public:
    TreeNode() : val(0) , right(nullptr) , left(nullptr) {}
    TreeNode(int x) : val(x) , right(nullptr) , left(nullptr) {}
    TreeNode(int x ,TreeNode* left1 , TreeNode* right1) : val(x) , right(right1) , left(left1) {}
};

class Iterative{
    public:
    vector<int> preorder(TreeNode* root)
    {
        vector<int> ans ;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode* node = st.top();
            st.pop();
            ans.push_back(node->val);
            if (node->left != nullptr)
            {
                st.push(node->left);
            }
            if (node->right != nullptr)
            {
                st.push(node->right);
            }
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
    Iterative* pre = new Iterative();
    vector<int> arr = pre->preorder(node);
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}