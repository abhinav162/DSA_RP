#include <bits/stdc++.h>
using namespace std;
int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    // vector<int> arr = {68, 41, 9, 52, 54, 45, 13, 13, 58, 1};
    vector<int> arr = {1, 1, 1};
    int k = 2;
    int n = arr.size();
    int sum = 0;

    unordered_map<int, int> mp;
    int cnt = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];

        if (sum == k)
            cnt++;

        if (mp.find(sum - k) != mp.end())
        {
            cnt += mp[sum - k];
        }

        mp[sum]++;
    }

    cout << cnt;

    return 0;
}