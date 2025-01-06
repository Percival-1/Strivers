#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<unordered_map>
using namespace std;

class StImp{
    public:
    int top = -1;
    int st[10];

    public:
    void push(int n)
    {
        if(top >= 10)
        {
            return;
        }
        top = top + 1;
        st[top] = n;
    }

    public:
    void pop()
    {
        if (top == -1)
        {
            return;
        }
        top = top - 1;
    }

    public:
    int toop()
    {
        if(top == -1)
        {
            return -1 ;
        }
        return st[top];
    }

    public:
    int size()
    {
        return top+1;
    }
};

int main(){
    StImp*  obj = new StImp();
    obj->push(4);
    obj->push(5);
    obj->push(4);
    obj->pop();
    for (int i = 0; i < obj->size(); i++)
    {
        cout<<obj->st[i]<<" ";
    }
    cout<<endl;
    cout<<"Size of the stack is : "<<obj->size()<<endl;
    cout<<"top element of the stack : "<<obj->toop()<<endl;
    return 0;
}