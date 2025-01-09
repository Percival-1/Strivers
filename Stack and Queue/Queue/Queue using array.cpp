#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Q{
    public:
    int start = -1;
    int end = -1;
    int size = 4;
    int curSize = 0;
    int q[4];

    public:
    void push(int n)
    {
        if (curSize == size)
        {
            return ;
        }
        if (curSize == 0)
        {
            start = 0;
            end = 0;
        }
        else
        {
            end = (end + 1)%size;
        }
        curSize ++;
        q[end] = n;
    }
    int pop()
    {
        if (curSize == 0)
        {
            return -1;
        }

        int ele = q[start];

        if (curSize == 1)
        {
            start = end = -1;
        }
        else
        {
            start = (start + 1)%size;
        }
        curSize--;
        return ele;
    }

    public:
    int top()
    {
        if (curSize == 0)
        {
            return -1;
        }
        return q[start];
    }

    public:
    int size1()
    {
        return curSize;
    }
};

int main(){
    Q* obj = new Q();
    obj->push(4);
    obj->push(5);
    obj->push(6);
    obj->push(7);
    int x = obj->pop();
    for (int i = 0; i < obj->size1(); i++)
    {
        cout<<obj->q[(obj->start + i)%obj->size]<<" ";
    }
    cout<<endl;
    cout<<x<<endl;
    return 0;
}