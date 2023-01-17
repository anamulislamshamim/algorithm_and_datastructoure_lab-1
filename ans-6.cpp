/*
See the sample input-output for more clarification.
Note - The given array will be sorted in increasing order. And it is guaranteed that at least one occurrence of k will exist.

** Solve this problem using binary search means O(logn)**
*/
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    int k;
    cin >> k;
    // sort the arr
    sort(arr.begin(), arr.end());
    // binary search
    int left=0, right=n;
    int c=0;
    while(left < right){
        int mid=(left+right)/2;
        if(arr[mid] == k)
            c++;
        if(c>1)
            break;
        if(k < arr[mid]){
            right=mid-1;
        }else if(k > arr[mid])
        {
            left=mid+1;
        };
    };
    if(c>1)
        cout << "YES" << "\n";
    else
        cout << "False" << "\n";
    return 0;
}
