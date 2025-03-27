#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<stack>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* right;
    Node* left;

    public:
    Node() : data(0) , right(nullptr) , left(nullptr) {}
    Node(int val) : data(val) , right(nullptr) , left(nullptr) {}
    Node(int val , Node* right1 , Node* left1) : data(val) , right(right1) , left(left1) {}
};

Node* buildTreeR(vector<int> &postorder , int postStart , int postEnd , vector<int> &inorder , int inStart , int inEnd , unordered_map<int , int> &mp)
{
    if(postStart > postEnd || inStart > inEnd)
    {
        return NULL;
    }

    Node* root = new Node(postorder[postEnd]);

    int introot = mp[root->data];
    int leftlen = introot - inStart;

    root->left = buildTreeR(postorder , postStart , postStart + leftlen - 1 , inorder , inStart , introot - 1 , mp);
    root->right = buildTreeR(postorder , postStart + leftlen , postEnd - 1 , inorder , introot + 1 , inEnd , mp);
    return root;
}

Node* buildTree(vector<int> postorder , vector<int> inorder)
{
    unordered_map<int , int> mp;

    for (int i = 0; i < inorder.size(); i++)
    {
        mp[inorder[i]] = i;
    }

    Node* root = buildTreeR(postorder , 0 , postorder.size() - 1 , inorder , 0 , inorder.size() - 1 , mp);
    return root;
}

void printTree(Node* root, string indent = "", bool isLeft = true) {
    if (root == nullptr) {
        return;
    }

    cout << indent;
    if (isLeft) {
        cout << "L----";
    } else {
        cout << "R----";
    }
    cout << root->data << endl;

    printTree(root->left, indent + (isLeft ? "     " : "|    "), true);
    printTree(root->right, indent + (isLeft ? "     " : "|    "), false);
}

void inorderprint(Node* root)
{
    if(root == nullptr)
    {
        return;
    }
    inorderprint(root->left);
    cout<<root->data<<" ";
    inorderprint(root->right);
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    vector<int> inorder = {40,20,50,10,60,30};
    vector<int> postorder = {40,50,20,60,30,10};

    Node* root = buildTree(postorder , inorder);

    inorderprint(root);
    cout<<endl;

    printTree(root);
    return 0;
}