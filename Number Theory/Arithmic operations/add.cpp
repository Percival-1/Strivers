#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<stack>
#include<queue>
using namespace std;

string convertDecimal2Binary(int n)
{
    
}

string trim(string &s1)
{
    long long in = s1.find('1');
    return s1.substr(in);
}

string add(string &s1 , string &s2)
{
    s1 = trim(s1);
    s2 = trim(s2);

    long long n1 = s1.length();
    long long n2 = s2.length();

    if (n2>n1)
    {
        return add(s2 , s1);
    }
    
    long long j = n2 - 1;
    int carry = 0;
    
    for (long long i = n1-1; i >= 0; i--)
    {
        long long bit1 = s1[i] - '0';
        long long sum = bit1 + carry;

        if (j>=0)
        {
            long long bit2 = s2[j] - '0';
            sum = sum + bit2;
            j--;
        }
        
        carry = sum/2;
        sum = sum%2;

        s1[i] = (char)(sum + '0');
    }

    if (carry > 0)
    {
        s1 = '1' + s1;
    }
    
    return s1;
}

int main(){
    string s1 = "0110101";
    string s2 = "001101";
    string s = add(s1 , s2);
    cout<<s<<endl;

    return 0;
}