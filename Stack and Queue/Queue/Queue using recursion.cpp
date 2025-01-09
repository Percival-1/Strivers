#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<stack>
using namespace std;

class Queue{
    stack<int> s;

    public:
        void push(int n)
        {
            s.push(n);
        }

        int pop()
        {
            if(s.empty())
            {
                cout<<"Queue is empty"<<endl;
                return -1;
            }

            int x = s.top();
            s.pop();

            if(s.empty())
            {
                return x;
            }

            int front = pop();

            s.push(x);
            return front;
        }

        int front()
        {   
           if(s.empty())
            {
                cout<<"Queue is empty"<<endl;
                return -1;
            }

            int x = s.top();
            s.pop();

            if(s.empty())
            {
                s.push(x);
                return x;
            }

            int f = front();
            s.push(x);
            return f;
        }

        void print()
        {
            if(s.empty())
            {
                return;
            }

            int x = pop();
            cout<<x<<" ";
            print();
            push(x);
        }
};

int main(){
    Queue* q = new Queue();
    q->push(1);
    q->push(2);
    q->push(3);
    int x = q->pop();
    cout<<"front element : "<<q->front()<<endl;
    q->print();
    return 0;
}