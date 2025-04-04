#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<stack>
#include<queue>
using namespace std;

int modularExpo(long long x , unsigned int y , int p)
{
    int res = 1;
    x = x % p;

    if (x == 0)
    {
        return 0;
    }
    
    while (y>0)
    {
        if (y&1 == 1)
        {
            res = (res*x)%p;
        }
        y = y>>1;
        x = (x*x)%p;
    }
    return res;
}

int main(){
    cout<<modularExpo(3,10,7);
    return 0;
}