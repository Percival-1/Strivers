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
    vector<int> arr = {1 , 2 , 9 , 3 , 5 , 1 , 1 , 1 , 1 , 8 , 10  , 2 , 2 , 2 , 1 , 1 , 1 , 1 , 1 , 2 , 2 , };
    int k;
    cout<<"Enter the sum : ";
    cin>>k;
    int l = 0 , r = 0 , len = 0 , sum = 0;
    int first = 0;
    while (r < arr.size()-1)
    {
        sum = sum + arr[r];
        if (sum>k)
        {
            sum = sum - arr[l];
            l++;
        }
        if (sum <= k)
        {
            if ((r-l+1) > len)
            {
                first = l;
            }
            len = max(len , r-l+1);
        }
        r++;
    }
    cout<<"Max subarray is : "<<len<<endl;
    for (int i = first; i < first + len ; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}