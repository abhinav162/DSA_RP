#include <bits/stdc++.h>
using namespace std;

/*
Approach :
1. Create a map of first array and store the frequency of each element.
2. Now traverse the second array and decrement the frequency of those element which is present in second array. (what will happen here is if any element which is not present in 1st array but it is in 2nd array then its frequency will become negative)
3- Now thech if any element in map have frequency less than 0, if yes then array 2 se not subset.
*/
bool checkSubset(vector<int> &arr1, vector<int> &arr2, int n, int m)
{
    // Write your code here.

    unordered_map<int, int> mp1;

    for (int i = 0; i < n; i++)
    {
        mp1[arr1[i]]++;
    }

    for (int i = 0; i < m; i++)
    {
        mp1[arr2[i]]--;
    }

    for (auto i : mp1)
    {
        if (i.second < 0)
            return false;
    }

    return true;
}

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here for check subset
    vector<int> arr1 = {5, 1, 3};
    vector<int> arr2 = {5, 5};
    cout << checkSubset(arr1, arr2, arr1.size(), arr2.size());
    return 0;
}