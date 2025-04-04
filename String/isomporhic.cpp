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
        bool isIsomorphic(string s, string t) 
        {
            unordered_map<char , char> mp;
            unordered_map<char , char> mp2;
            for (int i = 0; i < s.length(); i++)
            {
                if(mp.find(s[i]) == mp.end() && mp2.find(t[i]) == mp2.end())
                {
                    mp[s[i]] = t[i];
                    mp2[t[i]] = s[i];
                }
                else if((mp[s[i]] != t[i]) || (mp2[t[i]] != s[i]))
                {
                    return false;
                }
            }
            return true;
        }
};

int main(){
    
    return 0;
}