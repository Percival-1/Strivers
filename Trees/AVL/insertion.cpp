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
    Node* left;
    Node* right;
    int height;

    public:
    Node() : data(0) , right(nullptr) , left(nullptr) , height(1) {}
    Node(int val) : data(val) , right(nullptr) , left(nullptr) , height(1){}
    Node(int val , Node* right1 , Node* left1 , int height1) : data(val) , right(right1) , left(left1) , height(height1) {}
};

int height(Node* root)
{
    if(root == nullptr)
    {
        return 0;
    }
    return root->height;
}

Node* rightRotate(Node* y)
{
    Node* x = y->left;
    Node* t = x->right;

    x->right = y;
    y->left = t;

    x->height = 1 + max(height(x->left) , height(x->right));
    y->height = 1 + max(height(y->right) , height(y->left));

    return x;
}

Node* leftRotate(Node* y)
{
    Node* x = y->right;
    Node* t= x->left;

    x->left = y;
    y->right = t;

    x->height = 1 + max(height(x->left) , height(x->right));
    y->height = 1 + max(height(y->right) , height(y->left));

    return x;
}

int balanceFactor(Node* n)
{
    if(n == nullptr)
    {
        return 0;
    }
    return height(n->left) - height(n->right);
}

Node* insert(Node* root , int k)
{
    if(root == nullptr)
    {
        return new Node(k);
    }
    if(k < root->data)
    {
        root->left = insert(root->left , k);
    }
    else if(k > root->data)
    {
        root->right = insert(root->right , k);
    }
    else
    {
        return root;
    }

    root->height = 1 + max(height(root->left) , height(root->right));
    int balance = balanceFactor(root);

    if (balance > 1 && k < root->left->data)
    {
        return rightRotate(root);
    }
    if (balance < -1 && k > root->right->data)
    {
        return leftRotate(root);
    }
    if(balance > 1 && k > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(balance < -1 && k < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    
    return root;
}

void inorder(Node* root)
{
    if(root == nullptr)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    Node* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;
    return 0;
}