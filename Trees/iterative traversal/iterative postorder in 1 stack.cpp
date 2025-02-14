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

    TreeNode() : val(0) , right(nullptr) , left(nullptr) {}
    TreeNode(int x) : val(x) , right(nullptr) , left(nullptr) {}
    TreeNode(int x , TreeNode* right1 , TreeNode* left1) : val(x) , right(right1) , left(left1) {}
};

class Iterative{

    public:
    vector<int> postorder(TreeNode* root)
    {
        vector<int> ans;
        TreeNode* node = root;
        stack<TreeNode*> st;
        TreeNode* temp;
        while (!st.empty() || node!= NULL)
        {
            if (node != nullptr)
            {
                st.push(node);
                node = node->left;
            }
            else
            {
                temp = st.top()->right;
                if (temp == nullptr)
                {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);
                    while (!st.empty() && temp == st.top()->right)
                    {
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }
                else
                {
                    node = temp;
                }
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
    vector<int> arr = in->postorder(node);
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}