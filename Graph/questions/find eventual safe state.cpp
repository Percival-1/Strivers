#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<stack>
#include<queue>
using namespace std;

bool dfs(vector<vector<int>> &arr , vector<int> &vis , vector<int> &path , int node)
{
    vis[node] = 1;
    path[node] = 1;
    for (auto &&i : arr[node])
    {
        if (!vis[i])
        {
            if (dfs(arr , vis , path , i))
            {
                return true;
            }
        }
        else if(path[i])
        {
            return true;
        }
    }
    path[node] = 0;
    return false;
}

vector<int> check(vector<vector<int>> &arr , int v)
{
    vector<int> vis(v , 0);
    vector<int> path(v , 0);
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            if(dfs(arr , vis , path , i))
            {
                continue;
            }
        }
    }
    vector<int> ans;
    for (int i = 0; i < v; i++)
    {
        if(path[i] == 0)
        {
            ans.push_back(i);
        }
    }
    return ans;
}

void adj(vector<vector<int>> &arr , int i , int j)
{
    arr[i].push_back(j);
}

void print(vector<vector<int>> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<i<<" : ";
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    return 0;
}