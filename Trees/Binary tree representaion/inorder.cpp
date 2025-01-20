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
    Node(int data1)
    {
        data = data1;
        right = left = nullptr;
    }
};

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

int main(){
    Node* node = new Node(1);
    node->left = new Node(2);
    node->left->left = new Node(4);
    node->left->right = new Node(5);
    node->left->right->left = new Node(8);
    node->right = new Node(3);
    node->right->left = new Node(6);
    node->right->right = new Node(7);
    node->right->right->left = new Node(9);
    node->right->right->right = new Node(10);
    inorder(node);
    return 0;
}