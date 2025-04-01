#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<stack>
#include<queue>
using namespace std;

/*
    1-->2-->3-->4
        ^   |   |
        |   v   v
        8   7-->5-->6
       / ^
      v   \
      9-->10
*/

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
        else if(vis[i] && path[i])
        {
            return true;
        }
    }
    path[node] = 0;
    return false;
}

void cycle(vector<vector<int>> &arr , int v)
{
    vector<int> vis(v+1 , 0);
    vector<int> path(v+1 , 0);
    for (int i = 1; i < v+1; i++)
    {
        if(!vis[i])
        {
            if (dfs(arr , vis , path , i))
            {
                cout<<"cycle exist"<<endl;
                return;
            }
        }
    }
    cout<<"cycle does not exist"<<endl;
}

void adj(vector<vector<int>> &arr , int i , int j)
{
    arr[i].push_back(j);
}

void print(vector<vector<int>> &arr)
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
    
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int v = 10;
    vector<vector<int>> arr(v+1);
    adj(arr , 1 , 2);
    adj(arr , 2 , 3);
    adj(arr , 3 , 4);
    adj(arr , 7 , 5);
    adj(arr , 5 , 6);
    adj(arr , 3 , 7);
    adj(arr , 4 , 5);
    adj(arr , 10 , 8);
    adj(arr , 8 , 2);
    adj(arr , 8 , 9);
    adj(arr , 9 , 10);

    print(arr);

    cycle(arr , v);
    return 0;
}