#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<stack>
#include<queue>
using namespace std;

bool bfs(vector<vector<int>>& adj , vector<int>& vis , int node)
{
    vis[node] = 0;
    queue<int> q;
    q.push(node);
    while(!q.empty())
    {
        int a = q.front();
        q.pop();
        for (auto &&i : adj[a])
        {
            if (vis[i] == -1)
            {
                q.push(i);
                vis[i] = !vis[a];
            }
            else if(vis[i] == vis[a])
            {
                return false;
            }
        }
    }
    return true;
}

void bipartite(vector<vector<int>>& arr , int v)
{
    vector<int> vis(v+1 , -1);
    for (int i = 1; i < v + 1; i++)
    {
        if(vis[i] == -1 && bfs(arr , vis , i) == true)
        {
            cout<<"the graph is bipartite"<<endl;
            return;
        }
    }
    cout<<"the graph is not bipartite"<<endl;
}

void adj(vector<vector<int>>& arr , int i , int j)
{
    arr[i].push_back(j);
    arr[j].push_back(i);
}

void print(vector<vector<int>>& arr)
{
    for (int i = 1; i <  arr.size(); i++)
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

    int v = 8;
    vector<vector<int>> arr(v+1);
    adj(arr , 1 , 2);
    adj(arr , 2 , 3);
    adj(arr , 2 , 6);
    adj(arr , 3 , 4);
    adj(arr , 4 , 5);
    adj(arr , 4 , 7);
    adj(arr , 5 , 6);
    adj(arr , 7 , 8);

    print(arr);

    bipartite(arr , v);

    return 0;
}