#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<stack>
#include<queue>
using namespace std;

int str(string h , string d)
{
    int m = h.length();
    int n = d.length();
    if (n == 0)
    {
        return 0;
    }
    
    for (int i = 0; i <= m-n; i++)
    {
        int j = 0;
        while (j < n && (h[i+j] == d[j]))
        {
            j++;
        }
        if (j == n)
        {
            return i;
        }
    }
    return -1;
}

int main(){
    
    return 0;
}