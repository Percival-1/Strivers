#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<stack>
#include<queue>
using namespace std;

string convertpost2pre(string s)
{
    stack<string> st;

    for (int i = 0; i < s.length(); i++)
    {
        string temp;
        string s1;
        string s2;
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
        {
            st.push(string(1,s[i]));
        }
        else
        {
            s1 = st.top();
            st.pop();
            s2 = st.top();
            st.pop();
            temp = s[i] + s2 + s1;
            st.push(temp);
        }
    }
    return st.top();
}

int main(){
    string s = "ABC/-AK/L-*";
    cout<<"prefix : "<<convertpost2pre(s)<<endl;
    return 0;
}