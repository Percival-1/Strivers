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
    TreeNode() : val(0) , left(nullptr) , right(nullptr) {}
    TreeNode(int x) : val(x) , left(nullptr) , right(nullptr) {}
    TreeNode(int x , TreeNode* left1 , TreeNode* right1) : val(x) , right(right1) , left(left1) {}
};

class Iterative{

    public:
    vector<int> inorder(TreeNode* root)
    {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* node = root;
        while (1)
        {
            if (node != nullptr)
            {
                st.push(node);
                node = node->left;
            }
            
            else
            {
                if (st.empty() == true)
                {
                    break;
                }
                
                node = st.top();
                st.pop();
                ans.push_back(node->val);
                node = node->right;
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
    Iterative* in = new Iterative();
    vector<int> arr = in->inorder(node);
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}