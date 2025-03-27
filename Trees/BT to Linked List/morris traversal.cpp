#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<stack>
#include<queue>
using namespace std;

class Node
{
public:
    int data;
    Node *right;
    Node *left;

public:
    Node() : data(0), right(nullptr), left(nullptr) {}
    Node(int val) : data(val), right(nullptr), left(nullptr) {}
    Node(int val, Node *right1, Node *left1) : data(val), right(right1), left(left1) {}
};

void BinaryToLinked(Node* root)
{
    Node* cur = root;
    while(cur!=NULL)
    {
        if(cur->left != NULL)
        {
            Node* prev = cur->left;
            while(prev->right!= NULL)
            {
                prev = prev->right;
            }
            prev->right = cur->right;
            cur->right = cur->left;
            cur->left = nullptr;
        }
        cur = cur->right;
    }
}

void print(Node* root)
{
    Node* mover = root;
    while (mover != NULL)
    {
        cout<<mover->data<<" ";
        mover= mover->right;
    }
    cout<<endl;
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

    BinaryToLinked(node);

    print(node);
    return 0;
}