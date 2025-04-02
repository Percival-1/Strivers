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
        long long maximumTripletValue(vector<int>& nums) {
            long long result = 0;
            long long maxDiff = 0;
            long long maxi = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                result = max(result , maxDiff*nums[i]);
                maxi = max(maxi , (long long)nums[i]);
                maxDiff = max(maxDiff , (long long)maxi - nums[i]);
            }
            return result;
        }
    };

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    return 0;
}