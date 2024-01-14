#include <bits/stdc++.h>
using namespace std;
int longestSubarrayWithSumK(vector<int> a, long long k)
{
    int left = 0, right = 0;
    long long sum = a[0];
    int maxLen = 0;
    int n = a.size();

    while (right < n)
    {
        while (left <= right && sum > k)
        {
            sum -= a[left];
            left++;
        }
        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
        if (right < n)
        {
            sum += a[right];
        }
    }
    return maxLen;
}


// recursive -TLE
int findLongest(vector<int> &arr, int i, int n, long long k, long long sum, long long count)
{
    if (i == n)
    {
        if (sum == k)
        {
            return count;
        }
        return 0;
    }

    int x = findLongest(arr, i + 1, n, k, sum + arr[i], count + 1);
    int y = findLongest(arr, i + 1, n, k, sum, count);

    return max(x, y);
}

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8};
    long long k = 15;

    cout << longestSubarrayWithSumK(a, k);

    cout << endl;

    cout << findLongest(a, 0, a.size(), k, 0, 0);

    return 0;
}