#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
    cout<<endl<<endl;
    int n;
    cout<<"Enter the length of the array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements : ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    map<int , int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }
    cout<<"Enter the number you want to count : ";
    int k;
    cin>>k;
    cout<<"the count of the given number is : "<<mpp[k];
    cout<<endl<<endl;
    return 0;
}