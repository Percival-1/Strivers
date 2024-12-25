#include<iostream>
#include<vector>
using namespace std;

int main(){
    cout<<endl<<endl;
    int n ;
    cout<<"enter the length of the array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements :";
    for(int i = 0; i<n ; i++)
    {
        cin>>arr[i];
    }

    int hash[13] = {0};
    for(int i = 0 ; i<n ; i++)
    {
        hash[arr[i]] +=1;
    }
    int k;
    cout<<"Enter the element you want to count : ";
    cin>>k;
    cout<<hash[k]<<endl<<endl;
    
    return 0;
}