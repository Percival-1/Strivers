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
        string reverseVowels(string s) {
            vector<int> arr;
            for (int i = 0; i < s.length(); i++)
            {
                if(s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' || s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' || s[i] == 'u' || s[i] == 'U')
                {
                    arr.push_back(i);
                }
            }
            int j = arr.size() - 1;
            for (int i = 0; i < arr.size(); i++)
            {
                swap(s[arr[i]] , s[arr[j]]);
                j--;
            }
            return s;
        }
    };

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    return 0;
}