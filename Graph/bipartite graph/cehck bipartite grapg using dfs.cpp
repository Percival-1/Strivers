#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<stack>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* right;
    Node* left;

    Node() : data(0) , right(nullptr) , left(nullptr) {}
    Node(int val) : data(val) , right(nullptr) , left(nullptr) {}
    Node(int val , Node* right1 , Node* left1) : data(val) , right(right1) , left(left1) {} 
};

bool dfs(vector<vector<int>> &arr , vector<int> &vis , int node , int color)
{
    for (auto &&i : arr[node])
    {
        if(vis[i] == -1)
        {
            vis[i] = color;
            if(!dfs(arr , vis , i , !vis[i]))
            {
                return false;
            }
        }
        else if(vis[i] == vis[node])
        {
            return false;
        }
    }
    return true;
}

void bipartite(vector<vector<int>> &arr , int v)
{
    vector<int> vis(v+1 , -1);

    for (int i = 1; i < v+1; i++)
    {
        if (vis[i] == -1 && !dfs(arr , vis , i , 0))
        {
            cout<<"not bipartite graph"<<endl;
            return;
        }
    }
    
    cout<<"biprtite graph"<<endl;
}

void adj(vector<vector<int>> &arr , int i , int j)
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
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int v = 8;
    vector<vector<int>> arr(v+1);
    adj(arr , 1 , 2);
    adj(arr , 2 , 3);
    adj(arr , 2 , 6);
    adj(arr , 3 , 4);
    adj(arr , 4 , 5);
    adj(arr , 4 , 7);
    adj(arr , 5 , 6);
    adj(arr , 7 , 8);

    print(arr);

    bipartite(arr , v);

    return 0;
}