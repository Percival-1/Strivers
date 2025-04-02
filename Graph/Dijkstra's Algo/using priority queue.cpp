#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<stack>
#include<queue>
using namespace std;

int dij(vector<vector<pair<int , int>>> &arr , int s)
{
    int v = arr.size();
    priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;
    vector<int> dis(v , INT_MAX);
    dis[s] = 0;
    pq.push({0 , s});
    while (!pq.empty())
    {
        pair<int , int> p = pq.top();
        pq.pop();
        int distance = p.first;
        for (auto &&i : arr[p.second])
        {
            if (i.first + distance < dis[i.second])
            {
                dis[i.second] = i.first + distance;
                pq.push({distance + i.first , i.second});
            }
        }
    }
    return dis[v-1];
}

void adj(vector<vector<pair<int , int>>> &arr , int i , int j , int e)
{
    arr[i].push_back({e , j});
    arr[j].push_back({e , i});
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int v  = 6;

    vector<vector<pair<int , int>>> arr(v);

    adj(arr , 0 , 1 , 4);
    adj(arr , 0 , 2 , 4);
    adj(arr , 1 , 2 , 2);
    adj(arr , 2 , 3 , 3);
    adj(arr , 2 , 5 , 6);
    adj(arr , 2 , 4 , 1);
    adj(arr , 3 , 5 , 2);
    adj(arr , 4 , 5 , 3);
    cout<<dij(arr , 0);

    return 0;
}