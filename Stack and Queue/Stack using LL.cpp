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

class Stack{
    public:
    Node* head;
    int size = 0;

    public:
    Stack()
    {
        head = nullptr;
    }

    bool isEmpty()
    {
        if(head == nullptr)
        {
            return false;
        }
        return true;
    }

    public:
    void push(int n)
    {
      Node* mover = new Node(n);
      mover->next = head;
      head = mover;
      size++;
    }

    public:
    void pop()
    {
        if(isEmpty())
        {
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    public:
    void peek()
    {
        if(isEmpty())
        {
            cout<<"Stack is empty"<<endl;
            return;
        }
        cout<<"Top element : "<<head->data<<endl;
    }

    public:
    void print(Node* head)
    {
        Node* mover = head;
        while (mover!=NULL)
        {
            cout<<mover->data<<" ";
            mover = mover->next;
        }
        cout<<endl;
    }
};

int main(){
    Stack* st = new Stack();
    st->push(4);
    st->push(5);
    st->push(6);
    st->push(7);
    st->push(8);
    st->pop();
    st->print(st->head);
    st->peek();
    return 0;
}