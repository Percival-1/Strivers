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
    int count = 0;
    Node* mover = head;
    while(mover != NULL)
    {
        count++;
        mover = mover->next;
    }
    cout<<"Length : "<<count<<endl;
}

Node* deleteHead(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node* mover = head;
    head = head->next;
    head->back= nullptr;
    mover->next = nullptr;
    delete mover;
    return head;
}

Node* deleteTail(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node* mover = head;
    while(mover->next != NULL)
    {
        mover = mover->next;
    }
    Node* temp = mover->back;
    temp->next = nullptr;
    mover->back=nullptr;
    delete mover;
    return head;
    // while(mover->next->next != NULL)
    // {
    //     mover = mover->next;
    // }
    // Node*temp = mover->next;
    // mover->next=nullptr;
    // delete temp;
    // return head;
}

Node* deletePos(Node* head , int k)
{
    if(head == NULL )
    {
        return NULL;
    }
    int count = 0;
    Node* mover = head;
    while(mover != NULL)
    {
        count++ ;
        if(count == k)
        {
            break;
        }
        mover = mover->next;
    }
    Node* pre = mover->back;
    Node* forw = mover->next;
    if(pre == NULL && forw == NULL)
    {
        return NULL;
    }
    else if(pre == NULL)
    {
        head = deleteHead(head);
        return head;
    }
    else if(forw == NULL)
    {
        head = deleteTail(head);
        return head;
    }

    pre->next = forw;
    forw->back = pre;
    mover->next = nullptr;
    mover->back = nullptr;
    delete mover;
    return head;
}

void deleteNode(Node* temp)
{
    Node* pre = temp->back;
    Node* forw =temp->next;
    if(forw == NULL)
    {
         pre->next = nullptr;
         temp->back = nullptr;
         delete temp;
         return;
    }
    pre->next = forw;
    forw->back = pre;
    
    temp->next = temp->back = nullptr;
    delete temp;
}

Node* insertHead(Node* head , int val)
{
    Node* ele = new Node(val , head , nullptr);
    head->back = ele;
    return ele;
}

Node* insertTail(Node* head , int val)
{
    if(head == NULL)
    {
        return new Node(val , nullptr , nullptr);
    }
    Node* mover = head;
    while(mover->next != NULL)
    {
        mover= mover->next;
    }
    Node* pre = mover->back;
    Node* ele = new Node(val , mover , pre);
    pre->next = ele;
    mover->back = ele;
    return head;
}
Node* insertBeforeKthNode(Node* head , int val , int pos)
{
    if(pos == 1)
    {
        return insertHead(head , val);
    }
    Node* mover = head;
    int count = 0;
    while (mover != NULL)
    {
        count++;
        if (count == pos)
        {
            break;
        }
        mover = mover->next;
    }
    Node* pre = mover->back;
    Node * ele = new Node(val , mover , pre);
    mover->back = ele;
    pre->next = ele;
    return head;
}

void insertBeforNode(Node* node , int val)
{
    Node* pre = node->back;
    Node* ele = new Node(val , node , pre);
    pre->next = ele;
    node->back = ele;
}

int main(){
    vector<int> arr = { 2,4,6,8};
    Node* head = convert2DLL(arr);
    // head = deleteHead(head);
    // head = deleteTail(head);
    // head = deletePos(head,4);
    // deleteNode(head->next);
    // head = insertHead(head,99);
    // head = insertTail(head , 35);
    // head = insertBeforeKthNode(head , 34 , 5);

    print(head);
    length(head);
    return 0;
}
