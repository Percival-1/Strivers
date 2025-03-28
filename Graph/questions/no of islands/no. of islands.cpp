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
    void bfs(int row , int col , vector<vector<char>>& grid , vector<vector<int>>& vis)
    {
        vis[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row , col});
        int n = grid.size();
        int m = grid[0].size();


        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int crow = -1; crow <= 1; crow++)
            {
                for (int ccol = -1; ccol <= 1; ccol++)
                {
                    if(crow == 1 && ccol == 0 || crow == -1 && ccol == 0 || crow == 0 && ccol == 1 || crow == 0 && ccol == -1)
                    {
                        int nrow = row + crow;
                        int ncol = col + ccol;
                        if (nrow>= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == '1')
                        {
                            q.push({nrow , ncol});
                            vis[nrow][ncol] = 1;
                        }
                    }
                }
            }
        }
    }


    public:
        int numIslands(vector<vector<char>>& grid) {
            int n = grid.size();
            int m = grid[0].size();
            vector<vector<int>> vis(n , vector<int> (m,0));
            int count = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if(!vis[i][j] && grid[i][j] == '1')
                    {
                        count++;
                        bfs(i , j , grid , vis);
                    }
                }
            }
            return count;
        }
    };

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    return 0;
}