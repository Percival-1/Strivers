#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    public:
    Node(int data1 , Node* next1)
    {
        data = data1;
        next = next1;
    }

    public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node* convertArr(vector<int> &arr)
{
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node* temp = new Node(arr[i]);
        mover->next=temp;
        mover = mover->next; // mover = temp;     same thing
    }
    return head;
}

int lengthOfLL(Node* head)
{
    Node* mover = head;
    int count = 0;
    while(mover)
    {
        count++;
        mover = mover->next;
    }
    return count;
}

int check(Node* head , int val)
{
    Node* mover = head;
    while(mover)
    {
        if (mover->data == val)
        {
            return 1;
        }
        mover = mover->next;
    }
    return 0;
}

Node* removeHead(Node* head)
{
    if(head == NULL)
    {
        return head;
    }
    Node* mover = head;
    head = mover->next;
    delete mover;
    return head;
}

Node* removeTail(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node* mover = head;
    while(mover->next->next != nullptr)
    {
        mover = mover->next;
    }
    delete mover->next;
    mover->next = nullptr;
    return head;
}

Node* removeElements(Node* head , int k)
{
    if(head == NULL)
    {
        return head;
    }
    if(k == 1)
    {
        Node* mover = head;
        head = mover->next;
        delete mover;
        return head;
    }
    int count = 0;
    Node* mover = head;
    Node* prev = NULL;
    while(mover != NULL)
    {
        count++;
        if(count == k)
        {
            prev->next = prev->next->next;
            delete mover;
            break;
        }
        prev = mover;
        mover = mover->next;
    }
    return head;
    // Node* mover = head;
    // Node* back = nullptr;
    // for (int i = 1; i < k-1; i++)
    // {
    //     mover = mover->next;
    //     cout<<"value of i :"<<i<<endl;
    // }
    // back = mover->next;
    // mover->next=mover->next->next;
    // delete back;
    // return head;
}

Node* insertHead(Node* head , int val)
{
    Node* store = new Node(val,head);
    return store;
}

Node* insertTail(Node* head , int val)
{
    if (head == NULL)
    {
        return new Node(val);
    }
    
    Node* mover = head;
    while(mover->next != nullptr)
    {
        mover = mover->next;
    }
    Node* temp = new Node(val);
    mover->next = temp;
    return head;
}

Node* insertPosition(Node* head, int val , int pos)
{
    if(head == NULL)
    {
        if(pos==1)
        {
            return new Node(val);
        }
        else
        {
            return head;
        }
    }
    if(pos == 1)
    {
        return new Node(val , head);
    }
    int count = 0;
    Node* mover = head;
    while(mover != NULL)
    {
        count++;
        if(count == pos-1)
        {
            Node* ele = new Node(val);
            ele->next = mover->next;
            mover->next=ele;
            break;
        }
        mover = mover->next;
    }
    return head;
}

Node* insertByValue(Node* head , int val , int posVal)
{
    if(head == NULL)
    {
        return NULL;
    }
    if(head->data == posVal)
    {
        return new Node(val , head);
    }
    Node* mover = head;
    while(mover != NULL)
    {
        if(mover->next->data ==  posVal)
        {
            Node* ele = new Node(val);
            ele->next = mover->next;
            mover->next=ele;
            break;
        }
        mover = mover->next;
    }
    return head;
}

int main(){
    vector<int> arr = {2,5,8,7};
    Node* head = convertArr(arr);
    // cout<<head->data<<endl;
    // head = removeHead(head);
    // head = removeTail(head);
    // head = removeElements(head , 2);
    head = insertHead(head,9);
    head = insertTail(head,10);
    head = insertPosition(head,11,7);
    head = insertByValue(head , 12 , 11);

    Node* mover = head;
    int length = lengthOfLL(head);
    for (int i = 0; i < length; i++)
    {
        cout<<mover->data<<" ";
        mover = mover->next;
    }


    cout<<endl;
    cout<<"length is : "<<length<<endl;

    // cout<<"element exist : "<<check(head,8)<<endl;

    // Node* y = new Node(arr[0] , nullptr);
    // cout<<y->data<<endl;
    return 0;
}
