#include <bits/stdc++.h>
using namespace std;

void generateCombinations(int idx, int n, vector<int> &arr, vector<int> comb, int j)
{
    if (idx == n)
    {
        for (auto e : comb)
        {
            cout << e << " ";
        }
        cout << endl;
        return;
    }

    if (j < 2)
    {
        comb.push_back(arr[idx]);
        generateCombinations(idx, n, arr, comb, j + 1);
        comb.pop_back();
    }

    generateCombinations(idx + 1, n, arr, comb, 0);
}

void generateCombinations2(int idx, int n, vector<int> &arr, vector<int> comb, int i)
{
    if (idx == n)
    {
        for (auto e : comb)
        {
            cout << e << " ";
        }
        cout << endl;
        return;
    }

    if(i == 2)
    {
        return;
    }

    for (i; i < 2; i++)
    {
        comb.push_back(arr[idx]);
        generateCombinations2(idx, n, arr, comb, i+1);
        comb.pop_back();
    }

    generateCombinations2(idx + 1, n, arr, comb, i);
}

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    vector<int> arr = {1, 2};
    vector<int> comb;
    generateCombinations(0, arr.size(), arr, comb, 0);
    // generateCombinations2(0, arr.size(), arr, comb, 0);
    return 0;
}