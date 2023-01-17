// WAP that takes n-1 integer numbers, which contains distinct integers from 1 to n. Exactly one number between 1 to n is missing. Find that number in O(n).
#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin >> n;
    vector<int>arr(n-1);
    for(int i=0;i<n-1;i++)
        cin >> arr[i];
    vector<int>heap(n,0);
    for(int i=0;i<arr.size();i++)
        heap[arr[i]]+= 1;
    // search the missing element
    for(int i=1;i<heap.size();i++)
    {
        if(heap[i] == 0){
            cout << "ans: " << i << "\n";
            return 0;
        }
    }
    return 0;
}
