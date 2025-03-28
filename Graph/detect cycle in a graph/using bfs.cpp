#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<stack>
#include<queue>
using namespace std;

void cycle(vector<vector<int>>& adj , int v)
{
    vector<int> vis(v+1 , 0);
    vis[1] = 1;
    queue<pair<int , int>>q;
    q.push({1 , -1});
    while(!q.empty())
    {
        int a = q.front().first;
        int  b = q.front().second;
        q.pop();
        for (auto &&i : adj[a])
        {
            if (!vis[i])
            {
                q.push({i , a});
                vis[i] = 1;
            }
            else if(vis[i] && i != b)
            {
                cout<<"cycle exist"<<endl;
                return;
            }
        }
    }
    cout<<"cycle does not exist"<<endl;
}

void adj(vector<vector<int>>& arr , int i , int j)
{
    arr[i].push_back(j);
    arr[j].push_back(i);
}

void print(vector<vector<int>> arr)
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

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int v = 7;
    vector<vector<int>> arr(v+1);
    adj(arr , 1 , 2);
    adj(arr , 1 , 3);
    adj(arr , 2 , 5);
    adj(arr , 5 , 7);
    adj(arr , 3 , 6);
    adj(arr , 3 , 4);
    adj(arr , 6 , 7);
    print(arr);
    cycle(arr , v);
    return 0;
}