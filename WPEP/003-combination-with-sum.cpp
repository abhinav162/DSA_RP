#include <bits/stdc++.h>
using namespace std;

int countCombinationS(int idx, vector<int> &arr, int n, int rem)
{
    if (idx == n)
    {
        if (rem == 0)
        {
            return 1;
        }
        return 0;
    }

    int ans = 0;
    for (int i = 0; i <= (rem / arr[idx]); i++)
    {
        ans += countCombinationS(idx + 1, arr, n, rem - arr[idx]);
    }

    return ans;
}

void printAllCombination(int idx, vector<int> &arr, int n, int target, vector<int> combinationArr, vector<vector<int>> &res)
{
    if (idx == n)
    {
        if (target == 0)
        {
            res.push_back(combinationArr);
        }
        return;
    }

    if (arr[idx] <= target)
    {
        combinationArr.push_back(arr[idx]);
        printAllCombination(idx, arr, n, target - arr[idx], combinationArr, res);
        combinationArr.pop_back();
    }

    printAllCombination(idx + 1, arr, n, target, combinationArr, res);
}

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    vector<int> arr = {1, 2, 3};
    int k = 5;

    // cout << combinationS(0, arr, arr.size(), k);

    // print all combination having sum equals k
    vector<vector<int>> res;
    vector<int> combinationArr;

    printAllCombination(0, arr, arr.size(), k, combinationArr, res);

    for (auto r : res)
    {
        for (auto c : r)
        {
            cout << c << " ";
        }
        cout << endl;
    }
    
    return 0;
}