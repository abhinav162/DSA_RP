#include <bits/stdc++.h>
using namespace std;

struct m {
    int value;
    int idx;
    int freq;
};

bool comp(map<int, int> &a, map<int, int> &b)
{
    // return a.second < b.second;
}

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    vector<int> arr = {2, 3, 4, 2, 2, 4, 1, 6};

    map<int, int> mp;

    for(auto i : arr)
    {
        mp[i]++;
    }

    sort(mp.begin(), mp.end(), comp);

    for(auto i: mp)
    {
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}