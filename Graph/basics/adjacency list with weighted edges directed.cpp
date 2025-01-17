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
    int u , v , e;
    int  n , m;
    cin>>n>>m;
    vector<vector<pair<int , int>>> arr(n+1);
    for (int i = 0; i < m; i++)
    {
        cin>>u>>v>>e;
        arr[u].push_back({v,e});
    }
    
    //print
    cout<<"vertex     edge"<<endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout<<" "<<i<<"  "<<arr[i][j].first<<"      "<<arr[i][j].second<<endl;;
        }
        cout<<endl;
    }
    return 0;
} 