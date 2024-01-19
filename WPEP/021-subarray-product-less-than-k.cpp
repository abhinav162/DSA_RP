#include <bits/stdc++.h>
using namespace std;
int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    vector<int> arr = {10, 5, 2, 6};
    int k = 100;

    if (k <= 1)
        return 0;

    int l = 0;
    int r = 0;
    int n = arr.size();
    int p = 1;
    int ans = 0;

    while (r < n)
    {
        p = p * arr[r];
        while (p >= k)
        {
            p = p / arr[l];
            l++;
        }
        ans += r - l + 1;
        r++;
    }

    cout << ans;

    return 0;
}