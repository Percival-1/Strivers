#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<stack>
#include<queue>
using namespace std;

void dfs(int node , vector<vector<int>> adj , vector<int> &vis)
{
    vis[node] = 1;
    for (auto &&i : adj[node])
    {
        if (!vis[i])
        {
            dfs(i , adj , vis);
        }
    }
}

int dfsG(vector<vector<int>> adj)
{
    vector<vector<int>> adjls(adj.size());
    for (int i = 0; i < adj.size(); i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            if (adj[i][j] == 1 && i!=j)
            {
                adjls[i].push_back(j);
                adjls[j].push_back(i);
            }
        }
    }
    vector<int> vis(adjls.size() , 0);
    int count = 0;
    for (int i = 0; i < adjls.size() ; i++)
    {
        if(!vis[i])
        {
            count++;
            dfs(i , adjls , vis);
        }
    }
    return count;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    return 0;
}