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

int findCeil(Node* root , int k)
{
    int ceil = -1;
    Node* mover = root;
    while(mover)
    {
        if (mover->val == k)
        {
            ceil = mover->val;
            return ceil;
        }
        
        if(mover->val < k)
        {
            ceil = mover->val;
            mover = mover->right;
        }
        else
        {
            mover = mover->left;
        }
    }
    return ceil;
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
    cout<<findCeil(node , 12);
    return 0;
}