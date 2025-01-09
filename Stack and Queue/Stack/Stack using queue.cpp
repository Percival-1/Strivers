// Implement Stack using Queues by making push() operation costly:

#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<stack>
using namespace std;

class Stack{
    public:
    queue<int> q1,q2;

    public:
        void push(int n)
        {
            q2.push(n);

            while(!q1.empty())
            {
                q2.push(q1.front());
                q1.pop();
            }
            queue<int> q = q1;
            q1 = q2;
            q2 = q;
        }
        
        void pop()
        {
            if (q1.empty())
            {
                cout<<"Stack is empty"<<endl;
                return;
            }
            q1.pop();
        }

        void top()
        {
            if (q1.empty())
            {
                cout<<"Stack is empty"<<endl;
                return;
            }
            cout<<"Top element : "<<q1.front()<<endl;
        }

        void size()
        {
            cout<<"Size of the stack is : "<<q1.size()<<endl;
        }

        void print()
        {
            if(q1.empty())
            {
                cout<<"Stack is empty"<<endl;
                return;
            }
            queue<int> temp = q1;
            while(!temp.empty())
            {
                cout<<temp.front()<<" ";
                temp.pop();
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
    st->top();
    st->print();

    return 0;
}