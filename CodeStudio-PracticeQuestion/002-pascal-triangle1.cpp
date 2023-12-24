#include <bits/stdc++.h>
using namespace std;
int main()
{
    // input output for files
    #define TxtIO
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<vector<long long int>> res;

    for (int i = 0; i <= n; i++)
    {
        res.push_back(vector<long long int>(i, 1)); // adding 1D array of size i for all rows and columns value will be 1 for all
    }

    for (int i = 2; i < res.size(); i++)
    {
        for (int j = 1; j < res[i].size() - 1; j++)
        {
            res[i][j] = res[i - 1][j] + res[i - 1][j - 1];
        }
    }

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}