#include <bits/stdc++.h>
using namespace std;

void findSubset(vector<int> &arr, int i, int n, set<vector<int>> &resSet, vector<int> tempSet)
{
    if (i == n)
    {
        if (tempSet.size() == 0)
            return;
        resSet.insert(tempSet);
        return;
    }

    tempSet.push_back(arr[i]);
    findSubset(arr, i + 1, n, resSet, tempSet);

    tempSet.pop_back();
    findSubset(arr, i + 1, n, resSet, tempSet);
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    set<vector<int>> st;
    vector<int> tempSet;
    findSubset(arr, 0, n, st, tempSet);
    vector<vector<int>> res;

    for (auto i : st)
    {
        vector<int> temp;
        for (auto j : i)
        {
            temp.push_back(j);
        }
        res.push_back(temp);
    }

    return res;
}

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    vector<int> arr = {1, 1, 3};
    int n = arr.size();

    vector<vector<int>> res = uniqueSubsets(n, arr);

    sort(res.begin(), res.end());

    for (auto i : res)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}