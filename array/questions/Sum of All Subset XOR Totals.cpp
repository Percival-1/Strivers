#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

class Solution {
    public:
    void solve(vector<int> nums , int i , vector<int> &temp , vector<vector<int>> &ans)
    {
        if (i >= nums.size())
        {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(nums , i + 1 , temp , ans);
        temp.pop_back();
        solve(nums , i + 1 , temp , ans);
    }
    public:
        int subsetXORSum(vector<int>& nums) {
            vector<vector<int>> ans;
            vector<int> temp;
            solve(nums , 0 , temp , ans);
            int result = 0;
            for (auto &&i : ans)
            {
                int Xor = 0;
                for (auto &&j : i)
                {
                    Xor ^= j;
                }
                result += Xor;
            }
            return result;
        }
    };

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cout<<(1^1)<<endl;
    return 0;
}