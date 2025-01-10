#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<stack>
using namespace std;

int precedence(char ch)
{
    if(ch == '^')
    {
        return 3;
    }
    else if(ch == '*' || ch == '/')
    {
        return 2;
    }
    else if(ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void convert(string s)
{
    int i = 0;
    stack<char> st;
    string ans;

    for (int i = 0; i < s.length(); i++)
    {
        if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))
        {
            ans = ans + s[i];
        }
        else if(s[i] == '(')
        {
            st.push(s[i]);
        }
        else if(s[i] == ')')
        {
            while(st.top() != '(')
            {
                ans = ans + st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while(!st.empty() && precedence(s[i]) <= precedence(st.top()))
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
    cout<<"Postfix : "<<ans<<endl;
}

int main(){
    string s = "a*b(a+b(c/d)a^g)";
    convert(s);
    return 0;
}