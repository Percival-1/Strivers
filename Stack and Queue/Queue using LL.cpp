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

    public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

class Q{
    public:
    Node* end;
    Node* start;

    public:
    Q()
    {
        start = end = nullptr;
    }

    public:
    bool isEmpty()
    {
        if(start == nullptr)
        {
            return true;
        }
        return false;
    }

    public:
    void push(int n)
    {
        if(isEmpty())
        {
            Node* ele = new Node(n);
            start = end = ele;
            return;
        }
        Node* ele = new Node(n);
        end->next = ele;
        end = ele;
    }

    public:
    void pop()
    {
        if(isEmpty())
        {
            return;
        }
        Node* temp = start;
        start = start->next;
        if (start == nullptr)
        {
            end = nullptr;
        }
        delete temp;
    }

    public:
    void peek()
    {
        if(isEmpty())
        {
            cout<<"Queue is empty"<<endl;
        }
        cout<<"Top element : "<<start->data<<endl;
    }

    public:
    void endPeek()
    {
        if(isEmpty())
        {
            cout<<"Queue is empty"<<endl;
        }
        cout<<"End element : "<<end->data<<endl;
    }
};

int main(){
    Q* st = new Q();
    st->push(4);
    st->push(5);
    st->push(6);
    st->push(7);
    st->push(8);
    st->push(9);
    st->pop();
    st->pop();
    st->pop();
    Node* mover = st->start;
    while (mover!=NULL)
    {
        cout<<mover->data<<" ";
        mover= mover->next;
    }
    cout<<endl;
    st->peek();
    st->endPeek();
    return 0;
}