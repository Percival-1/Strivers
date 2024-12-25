#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Node{

    public:
    int data;
    Node* next;
    Node* back;

    public: 
    Node(int data1 , Node*  next1 , Node* back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }

    public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convert2DLL(vector<int>&arr)
{
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node* temp = new Node(arr[i], nullptr , prev);
        prev->next = temp;
        prev = prev->next;    // prev = temp;
    }
    return head;
}

void print(Node* head)
{
    Node* mover = head;
    while(mover != NULL)
    {
        cout<<mover->data<<" ";
        mover = mover->next;
    }
    cout<<endl;
}

void length(Node* head)
{
    
}


Node* deleteHead(Node* head)
{
    Node* mover = head;
    mover = mover->next;
    mover->back = nullptr;
    delete head;
    return mover;
}

int main(){
    vector<int> arr = { 2,4,6,8};
    Node* head = convert2DLL(arr);
    head = deleteHead(head);
    print(head);
    return 0;
}