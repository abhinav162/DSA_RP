#include <bits/stdc++.h>
using namespace std;

int findMajorityElement(int arr[], int n)
{
    map<int, int> m;

    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }

    int ele = -1;

    for (auto it = m.begin(); it != m.end(); it++)
    {
        if (it->second > n / 2)
        {
            ele = it->first;
        }
    }

    return ele;
}

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    int arr[] = {5, 2, 0, 0};

    cout << findMajorityElement(arr, 4);

    return 0;
}