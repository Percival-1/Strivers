#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<stack>
#include<queue>
#include<set>
using namespace std;

vector<int> dij(vector<vector<pair<int , int>>> &arr , int s)
{
    int v = arr.size();
    set<pair<int , int>> st;
    vector<int> dis(v , INT_MAX);
    dis[s] = 0;
    st.insert({0 , s});
    while (!st.empty())
    {
        pair<int , int> p = *st.begin();
        st.erase(st.begin());
        int distance = p.first;
        for (auto &&i : arr[p.second])
        {
            if(i.first + distance < dis[i.second])
            {
                if(dis[i.second] != INT_MAX)
                {
                    st.erase({dis[i.second] , i.first});
                }
                
                dis[i.second] = i.first + distance;
                st.insert({i.first + distance , i.second});
            }
        }
    }
    return dis;
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
    
    vector<int> ans = dij(arr , 0);
    cout<<ans[v-1];
    return 0;
}