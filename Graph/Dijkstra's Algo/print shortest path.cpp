#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<stack>
#include<queue>
using namespace std;

vector<int> dij(vector<vector<pair<int , int>>> &arr , int s)
{
    int v = arr.size();
    vector<int> dis(v , INT_MAX);
    vector<int> path(v , 0);
}

void adj(vector<vector<pair<int , int>>> &arr , int i , int j , int e)
{
    arr[i].push_back({e , j});
    arr[j].push_back({e , i});
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    return 0;
}