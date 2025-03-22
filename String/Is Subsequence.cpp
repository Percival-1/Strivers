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
        bool isSubsequence(string s, string t) {
            int j = 0;
            for (int i = 0; i < t.length(); i++)
            {
                if(s[j] == t[i] && (j<s.length()))
                {
                    j++;
                }
                if(j == s.length())
                {
                    return true;
                }
            }
            return false;
        }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    return 0;
}