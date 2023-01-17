/*
Write a C++ program that returns the elements in a vector that
    are even numbered.
    1)Take 5 elements into a vector.
    2)Define a function named even_generator(), which receives a vector
    and returns a vector that only contains even numbers.
    
    Note: You don't need to take input from the user.
*/
#include<bits/stdc++.h>
using namespace std;

vector<int>even_generator(vector<int>arr)
{
    vector<int>ans;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]%2==0)
            ans.push_back(arr[i]);
    };
    return ans;
}

int main()
{
    vector<int>arr={1,2,3,4,5,6,7};
    vector<int>ans=even_generator(arr);
    for(int i=0;i<ans.size();i++)
        cout << ans[i] << " ";
    return 0;
}
