#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<stack>
#include<queue>
using namespace std;

bool dfs(vector<vector<int>>& arr , vector<int>& vis , int a , int b)
{
    vis[a] = 1;
    for (auto &&i : arr[a])
    {
        if(!vis[i] && dfs(arr , vis , i , a) == true)
        {
            return true;
        }
        else if(vis[i] && i != b)
        {
            return true;
        }
    }
    return false;
}

void cycle(vector<vector<int>>& arr , int v)
{
    vector<int> vis(v+1 , 0);
    for (int i = 1; i < v+1; i++)
    {
        if(dfs(arr , vis , 1 , -1) == true && !vis[i])
        {
            cout<<"cycle exists"<<endl;
            return;
        }
    }
    cout<<"cycle does not exixt"<<endl;
}

void adj(vector<vector<int>>& arr , int i , int j)
{
    arr[i].push_back(j);
    arr[j].push_back(i);
}

void print(vector<vector<int>> arr)
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