#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<stack>
using namespace std;

class Queue{

    stack<int> s1,s2;

    public:
        void push(int x)
        {
            s1.push(x);
        }

        void pop()
        {
            if(s1.empty() && s2.empty())
            {
                cout<<"Queue is empty"<<endl;
                return;
            }

            if(s2.empty())
            {
                while (!s1.empty())
                {
                    s2.push(s1.top());
                    s1.pop();   
                }
            }
            int x = s2.top();
            s2.pop();
            cout<<"poped element in the Queue is : "<<x<<endl;
        }

        void front()
        {
            if (s1.empty() && s2.empty())
            {
                cout<<"Queue is empty"<<endl;
                return;
            }
            
            if(s2.empty())
            {
                while(!s1.empty())
                {
                    s2.push(s1.top());
                    s1.pop();
                }
            }

            cout<<"front element is : "<<s2.top()<<endl;
        }

        void print()
        {
            stack<int> a,b;
            a=s1;
            b=s2;
            while(!b.empty())
            {
                cout<<b.top()<<" ";
                b.pop();
            }
            while (!a.empty())
            {
                cout<<a.top()<<" ";
                a.pop();
            }
            cout<<endl;
        }
};

int main(){
    Queue* q = new Queue();
    q->push(4);
    q->push(5);
    q->push(6);
    q->push(7);
    q->push(8);
    q->push(9);
    cout<<"before"<<endl;
    q->print();
    q->front();
    cout<<"after"<<endl;
    q->pop();
    q->pop();
    q->push(10);
    q->print();
    q->front();
    return 0;
}