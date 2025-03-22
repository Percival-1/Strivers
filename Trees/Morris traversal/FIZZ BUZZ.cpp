#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<stack>
#include<queue>
using namespace std;

class Solution {
    public:
        vector<string> fizzBuzz(int n) {
            vector<string> arr;
            for (int i = 1; i <= n; i++)
            {
                if(i%15 == 0)
                {
                    arr.push_back("FizzBuzz");
                }
                else if (i%5 == 0)
                {
                    arr.push_back("Buzz");
                }
                else if (i%3 == 0)
                {
                    arr.push_back("Fizz");
                }
                else
                {
                    arr.push_back(to_string(i));
                }
            }
            return arr;
        }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    return 0;
}