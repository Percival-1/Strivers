#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<unordered_map>
#include<stack>
#include<queue>
using namespace std;

class Heap{
    public:
        vector<int> arr;

        void heapify(vector<int> &arr , int n , int i)
        {
            int largest = i;
            int l = 2*i + 1;
            int r = 2*i + 2;

            if(l < n && arr[largest] < arr[l])
            {
                largest = l;
            }

            if(r < n && arr[largest] < arr[r])
            {
                largest = r;
            }

            if(largest != i)
            {
                swap(arr[largest] , arr[i]);
                heapify(arr , n , largest);
            }
        }

        void insert(int val)
        {
            arr.push_back(val);
            int n = arr.size();
            for (int i = n/2 - 1; i >= 0; i--)
            {
                heapify(arr , n , i);
            }
        }

        void deleteRoot(vector<int> &arr)
        {
            int n = arr.size();
            if (n == 0)
            {
                return;
            }
            
            swap(arr[0] , arr[n-1]);
            arr.pop_back();
            heapify(arr , arr.size() , 0);
        }
        
        void heapSort(vector<int> &sort)
        {
            int n  = sort.size();
            for (int i = n/2 - 1; i >= 0; i--)
            {
                heapify(sort , n , i);
            }
            for (int i = n - 1; i >= 0; i--)
            {
                swap(sort[0] , sort[i]);
                heapify(sort , i , 0);
            }
        }

        void print(vector<int> arr)
        {
            for (int i = 0; i < arr.size(); i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }

};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Heap* obj = new Heap();

    obj->insert(23);
    obj->insert(14);
    obj->insert(35);
    obj->insert(56);
    obj->insert(44);
    obj->insert(30);
    obj->deleteRoot(obj->arr);
    obj->print(obj->arr);
    
    return 0;
}