#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<stack>
#include<queue>
using namespace std;

string convertPre2Post(string s)
{
    stack<string> st;
    for (int i = s.length() - 1; i >= 0; i--)
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
            temp = s1 + s2 + s[i];
            st.push(temp);
        }
    }
    return st.top();
}

int main(){
    string s = "*-A/BC-/AKL";
    cout<<"Postfix : "<<convertPre2Post(s)<<endl;
    return 0;
}