#include <bits/stdc++.h>
using namespace std;

int findKdist(vector<int> &arr, int k)
{
    int l = 0;
    int r = 0;
    int n = arr.size();
    unordered_map<int, int> m;
    int ans = 0;

    while(r < n)
    {
        m[arr[r]]++;
        r++;

        while(m.size() > k)
        {
            if(m[arr[l]] == 1)
            {
                m.erase(arr[l]);
            }
            else
            {
                m[arr[l]]--;
            }
        }
        ans += r - l;
    }

    return ans;
}

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    vector<int> arr = {2, 3, 4, 2, 2, 4, 1, 6};
    int k = 3;

    cout << findKdist(arr, k);

    return 0;
}