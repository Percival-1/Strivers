#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<stack>
#include<queue>
using namespace std;

void ans(vector<vector<int>> &arr , int i , int j)
{
    arr[i].push_back(j);
    arr[j].push_back(i);
}

void display(vector<vector<int>> arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        cout<<i<<" : ";
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void dfs(int node , vector<vector<int>> adj , vector<int> &vis ,vector<int> &ls)
{
    vis[node] = 1;
    ls.push_back(node);
    for (auto &&i : adj[node])
    {
        if(!vis[i])
        {
            dfs(i , adj , vis , ls);
        }
    }
}

vector<int> dfsG(int v , vector<vector<int>> adj)
{
    vector<int> vis(v + 1,0);
    int start = 1;
    vector<int> ls;
    dfs( start , adj , vis , ls);
    return ls;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int v = 8;
    
    vector<vector<int>> arr(v+1);

    ans(arr , 1 , 2);
    ans(arr , 1 , 3);
    ans(arr , 2 , 5);
    ans(arr , 2 , 6);
    ans(arr , 3 , 4);
    ans(arr , 3 , 7);
    ans(arr , 4 , 8);
    ans(arr , 8 , 7);

    display(arr);
    vector<int> dfs = dfsG(v , arr);
    for (int i = 0; i < dfs.size(); i++)
    {
        cout<<dfs[i]<<" ";
    }
    

    return 0;
}