#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<stack>
#include<queue>
using namespace std;

int main(){
    int n , m;
    cin>>n>>m;
    vector<vector<int>> arr(n+1);
    int u,v;
    for (int i = 0; i < m; i++)
    {
        cin>>u>>v;
        arr[u].push_back(v);
    }

    // print

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
    return 0;
}