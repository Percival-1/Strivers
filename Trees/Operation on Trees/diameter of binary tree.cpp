#include <iostream>
#include<cmath>
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



int height(TreeNode* root , int& maxi)
{
  TreeNode* node= root;
  
  if(node == nullptr)
  {
    return 0;
  }
  
  int lh = height(node->left , maxi);
  int rh = height(node->right , maxi);
  
  maxi = max(maxi , rh  + lh);
  return 1 + max(lh , rh);
}

int diameterOfBinary(TreeNode* root)
{
  int dia = 0;
  TreeNode* node = root;
  int h = height(node , dia);
  return dia;
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
  
  int dia = diameterOfBinary(node);
  cout<<"Diameter of binary tree is : "<<dia<<endl;
  
  return 0;
}
