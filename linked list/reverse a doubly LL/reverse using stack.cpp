#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<stack>
#include<queue>
using namespace std;

// we are pushing two times not effecient solution

class Node{

    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* push(int n , Node* head)
{
    Node* mover = head;
    if(mover == nullptr)
    {
        Node* ele = new Node(n);
        return ele;
    }
    while (mover->next != nullptr)
    {
        mover = mover->next;
    }
    Node* ele = new Node(n);
    mover->next = ele;
    ele->back = mover;
    return head;
}

Node* reverse(Node* head)
{
    stack<int> st;
    Node* mover = head;
    while(mover != nullptr)
    {
        st.push(mover->data);
        mover = mover->next;
    }

    Node* temp = head;
    while(temp != nullptr)
    {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}

void print(Node* head)
{
    Node* mover = head;
    while (mover != NULL)
    {
        cout<<mover->data<<" ";
        mover = mover->next;
    }
    cout<<endl;
}

int main(){
    
    Node* head  = nullptr;
    head = push(2,head);
    head = push(3,head);
    head = push(4,head);
    head = push(5,head);

    cout<<"Before"<<endl;
    print(head);

    cout<<"After"<<endl;
    head = reverse(head);
    print(head);
    return 0;
}