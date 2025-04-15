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
        int minimumEffortPath(vector<vector<int>>& h) {
            int n = h.size();
            int m = h[0].size();
            priority_queue<pair<int , pair<int , int>> , vector<pair<int , pair<int , int>>> , greater<pair<int , pair<int , int>>>> q;
            vector<vector<int>> arr( n , vector<int>(m , INT_MAX));
            arr[0][0] = 0;
            q.push({0 , {0 , 0}});
            vector<pair<int , int>> dis = {{0 , 1} , {1 , 0} , {0 , -1} , {-1 , 0}};
            while (!q.empty())
            {
                pair<int ,pair<int , int>> p = q.top();
                q.pop();
                int dif = p.first;
                int a = p.second.first;
                int b = p.second.second;
                if(a == n-1 && b == m-1)
                {
                    return dif;
                }
                for (auto &&i : dis)
                {
                    int row = a + i.first;
                    int col = b + i.second;
                    if (row >= 0 && row < n && col >= 0 && col < m)
                    {
                        int newEffort = max(dif , abs(h[row][col] - h[a][b]));
                        if (newEffort < arr[row][col])
                        {
                            arr[row][col] = newEffort;
                            q.push({newEffort , {row , col}});
                        }
                    }
                }
            }
            return 0;
        }
    };

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    return 0;
}