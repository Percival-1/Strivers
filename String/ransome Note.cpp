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
        bool canConstruct(string s, string m) {
            unordered_map<char , int> mp;
            if(s.length() > m.length())
            {
                return false;
            }
            for (int i = 0; i < m.length(); i++)
            {
                if (i>=0 && i<s.length())
                {
                    mp[s[i]]--;
                }
                mp[m[i]]++;
            }
            for (auto &&i : mp)
            {
                if(i.second <= 0)
                {
                    return false;
                }
            }
            return true;
        }
    };

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    return 0;
}