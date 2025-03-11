#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<stack>
#include<queue>
#include<map>
using namespace std;

class Solution {
    public:
        bool isAnagram(string s, string t) {
            map<char , int> mp1;
            map<char , int> mp2;
            for (int i = 0; i < s.length(); i++)
            {
                mp1[s[i]]++;
                mp2[t[i]]++;
            }
            auto it1 = mp1.begin();
            auto it2 = mp2.begin();

            while((it1 != mp1.end()) && (it2 != mp2.end()))
            {
                if((it1->first != it2->first) || it1->second != it2->second)
                {
                    return false;
                }
                it1++;
                it2++;
            }
            return true;
        }
};


int main(){
    
    return 0;
}