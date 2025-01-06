#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<unordered_map>
using namespace std;

int main(){
    class StImp{
        int top = -1;
        int st[10];

        public:
        void push(int n)
        {
            if(top >= 10)
            {
                return;
            }
            top = top + 1;
        }
    };
    return 0;
}