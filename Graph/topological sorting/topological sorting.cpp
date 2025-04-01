#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<stack>
#include<queue>
using namespace std;

void dfs(vector<vector<int>> &arr , vector<int> &vis , int node , stack<int> &st)
{
    vis[node] = 1;
    for (auto &&i : arr[node])
    {
        if (!vis[i])
        {
            dfs(arr , vis , i , st);
        }
    }
    st.push(node);
}

vector<int> topological(vector<vector<int>> &arr)
{
    int v = arr.size();
    vector<int> vis(v , 0);
    stack<int> st;
    for (int i = 0; i < v; i++)
    {
        if(!vis[i])
        {
            dfs(arr ,vis , i , st);
        }
    }
    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
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
    int v = 6;
    vector<vector<int>> arr(v);
    adj(arr , 5 , 0);
    adj(arr , 4 , 0);
    adj(arr , 4 , 1);
    adj(arr , 3 , 1);
    adj(arr , 2 , 3);
    adj(arr , 5 , 2);
    print(arr);
    vector<int> ans = topological(arr);
    for (int i = 0; i < v; i++)
    {
        cout<<ans[i]<<" ";
    }
    
    return 0;
}