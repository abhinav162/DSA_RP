#include <bits/stdc++.h>
using namespace std;

vector<int> findCommonElements(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    vector<int> res;

    vector<set<int>> st(n);

    for (int i = 0; i < n; i++)
    {
        st[i].insert(mat[i].begin(), mat[i].end());
    }

    for (auto it = st[0].begin(); it != st[0].end(); it++)
    {
        int num = *it;
        int count = 1;
        for (int i = 1; i < n; i++)
        {
            if (st[i].find(num) != st[i].end())
            {
                count++;
            }
        }

        if (count == n)
        {
            res.push_back(num);
        }
    }


    // map<int, int> mp;

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         mp[mat[i][j]]++;
    //     }
    // }


    // for (auto it = mp.begin(); it != mp.end(); it++)
    // {
    //     if (it->second >= n)
    //     {
    //         res.push_back(it->first);
    //     }
    // }

    return res;
}

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    vector<int> res = findCommonElements(mat);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " " << endl;
    }

    return 0;
}