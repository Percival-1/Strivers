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
        int firstUniqChar(string s) {
            unordered_map<char , int> mp;
            for (int i = 0; i < s.length(); i++)
            {
                mp[s[i]]++;
            }
            for (int i = 0; i < s.length(); i++)
            {
                if(mp[s[i]] == 1)
                {
                    return i;
                }
            }
            return -1;
        }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    return 0;
}