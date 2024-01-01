#include <bits/stdc++.h>
using namespace std;
vector<int> findMissingRepeatingNumbers(vector<int> a)
{
    // Write your code here
    sort(a.begin(), a.end());
    map<int, int> mp;
    int start = 1;
    int end = a.back();

    while (start <= a.size())
    {
        mp[start] = 0;
        start++;
    }

    for (int i = 0; i < a.size(); i++)
    {
        mp[a[i]]++;
    }

    int M = 0, R;

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if (it->second == 0)
        {
            M = it->first;
        }
        else if (it->second > 1)
        {
            R = it->first;
        }
    }

    return {R, M};
}

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    vector<int> a = {1, 2, 3, 2};
    vector<int> ans = findMissingRepeatingNumbers(a);

    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}