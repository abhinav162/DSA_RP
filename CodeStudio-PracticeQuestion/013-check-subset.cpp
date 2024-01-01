#include <bits/stdc++.h>
using namespace std;

bool checkSubset(vector<int> &arr1, vector<int> &arr2, int n, int m)
{
    // Write your code here.

    unordered_map<int, int> mp1;
    unordered_map<int, int> mp2;

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