#include <bits/stdc++.h>
using namespace std;

void findCombo(int digit, int target, int length, vector<int> &temp, vector<vector<int>> &res)
{
    if (target == 0 && temp.size() == length)
    {
        res.push_back(temp);
        return;
    }

    for (int i = digit; i <= 9; i++)
    {
        temp.push_back(i);
        findCombo(i + 1, target - i, length, temp, res);
        temp.pop_back();
    }
}

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    vector<int> arr = {4, 3, 6, 5, 7, 3, 4};
    int k = 3;
    int n = 7;

    vector<vector<int>> res;
    vector<int> temp;
    findCombo(1, n, k, temp, res);

    for (auto i : res)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}