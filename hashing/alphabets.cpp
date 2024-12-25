#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    cout<<endl<<endl;
    string s ;
    cout<<"Enter a string : ";
    cin>>s;
    int n = s.length();

    int hash[26] = {0};
    for(int i = 0 ; i < n ; i++)
    {
        hash[s[i] - 97] +=1;
    }

    char ch;
    cout<<"Enter the character you want to count : ";
    cin>>ch;
    cout<<hash[ch-97]<<endl<<endl;
    return 0;
    
}