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
            vector<int> arr(26);
            for (int i = 0; i < s.length(); i++)
            {
                arr[s[i]-'a'] ++;
            }

            for (int i = 0; i < s.length(); i++)
            {
                if(arr[s[i] - 'a'] == 1)
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