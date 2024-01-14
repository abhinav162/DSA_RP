#include <bits/stdc++.h>
using namespace std;

void printSubsLexicographically(int i, vector<int> &arr, int n, vector<int> temp)
{
    if (i == n)
    {
        return;
    }

    temp.push_back(arr[i]);
    for (auto i : temp)
    {
        cout << i << " ";
    }
    cout << endl;

    printSubsLexicographically(i + 1, arr, n, temp);
    temp.pop_back();
    printSubsLexicographically(i + 1, arr, n, temp);
}

void printSub(int i, vector<int> &arr, int n, vector<int> temp)
{
    if (i == n)
    {
        for (auto i : temp)
        {
            cout << i << " ";
        }
        cout << endl;
        return;
    }

    temp.push_back(arr[i]);
    printSub(i + 1, arr, n, temp);
    temp.pop_back();
    printSub(i + 1, arr, n, temp);
}

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    vector<int> arr = {1, 4, 3, 6, 8};
    int k = 2;
    vector<int> temp;

    // printSub(0, arr,arr.size(), temp);

    printSubsLexicographically(0, arr, arr.size(), temp);
    return 0;
}