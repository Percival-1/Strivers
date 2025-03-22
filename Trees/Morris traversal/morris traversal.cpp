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

vector<int> inorder(Node* root)
{
    vector<int> in;
    Node* cur = root;
    while (cur != NULL)
    {
        if (cur->left == NULL)
        {
            in.push_back(cur->data);
            cur = cur->right;
        }
        else
        {
            Node* pre = cur->left;
            while (pre->right && pre->right != cur)
            {
                pre = pre->right;
            }
            if(pre->right == NULL)
            {
                pre->right = cur;
                cur = cur->left; 
            }
            else
            {
                pre->right = NULL;
                in.push_back(cur->data);
                cur = cur->right;
            }
        }
    }
    return in;
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
    vector<int> arr = inorder(node);
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}