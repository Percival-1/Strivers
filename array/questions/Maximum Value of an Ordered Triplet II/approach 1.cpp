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
            vector<int> arr1(nums.size() , 0);
            vector<int> arr2(nums.size() , 0);
            long long maxi = INT_MIN;
            for (int i = 1; i < nums.size(); i++)
            {
                maxi = max(arr1[i-1] , nums[i-1]);
                arr1[i] = maxi;
            }
            maxi = INT_MIN;
            for (int i = nums.size() - 2; i >= 0; i--)
            {
                maxi = max(arr2[i + 1] , nums[i + 1]);
                arr2[i] = maxi;
            }
            maxi = INT_MIN;
            for (int i = 0; i < nums.size(); i++)
            {
                maxi = max(maxi , (long long)(arr1[i] - nums[i])*arr2[i]);
            }
            return maxi;
        }
    };

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    return 0;
}