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
    
    public:
    Node* deleteNode(Node* root , int k)
    {
        if(root == nullptr)
        {
            return NULL;
        }
        if(root->data == k)
        {
            return helper(root);
        }
        Node* mover = root;
        while (mover!=nullptr)
        {
            if(mover->data > k)
            {
                if (mover->left != nullptr && mover->left->data == k)
                {
                    mover->left = helper(mover->left);
                    break;
                }
                else
                {
                    mover = mover->left;
                }
            }
            else
            {
                if(mover->right != nullptr && mover->right->data == k)
                {
                    mover->right = helper(mover->right);
                    break;
                }
                else
                {
                    mover = mover->right;
                }
            }
        }
        return root;
    }

    public:
    Node* helper(Node* root)
    {
        if(root->left == NULL)
        {
            return root->right;
        }
        if (root->right == NULL)
        {
            return root->left;
        }
        Node* rightChild = root->right;
        Node* lastRight = findLastRight(root->left);
        lastRight->right = rightChild;
        return root->left;
    }

    public:
    Node* findLastRight(Node* root)
    {
        if(root->right == NULL)
        {
            return root;
        }
        return findLastRight(root->right);
    }

    public:
    void inorder(Node* node)
    {
        if (node == nullptr)
        {
            return;
        }
        inorder(node->left);
        cout<<node->data<<" ";
        inorder(node->right);
    }
};

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
    node->deleteNode(node , 5);
    node->inorder(node);
    return 0;
}