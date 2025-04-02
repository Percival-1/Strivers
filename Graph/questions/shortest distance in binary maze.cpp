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
        int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

            int n = grid.size();;
            int m = grid[0].size();

            if (grid.empty() || grid[0].empty() || grid[0][0] != 0 || grid[n - 1][m - 1] != 0)
            {
                return -1;
            }
            
            queue<pair<int , pair<int , int>>> q;
            vector<vector<int>> arr(n , vector<int>(m , INT_MAX));
            arr[0][0] = 1;
            q.push({1 , {0 , 0}});
            vector<pair<int , int>> direction = {{-1 , -1} , {-1 , 0} , {0 , -1} , {-1 , 1} , {1 , -1} , {1 , 1} , {0 , 1} , {1 , 0}};
            while (!q.empty())
            {
                pair<int , pair<int , int>> p = q.front();
                q.pop();
                int a = p.second.first;
                int b = p.second.second;
                int distance = p.first;

                if(a == n - 1 && b == m - 1)
                {
                    return arr[n - 1][n - 1];
                }
                for (auto &&i : direction)
                {
                    int row = a + i.first;
                    int col = b + i.second;

                    if (row >= 0 && row < n && col >= 0 && col < m && grid[row][col] == 0 && (distance + 1) < arr[row][col])
                    {
                        q.push({distance + 1 , {row , col}});
                        arr[row][col] = distance + 1;
                    }
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