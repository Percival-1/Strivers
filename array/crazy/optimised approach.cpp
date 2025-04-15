#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;

class Solution
{
private:
    void solve(vector<int> nums , int j , vector<vector<int>> &ans)
    {
        if(j >= nums.size())
        {
            return;
        }

        int n = ans.size();
        for (int i = 0; i < n; i++)
        {
            vector<int> temp = ans[i];
            temp.push_back(nums[j]);
            ans.push_back(temp);
        }
        solve(nums , j + 1 , ans);
    }
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        ans.push_back({});
        solve(nums , 0 , ans);
        return ans;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    return 0;
}