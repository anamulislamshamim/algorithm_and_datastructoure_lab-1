// WAP that takes n integer numbers, sorts them in non-increasing order using Quick sort.
#include<bits/stdc++.h>
using  namespace std;

vector<int>quickSort(vector<int>arr)
{
    // check the length of the array. If length is 1 or 0 just return the array.
    if(arr.size() <= 1)
        return  arr;
    int pivot = arr[arr.size() - 1];
// create two arrays with the value less than pivot and another one is with greater // // than or equal to pivot.
    vector<int>left;
    vector<int>right;
    // since i define a element as a pivot value
    int sz=arr.size() - 1;
    for(int i=0;i<sz;i++)
    {
        if(arr[i]<pivot)
            left.push_back(arr[i]);
        else
            right.push_back(arr[i]);
    }
// now sort the left and right arrays:
    vector<int>sorted_left=quickSort(left);
    vector<int>sorted_right=quickSort(right);
// now we need to merge sorted left array , pivot and sorted right array;
    vector<int>mergeArr;
// merge the sorted left array
    for(int i=0; i<sorted_left.size(); i++)
        mergeArr.push_back(sorted_left[i]);
// merge the pivot value;
    mergeArr.push_back(pivot);
// merge the sorted left array:
    for(int i=0; i<sorted_right.size(); i++)
        mergeArr.push_back(sorted_right[i]);
    // Here merge is the sorted array of arr.
    return mergeArr;
};

int main()
{
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    vector<int>ans=quickSort(arr);
    for(int i=0; i<ans.size(); i++)
        cout << ans[i] << " " ;
    return 0;
}
