
#include <bits/stdc++.h>
using namespace std;

vector<int> getFrequencies(vector<int> &v)
{
    // Write Your Code Here
    map<int, int> mp;

    for (int i = 0; i < v.size(); i++)
    {
        mp[v[i]]++;
    }

    vector<int> h;
    vector<int> l;
    int hf = 0, lf = INT_MAX;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << it->first << " " << it->second << endl;

        if(it->second > hf){
            hf = it->second;
            h.clear();
            h.push_back(it->first);
        }

        if(it->second < lf){
            lf = it->second;
            l.clear();
            l.push_back(it->first);
        }
    }

    vector<int> res = {h.back(), l.back()};

    return res;
}

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    vector<int> v = {1, 2, 3, 1, 1, 4};
    vector<int> res = getFrequencies(v);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}