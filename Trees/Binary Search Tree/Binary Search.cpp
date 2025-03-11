#include<iostream>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<cmath>
#include<map>

using namespace std;

class TreeNode{
  
  public:
  int val;
  TreeNode* right;
  TreeNode* left;
  
  public:
  TreeNode() : val(0) , right(nullptr) , left(nullptr){}
  TreeNode(int data) : val(data) , right(nullptr0 , left(nullptr) {}
  TreeNode(int data , TreeNode* right1 , TreeNode* left1) : val(data) , right(right1) , left(left1){}
};

TreeNode* searchBST(TreeNode* root m int data)
{
  TreeNode* node = root;
  while(node!=nullptr && node->val!= data)
  {
    if(node->val < data)
    {
      node = node->right;
    }
    else
    {
      node = node->left;
    }
  }
  return node;
}

int main()
{
  
  TreeNode* node = new TreeNode(20);
  node->left = new TreeNode(20);
  node->left->left = new TreeNode(20);
  node->left->right = new TreeNode(20);
  node->
  return 0;
}
