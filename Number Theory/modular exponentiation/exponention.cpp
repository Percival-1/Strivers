#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<stack>
#include<queue>
using namespace std;

int power(long long x , unsigned int y )
{
    int res = 1;
    while (y > 0)
    {
        if (y&1 == 1)
        {
            res = res*x;
        }
        y = y>>1;
        x = (x*x);
    }
    return res;
}

int main(){
    cout<<power(2,10);
    return 0;
}