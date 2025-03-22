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
  TreeNode(int data) : val(data) , right(nullptr) , left(nullptr) {}
  TreeNode(int data , TreeNode* right1 , TreeNode* left1) : val(data) , right(right1) , left(left1){}
};

TreeNode* searchBST(TreeNode* root , int data)
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
  
  TreeNode* node = new TreeNode(10);
  node->left = new TreeNode(5);
  node->left->left = new TreeNode(3);
  node->left->right = new TreeNode(6);
  node->left->left->left = new TreeNode(2);
  node->left->left->right = new TreeNode(4);
  node->left->right->right = new TreeNode(9);
  node->right = new TreeNode(13);
  node->right->left = new TreeNode(11);
  node->right->right = new TreeNode(14);
  cout<<searchBST(node , 9)->val;
  return 0;
}
