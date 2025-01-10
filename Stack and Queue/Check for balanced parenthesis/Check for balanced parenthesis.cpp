#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<stack>
using namespace std;

bool check(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else
        {
            if(st.empty())
            {
                return false;
            }
            char ch = st.top();
            st.pop();
            if ((s[i] == ')' && ch == '(') || (s[i] == ']' && ch == '[') || (s[i] == '}' && ch == '{'))
            {
                continue;
            }
            else
            {
                return false;
            }
        }
    }
    return st.empty();
}

int main(){
    string s;
    cout<<"Enter a string with open and close brackets"<<endl;
    cin>>s;
    if(check(s))
    {
        cout<<"balanced parenthesis"<<endl;
    }
    else
    {
        cout<<"unabalanced parenthesis"<<endl;
    }
    return 0;
}