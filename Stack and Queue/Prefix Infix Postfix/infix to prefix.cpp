#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<stack>
#include<queue>
using namespace std;

int precedence(char ch)
{
    if(ch =='^')
    {
        return 3;
    }
    else if(ch == '*' || ch == '/')
    {
        return 2;
    }
    else if( ch == '+' || ch == '-')
    {
        return 1;
    }
    else 
    {
        return -1;
    }
}

string convert2Postfix(string s)
{
    stack<char> st;
    string ans;

    for (int i = 0; i < s.length(); i++)
    {
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
        {
            ans = ans + s[i];
        }
        else if(s[i] == '(')
        {
            st.push(s[i]);
        }
        else if(s[i] == ')')
        {
            while (st.top() != '(')
            {
                ans = ans + st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            if(!st.empty() && precedence(s[i]) < precedence(st.top()))
            {
                ans = ans + st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        ans = ans + st.top();
        st.pop();
    }
    return ans;
}

void convert2Prefix(string s)
{
    reverse(s.begin() , s.end());

    for (int i = 0; i < s.length(); i++)
    {
        if(s[i] == '(')
        {
            s[i] = ')';
        }
        else if(s[i] == ')')
        {
            s[i] = '(';
        }
    }
    string prefix = convert2Postfix(s);
    reverse(prefix.begin() , prefix.end());
    cout<<"Prefix : "<<prefix<<endl;
}

int main(){
    string s = "F+D-c*(B+A)";
    convert2Prefix(s);
    return 0;
}