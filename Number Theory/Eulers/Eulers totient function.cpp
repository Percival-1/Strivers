#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<stack>
#include<queue>
using namespace std;

int phi(int n)
{
    int result = n;
    for (int p = 2; p*p <= n; p++)
    {
        if ((n % p) == 0 )
        {
            while ((n % p) == 0)
            {
                n = n/p;
            }
            result -= result/p;
        }
    }
    if (n > 1)
    {
        result -= result/n;
    }
    return result;
}

int main(){
    cout<<phi(1)<<endl;
    return 0;
}