#include <bits/stdc++.h>
using namespace std;

void findSubset(int i, int k, int n, vector<int> &arr, vector<int> &temp, vector<vector<int>> &res)
{
    if (i == n)
    {
        res.push_back(temp);
        return;
    }

    temp.push_back(arr[i]);
    findSubset(i + 1, k, n, arr, temp, res);
    temp.pop_back();
    findSubset(i + 1, k, n, arr, temp, res);
}

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
    vector<vector<int>> res;
    vector<int> temp;

    findSubset(0, k, arr.size(), arr, temp, res);

    for(auto i : res)
    {
        for(auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}