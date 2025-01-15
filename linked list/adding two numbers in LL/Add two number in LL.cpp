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
        next= nullptr;
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
            head = ele;
            return;
        }
        while (mover->next != NULL)
        {
            mover = mover->next;
        }
        Node* ele = new Node(n);
        mover->next = ele;
        ele->back = mover;
    }
};

Node* add(Node* head1 , Node* head2)
{
    Node* t1 = head1;
    Node* t2 = head2;
    Linked* dum = new Linked();
    int carry = 0;
    while((t1 != NULL) || (t2 != NULL))
    {
        int sum = carry;
        if (t1)
        {
            sum = sum + t1->data;
            t1 = t1->next;
        }
        if (t2)
        {
            sum = sum + t2->data;
            t2 = t2->next;
        }
        dum->push(sum%10);
        carry = sum / 10;
    }
    if(carry != 0)
    {
        dum->push(carry);
    }
    return dum->head;
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
    Linked* num1 = new Linked();
    Linked* num2 = new Linked();
    num1->push(3);
    num1->push(5);
    num2->push(4);
    num2->push(5);
    num2->push(9);
    num2->push(9);
    Node * head = add(num1->head , num2->head);
    print(head);
    return 0;
}