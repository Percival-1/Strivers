#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<stack>
#include<queue>
using namespace std;

string concertPost2In(string s)
{
    stack<string> st;
    for (int i = 0; i < s.length(); i++)
    {
        string s1;
        string s2;
        string temp;

        if ((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))
        {
            st.push(string(1,s[i]));
        }
        else
        {
            s1 = st.top();
            st.pop();
            s2=st.top();
            st.pop();
            temp = '(' + s2 + s[i] + s1 + ')';
            st.push(temp);
        }
    }
    return st.top();
}

int main(){
    string postfix = "AB-DE+F*/";
    cout<<"Infix : "<<concertPost2In(postfix)<<endl;
    return 0;
}