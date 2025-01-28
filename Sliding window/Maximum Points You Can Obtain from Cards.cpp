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
    vector<int> arr = {6 , 2 , 3 , 4 , 7 , 2 , 1 , 7 , 1};
    int sum = 0 , r = 0 , maxSum = 0;
    int k;
    cout<<"Enter a size : ";
    cin>>k;
    
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    maxSum = max(maxSum , sum);
    r = arr.size() - 1;
    for (int i = k - 1; i >= 0 ; i--)
    {
        sum = sum - arr[i] + arr[r];
        maxSum = max(maxSum , sum);
        r--;
    }
    cout<<"largest point : "<<maxSum<<endl;
    
    return 0;
}