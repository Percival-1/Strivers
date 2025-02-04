#include <iostream>
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

int height(TreeNode* root)
{
  TreeNode* node = root;
  if(node == nullptr)
  {
    return 0;
  }
  int lh = height(node->left);
  int rh = height(node->right);
  
  int maxi = max(lh , rh);
  return 1+ maxi;
}

int main() 
{
    TreeNode* node = new TreeNode(1);
    node->left = new TreeNode(2);
    node->right = new TreeNode(3);
    node->left->left = new TreeNode(4);
    node->left->right = new TreeNode(5);
    node->left->right->left = new TreeNode(6);
    node->left->right->right = new TreeNode(7);
    int h = height(node);
    cout<<"Maximum depth of binary tree is : "<<h<<endl;
    return 0;
}
