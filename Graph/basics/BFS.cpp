#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<stack>
#include<queue>
using namespace std;

vector<bool> visited(vector<bool>& arr , int n , queue<int>& q)
{
    if(arr[n] == 0)
    {
        arr[n] = true;
        q.push(n);
    }
    return arr;
}

int main(){
    int u , v , n;
    cin>>n;
    vector<vector<int>> arr(n+1);
    for (int i = 0; i < n; i++)
    {
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    
    queue<int> q;

    vector<bool> vis(n+1 , false);

    int start = 1;
    vis[1] = 1;
    q.push(1);
    while(!q.empty())
    {
        for (int i = 0; i < arr[q.front()].size(); i++)
        {
            if (vis[arr[q.front()][i]] == 0)
            {
                vis[arr[q.front()][i]] = true;
                q.push(arr[q.front()][i]);
            }
        }
        q.pop();
    }
    
    for (int i = 1; i <= n; i++)
    {
        cout<<vis[i]<<" ";
    }
    cout<<endl;
    return 0;
}