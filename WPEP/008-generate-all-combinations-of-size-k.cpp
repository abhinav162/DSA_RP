#include <bits/stdc++.h>
using namespace std;
void findC(int i, int n, int k, vector<int> &temp, int target, vector<vector<int>> &res)
{
    if (i > n)
    {
        if (k == 0 && target == 0)
        {
            res.push_back(temp);
        }
        return;
    }

    temp.push_back(i);
    findC(i + 1, n, k - 1, temp, target-i, res);
    temp.pop_back();

    findC(i + 1, n, k, temp, target, res);
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

    findC(1, n, k, temp, 7, res);

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