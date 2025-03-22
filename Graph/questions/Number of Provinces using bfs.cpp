#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<stack>
#include<queue>
using namespace std;

int bfsG(vector<vector<int>> & adj)
{
    int n = adj.size();
    vector<int> vis(n , 0);
    int count = 0;
    
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            queue<int> q;
            q.push(i);
            vis[i] = 1;

            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                for (int j = 0; j < n; j++)
                {
                    if (adj[node][j] == 1 && !vis[j] && node!=j)
                    {
                        q.push(j);
                        vis[j] = 1;
                    }
                }
            }
            count++;
        }
    }
    return 0;

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    return 0;
}