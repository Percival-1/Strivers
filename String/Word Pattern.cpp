#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<stack>
#include<queue>
using namespace std;
//abba --> dog cat cat dog
class Solution {
    public:
        bool wordPattern(string pattern, string s) {
            unordered_map<char , string> mp1;
            unordered_map<string , char> mp2;
            vector<string> st;
            string word = "";

            for (int i = 0; i < s.length(); i++)
            {
               if ((s[i] )== ' ')
               {
                   if(!word.empty())
                   {
                       st.push_back(word);
                       word = "";
                   }
               }
               else
               {
                    word += s[i];
               }
            }

            if(!word.empty())
            {
                st.push_back(word);
            }
            
            for (int i = 0; i < st.size(); i++)
            {
                cout<<st[i]<<' ';
            }
            

            if(st.size() != pattern.length())
            {
               return false;
            }
            for (int i = 0; i < st.size(); i++)
            {
                if ((mp1.find(pattern[i]) == mp1.end()) && (mp2.find(st[i]) == mp2.end()))
                {
                    mp1[pattern[i]] = st[i];
                    mp2[st[i]] = pattern[i];
                }
                else if(mp1[pattern[i]] != st[i] && mp2[st[i]] != pattern[i])
                {
                    return false;
                }
            }
            return true;
        }
};

int main(){
    Solution* obj = new Solution();
    bool x = obj->wordPattern("abba" , "dog cat cat dog");
    cout<<x;
    return 0;
}