#include<iostream>
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

bool sameTree(TreeNode* p , TreeNode* q)
{
  if( p == nullptr && q == nullptr)
  {
    return (p == q);
  }
  return (p->val == q->val)
          && sameTree(p->left , q->left)
          && sameTree(p->right , q->right);
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
  node->left->right->left->left = new TreeNode(8);
  node->left->right->left->right = new TreeNode(9);
  node->right->left = new TreeNode(10);
  
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->left->right->left = new TreeNode(6);
  root->left->right->right = new TreeNode(7);
  root->left->right->left->left = new TreeNode(8);
  root->left->right->left->right = new TreeNode(9);
  root->right->left = new TreeNode(10);
  
  cout<<sameTree(node , root);
  return 0;
}
