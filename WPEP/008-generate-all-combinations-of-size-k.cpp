#include <bits/stdc++.h>
using namespace std;
void findC(int i, int n, int k, vector<int> &temp, vector<vector<int>> &res)
{
    if (i > n)
    {
        if (k == 0)
        {
            res.push_back(temp);
        }
        return;
    }

    // if (k == 0)
    // {
    //     res.push_back(temp);
    //     return;
    // }

    temp.push_back(i);
    findC(i + 1, n, k - 1, temp, res);
    temp.pop_back();

    findC(i + 1, n, k, temp, res);
}

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    int n;
    int k;

    cin >> n >> k;

    vector<vector<int>> res;
    vector<int> temp;

    findC(1, n, k, temp, res);

    for (auto r : res)
    {
        for (auto c : r)
        {
            cout << c << " ";
        }
        cout << endl;
    }
    return 0;
}