#include <bits/stdc++.h>
using namespace std;

int minSubsetSumDifference(vector<int> &arr, int n)
{
    int range = 0;
    for (int i = 0; i < n; i++)
        range += arr[i];

    bool dp[n + 1][range + 1];

    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    for (int i = 1; i <= range; i++)
        dp[0][i] = false;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= range; j++)
        {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];

            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    int minDiff = INT_MAX;
    for (int i = 0; i <= range / 2; i++)
    {
        if (dp[n][i])
            minDiff = min(minDiff, range - 2 * i);
    }

    return minDiff;
}

void findSums(vector<int> &arr, int i, int n, int sum, int totalSum,vector<pair<int, int>> &sumsArray)
{
    if (i == n)
    {
        if (sum != 0)
            sumsArray.push_back({sum, totalSum - sum});
        return;
    }

    findSums(arr, i + 1, n, sum + arr[i], totalSum,sumsArray);
    findSums(arr, i + 1, n, sum, totalSum, sumsArray);
}

int minSubsetSumDifference2(vector<int> &arr, int n)
{
    sort(arr.begin(), arr.end());
    int totalSum = accumulate(arr.begin(), arr.end(), 0);

    vector<pair<int, int>> sumStore;

    findSums(arr, 0, n, 0, totalSum, sumStore);

    int minDiff = INT_MAX;
    for (int i = 0; i < sumStore.size(); i++)
    {
        minDiff = min(minDiff, abs(sumStore[i].first - sumStore[i].second));
    }

    return minDiff;
}

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << minSubsetSumDifference2(arr, n); // my method

    // cout << minSubsetSumDifference(arr, n); // striver's method

    return 0;
}