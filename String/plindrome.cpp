#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<stack>
#include<queue>
using namespace std;
class Solution {
    public:
        string lower(string s)
        {
            string l;
            int j = 0;
            for(int i = 0 ; i < s.length() ; i++)
            {
                if((s[i]>='A' && s[i]<='Z'))
                {
                    l[j++] = s[i] - 'A' + 'a';
                }
                else
                {
                    continue;
                }
            }
            return l;
        }
    
    public:
        bool isPalindrome(string s) {
            string l = lower(s);
            cout<<l;
            int i = 0;
            int j = l.length() - 1;
            while(i<=j)
            {
                if(l[i] == s[i])
                {
                    continue;
                }
                else
                {
                    return false;
                }
            }
            return true;
        }
    };

int main(){
    Solution* obj = new Solution();
    string s = "race a car";
    bool p = obj->isPalindrome(s);
    cout<<p;
    return 0;
}