#include<iostream>
#include<vector>
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

vector<vector<int>> zigZag(TreeNode* root)
{
  vector<vector<int>> ans;
  queue<TreeNode*> q;
  q.push(root);
  bool left2Right = true;
  while(!q.empty())
  {
    int size = q.size();
    vector<int> level(size);
    for (int i = 0; i < size; i++) 
    {
      TreeNode* node = q.front();
      q.pop();
      int index = (left2Right ? i : size - 1 - i);
      if(node->left != nullptr)
      {
        q.push(node->left);
      }
      if(node->right != nullptr)
      {
        q.push(node->right);
      }
      level[index] = node->val;
    }
    left2Right = !left2Right;
    ans.push_back(level);
  }
  return ans;
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
  vector<vector<int>> z = zigZag(node);
  for (int i = 0; i < z.size(); i++) {
    for (int j = 0; j < z[i].size(); j++) {
      cout<<z[i][j]<<" ";
    }
    cout<<endl;
  }
  
  return 0;
}
