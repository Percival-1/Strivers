#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<unordered_map>
#include<cmath>
using namespace std;

void merge(vector<int> &arr , int low , int mid , int high)
{
    vector<int> temp;
    int left = low;
    int right = mid+1;
    while(left<=mid && right <= high)
    {
        if(arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i-low];
    }
    
}

void ms(vector<int> &arr , int low , int high)
{
    if(low >= high)
    {
        return;
    }
    int mid = (low + (high - low)/2);
    ms(arr , low , mid);
    ms(arr , mid+1 , high);
    merge(arr , low , mid , high);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    vector<int> arr = {2,43,54,2,3,4,3,112,56,76,8,23,54,67};
    ms(arr,0,arr.size()-1);
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}