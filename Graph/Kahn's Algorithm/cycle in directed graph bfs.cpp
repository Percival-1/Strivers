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
    for (int i = 1; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            ans[arr[i][j]]++;
        }
    }
    return ans;
}

void cycle(vector<vector<int>> &arr)
{
    int v = arr.size();
    vector<int> end = endDegree(arr);
    queue<int> q;
    for (int i = 1; i < v; i++)
    {
        if(end[i] == 0)
        {
            q.push(i);
        }
    }
    
    vector<int> ans;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (auto &&i : arr[node])
        {
            end[i]--;
            if(end[i] == 0)
            {
                q.push(i);
            }
        }
    }

    if (ans.size() < v)
    {
        cout<<"cycle exists"<<endl;
        return;
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
    int v = 5;
    vector<vector<int>> arr(v + 1);
    adj(arr , 1 , 2);
    adj(arr , 2 , 3);
    adj(arr , 3 , 5);
    adj(arr , 3 , 4);
    adj(arr , 4 , 2);
    print(arr);
    cycle(arr);
    return 0;
}