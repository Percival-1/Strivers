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
    TreeNode(int x , TreeNode* right1 , TreeNode* left1) : val(x) , right(right1) , left(left1) {}
};

class Iterative{
    public:
    vector<int> fun(TreeNode* root , int k)
    {
        stack<pair<TreeNode*,int>> st;
        st.push({root,1});
        vector<int> pre , in , post;
        if (root == nullptr)
        {
            return {};
        }
        while (!st.empty())
        {
            auto it = st.top();
            st.pop();

            // pre ncrement 1 to 2
            if (it.second == 1)
            {
                pre.push_back(it.first->val);
                it.second++;
                st.push(it);

                if (it.first->left != nullptr)
                {
                    st.push({it.first->left , 1});
                }
            }
            

            // in increment from 2 to 3

            else if (it.second == 2)
            {
                in.push_back(it.first->val);
                it.second++;
                st.push(it);

                if (it.first->right != nullptr)
                {
                    st.push({it.first->right , 1});
                }
                
            }
            
            else
            {
                post.push_back(it.first->val);
            }
        }
        if (k == 1)
        {
            return pre;
        }
        if (k == 2)
        {
            return in;
        }
        return post;
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
    Iterative* all = new Iterative();
    vector<int> arr = all->fun(node , 3);
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}