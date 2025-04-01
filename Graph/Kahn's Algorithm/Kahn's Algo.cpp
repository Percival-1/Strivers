#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<stack>
#include<queue>
using namespace std;

vector<int> endDegree(vector<vector<int>> &arr)
{
    vector<int> ans(arr.size() , 0);
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            ans[arr[i][j]]++;
        }
    }
    return ans;
}

vector<int> kahn(vector<vector<int>> &arr)
{
    queue<int> q;
    vector<int> end = endDegree(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        if(end[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> ans;
    while (!q.empty())
    {
        int a = q.front();
        q.pop();
        ans.push_back(a);
        for (auto &&i : arr[a])
        {
            end[i]--;
            if (end[i] == 0)
            {
                q.push(i);
            }
        }
    }
    return ans;
}

void adj(vector<vector<int>> & arr , int i , int j)
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
    vector<int> ans = kahn(arr);
    for (int i = 0; i < v; i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}