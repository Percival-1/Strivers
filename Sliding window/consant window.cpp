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
    vector<int> arr = {-1 , 1 , 2, 3 , 4 , -2 , 5 , -1 , 3};
    int s;
    cout<<"Enter the size : "<<endl;
    cin>>s;
    int maxSum = 0;
    for (int i = 0; i < s; i++)
    {
        maxSum += arr[i];
    }
    int l = 0;
    int r = s-1;
    int sum = maxSum;
    while (r < arr.size()-1 )
    {
        sum = sum - arr[l];
        l++;
        r++;
        sum = sum + arr[r];
        maxSum = max(maxSum , sum);
    }
    cout<<maxSum<<endl;
    return 0;
}