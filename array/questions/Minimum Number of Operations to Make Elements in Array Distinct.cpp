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
        int minimumOperations(vector<int>& nums) {
            int count = 0;
            int temp;
            
            while(1)
            {
                unordered_map<int , int> mp;
                temp = 0;
                for (auto &&i : nums)
                {
                    if(++(mp[i]) > 1)
                    {
                        temp++;
                    }
                }
                if(temp == 0)
                {
                    break;
                }
                nums.erase(nums.begin() , nums.begin() + min(3 , (int)nums.size()));
                count++;
            }
            return count;
        }
    };

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    return 0;
}