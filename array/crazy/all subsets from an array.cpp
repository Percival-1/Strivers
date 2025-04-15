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
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> temp;
        vector<vector<int>> ans;
        solve(nums , 0 , temp , ans);
        return ans;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    return 0;
}