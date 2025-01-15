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

class Linked{
    public:
    Node* head;

    Linked()
    {
        head = nullptr;
    }
    
    public:
    void push(int n)
    {
        Node* mover = head;
        if (mover == nullptr)
        {
            Node* ele = new Node(n);
            head = ele;;
            return ;
        }
        
        while (mover->next != NULL)
        {
            mover = mover->next;
        }
        Node* ele = new Node(n);
        mover->next = ele;
        ele->back = mover;
    }

    public:
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

    public:
    void reverse()
    {
        Node* mover = head;
        Node* last = nullptr;
        while(mover != NULL)
        {
            last = mover->back;
            mover->back = mover->next;
            mover->next = last;
            mover = mover->back;
        }
        head = last->back;
    }
};

int main(){
    Linked* n = new Linked();
    n->push(2);
    n->push(3);
    n->push(4);
    n->push(5);
    n->push(6);
    n->push(7);
    cout<<"Before"<<endl;
    n->print(n->head);
    n->reverse();
    cout<<"After"<<endl;
    n->print(n->head);
    return 0;
}