#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<stack>
#include<queue>
using namespace std;

void totient(int n)
{
    vector<long long> phi(n+1);
    for (int i = 1; i <= n; i++)
    {
        phi[i] = i;
    }
    for (int p = 2; p <= n; p++)
    {
        if (phi[p] == p)
        {
            phi[p] = p-1;

            for (int i = 2*p; i <= n; i+=p)
            {
                phi[i] -=(phi[i]/p);
            }
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        cout<<"Totient value of "<<i<<" : "<<phi[i]<<endl;
    }
}

int main(){
    totient(12);
    return 0;
}