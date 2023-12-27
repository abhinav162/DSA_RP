#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> twoSum(vector<int> &arr, int target, int n)
{
    vector<pair<int, int>> res;
    sort(arr.begin(), arr.end());
    int start = 0, end = arr.size() - 1;

    while (start < end)
    {
        if (arr[start] + arr[end] == target)
        {
            res.push_back({arr[start], arr[end]});
            start++;
            end--;
        }
        else if (arr[start] + arr[end] < target)
        {
            start++;
        }
        else
        {
            end--;
        }
    }

    if (!res.size())
        res.push_back(pair<int, int>(-1, -1));

    return res;
}

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    vector<int> arr = {1, -1, -1, 2, 2};
    int target = 1;

    vector<pair<int, int>> res = twoSum(arr, target, arr.size());

    for (auto p : res)
    {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}