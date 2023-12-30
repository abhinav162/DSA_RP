#include <bits/stdc++.h>
using namespace std;

// using set to avoid duplicate rows
vector<vector<int>> findTriplets(vector<int> arr, int n, int K)
{
    // Write your code here.
    sort(arr.begin(), arr.end());
    vector<vector<int>> res;
    set<vector<int>> tempSet;

    for (int i = 0; i < n; i++)
    {
        int target = K - arr[i];
        int start = i + 1;
        int end = n - 1;

        while (start < end)
        {
            int check = arr[start] + arr[end];
            if (check == target)
            {
                tempSet.insert({arr[i], arr[start], arr[end]});
                start++;
                end--;
            }
            else if (check > target)
            {
                end--;
            }
            else
            {
                start++;
            }
        }
    }

    for (auto r : tempSet)
    {
        res.push_back(r);
    }

    return res;
}

int main()
{
    // input output for files
    // freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    // vector<int> arr = {10, 5, 5, 5, 2};
    vector<int> arr = {1, 1, 2, 2, 1, 1};
    int k = 4;

    vector<vector<int>> res = findTriplets(arr, arr.size(), k);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}