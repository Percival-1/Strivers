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
        right = nullptr;
        left = nullptr;
    }
};

int main(){
    Node* root = new Node(1);
    root->right = new Node(2);
    root->left = new Node(3);
    root->left->right = new Node(5);
    return 0;
}