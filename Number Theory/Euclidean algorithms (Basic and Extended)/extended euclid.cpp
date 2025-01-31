#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<stack>
#include<queue>
using namespace std;

int extendedGcd(int a , int b , int &x , int &y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    int x1 , y1;
    int g = extendedGcd(b%a , a , x1 , y1);
    cout<<x1<<" "<<y1<<endl;

    y = x1;
    x = y1 - (b/a)*x1;
    return g;
}

int main(){
    int x = 0;
    int y = 0;
    int g = extendedGcd(414 , 662 , x , y);
    cout<<x<<" "<<y<<endl;
    return 0;
}