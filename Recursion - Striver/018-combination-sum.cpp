#include <bits/stdc++.h>
using namespace std;
void printCombination(int i, vector<int> &arr, int n, int target, vector<int> temp, vector<vector<int>> &res)
{
    if (i == n)
    {
        if (target == 0)
        {
            res.push_back(temp);
        }
        return;
    }

    // pick element at i index only when element is less than or equal to target
    if (arr[i] <= target)
    {
        temp.push_back(arr[i]);
        printCombination(i, arr, n, target - arr[i], temp, res); // decrement element from target and don't increment the index as we can pick the same element multiple times
        temp.pop_back(); // pop the picked element as its work is done
    }

    // non pick
    printCombination(i + 1, arr, n, target, temp, res); // just incrementing the index without picking any element
}

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here

    vector<int> arr = {1, 4, 5};
    int target = 5;

    vector<int> temp;
    vector<vector<int>> res;

    printCombination(0, arr, arr.size(), target, temp, res);

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