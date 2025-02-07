#include<iostream>
#include<vector>
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

bool isLeaf(TreeNode* root)
{
  if((root->left == nullptr) && (root->right == nullptr))
  {
    return true;
  }
  return false;
}

void addLeftBoundary(TreeNode* root , vector<int>& res)
{
  TreeNode* mover = root->left;
  while(mover)
  {
    if(!isLeaf(mover))
    {
      res.push_back(mover->val);
    }
    if(mover->left)
    {
      mover = mover->left;
    }
    else
    {
      mover = mover->right;
    }
  }
}

void addRightBoundary(TreeNode* root , vector<int>& res)
{
  vector<int> temp;
  TreeNode* mover = root->right;
  while(mover)
  {
    if(!isLeaf(mover))
    {
      temp.push_back(mover->val);
    }
    if(mover->right)
    {
      mover = mover->right;
    }
    else
    {
      mover = mover->left;
    }
  }
  for (int i = temp.size() - 1; i >= 0; i--) 
  {
    res.push_back(temp[i]);
  }
}

void addLeaf(TreeNode* root , vector<int> & res)
{
  if(isLeaf(root))
  {
    res.push_back(root->val);
    return;
  }
  if(root->left)
  {
    addLeaf(root->left , res);
  }
  if(root->right)
  {
    addLeaf(root->right , res);
  }
}

vector<int> printBoundary(TreeNode* root)
{
  vector<int> res;
  if(!root)
  {
    return res;
  }
  if(!isLeaf(root))
  {
    res.push_back(root->val);
  }
  addLeftBoundary(root, res);
  addLeaf(root , res);
  addRightBoundary(root , res);
  return res;
}

int main(){
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
  vector<int> ans = printBoundary(node);
  for (int i = 0; i < ans.size(); i++) {
    cout<<ans[i]<<" ";
  }
  cout<<endl;
  return 0;
}
