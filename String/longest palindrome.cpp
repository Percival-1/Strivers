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
        int longestPalindrome(string s) {
            unordered_map<char , int> mp;
            for (int i = 0; i < s.length(); i++)
            {
                mp[s[i]]++;
            }
            int ans = 0;
            bool odd = false;
            for (auto &&i : mp)
            {
                if(i.second%2 == 0)
                {
                    ans += i.second;
                }
                else
                {
                    ans = i.second - 1 + ans;
                    odd = true;
                }
            }
            if (odd)
            {
                return ans+ 1;
            }
            return ans;
        }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    return 0;
}