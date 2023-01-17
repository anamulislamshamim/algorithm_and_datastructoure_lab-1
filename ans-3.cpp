// WAP that takes n integer numbers and an integer k, and how many pairs of numbers in the array which sums to k. You have to do it inside the Merge Sort function, divide and conquer fashion in O(nlogn).
#include<bits/stdc++.h>
using namespace std;
int k;
int c=0;
int n;
vector<int>countPair(vector<int> arr)
{
    if(arr.size() <= 1)
        return arr;
    int mid = arr.size() / 2;
    vector<int>left;
    vector<int>right;
    for(int i=0; i<mid; i++)
        left.push_back(arr[i]);
    for(int i=mid; i<arr.size(); i++)
        right.push_back(arr[i]);
    vector<int>count_left=countPair(left);
    vector<int>count_right=countPair(right);
    // count the left and right;
    int il=0,ir=0;
    vector<int>sorted_arr;
    while(il < count_left.size() && ir < count_right.size())
    {
        if(count_left[il] < count_right[ir])
        {
            sorted_arr.push_back(count_left[il]);
            il++;
        }
        else
        {
            sorted_arr.push_back(count_right[ir]);
            ir++;
        }
    };
    while(il < count_left.size())
    {
        sorted_arr.push_back(count_left[il]);
        il++;
    };
    while(ir < count_right.size())
    {
        sorted_arr.push_back(count_right[ir]);
        ir++;
    };

    // int c=0;
    if(sorted_arr.size() == n)
    {
        int i=0,j=sorted_arr.size() - 1;
        while(i<j)
        {
            if(sorted_arr[i]+sorted_arr[j] > k)
            {
                j--;
            }
            else if(sorted_arr[i]+sorted_arr[j]<k)
            {
                i++;
            }else if(sorted_arr[i]+sorted_arr[j] == k){
                c++;
                i++;
                j--;
            }
            else
            {
                i++;
                j--;
            }
        }
    };
    // cout << "ans: " << c << "\n";
    return sorted_arr;

}

int main()
{
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cin >> k;
    countPair(arr);
    cout << c << "\n";
    return 0;
}
