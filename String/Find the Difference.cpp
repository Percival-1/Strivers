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
        char findTheDifference(string s, string t) {
            if (t. length() == s.length())
            {
                return '\0';
            }
            
            unordered_map<char , int> mp;
            for (int i = 0; i < t.length(); i++)
            {
                mp[t[i]]++;
                mp[s[i]]--;
            }
            for (auto &&i : mp)
            {
                if(i.second == 1)
                {
                    return i.first;
                }
            }
            return '\0';
        }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    return 0;
}