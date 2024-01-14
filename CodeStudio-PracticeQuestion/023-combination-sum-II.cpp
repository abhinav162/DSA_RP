#include <bits/stdc++.h>
using namespace std;

// Works but TLE
void generateCombinations(vector<int> &arr, int i, int n, int target, vector<int> &temp, set<vector<int>> &res)
{
    if (i == n)
    {
        if (target == 0)
        {
            res.insert(temp);
        }
        return;
    }

    if (arr[i] <= target)
    {
        temp.push_back(arr[i]);
        generateCombinations(arr, i + 1, n, target - arr[i], temp, res);
        temp.pop_back();
    }

    generateCombinations(arr, i + 1, n, target, temp, res);
}

void generateCombinations2(vector<int> &arr, int idx, int n, int target, vector<int> &temp, vector<vector<int>> &res)
{
    if (target == 0)
    {
        res.push_back(temp);
        return;
    }

    for (int i = idx; i < n; i++)
    {
        if (i > idx && arr[i] == arr[i - 1])
        {
            continue;
        }
        if (arr[i] > target)
        {
            break;
        }
        else
        {
            temp.push_back(arr[i]);
            generateCombinations2(arr, i + 1, n, target - arr[i], temp, res);
            temp.pop_back();
        }
    }
}

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    vector<int> arr = {1, 1, 1, 2, 2};
    int target = 5;

    //// TLE
    // vector<int> temp;
    // set<vector<int>> res;
    // generateCombinations(arr, 0, arr.size(), target, temp, res);
    // vector<vector<int>> ans(res.begin(), res.end());

    //// Works
    vector<vector<int>> ans;
    vector<int> temp;
    sort(arr.begin(), arr.end());
    generateCombinations2(arr, 0, arr.size(), target, temp, ans);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}