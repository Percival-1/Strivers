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
    int val;
    Node* right;
    Node* left;

    public:
    Node() : val(0) , right(nullptr) , left(nullptr) {}
    Node(int x) : val(x) , right(nullptr) , left(nullptr) {}
    Node(int x , Node* right1 , Node* left1) : val(x) , right(right1) , left(left1) {}
};

Node* insert(Node* root , int k)
{
    if(root == nullptr)
    {
        return new Node(k);
    }
    Node* mover = root;
    while(root)
    {
        if(mover->val <= k)
        {
            if(mover->right != nullptr)
            {
                mover = mover->right;
            }
            else
            {
                mover->right = new Node(k);
                break;
            }
        }
        else
        {
            if(mover->left != nullptr)
            {
                mover = mover->left;
            }
            else
            {
                mover->left = new Node(k);
                break;
            }
        }
    }
    return root;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    Node* node = new Node(10);
    node->left = new Node(5);
    node->left->left = new Node(3);
    node->left->right = new Node(6);
    node->left->left->left = new Node(2);
    node->left->left->right = new Node(4);
    node->left->right->right = new Node(9);
    node->right = new Node(13);
    node->right->left = new Node(11);
    node->right->right = new Node(14);
    
    return 0;
}