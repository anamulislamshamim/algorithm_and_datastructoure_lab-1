/*
You are given an array of n positive integers. Your task is to remove the element from the range a position to b position.
After removing the element print the all elements left.
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
    int p1,p2;
    cin >> p1 >> p2;
    for(int i=0;i<n;i++){
        if(i < p1-1 || i > p2-1)
            cout << arr[i] << " ";
    };
    return 0;
}
