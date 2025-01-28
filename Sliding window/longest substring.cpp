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
    int lengthOfLongestSubstring(string s) {
        vector<int> map(126 , -1);
        int l = 0 , r = 0 , maxLen = 0;
        while (r < s.length())
        {
                if (map[s[r]] >= l)
                {
                    l = map[s[r]] + 1;
                }
            maxLen = max(maxLen , r-l+1);
            map[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};

int main(){
    
    return 0;
}