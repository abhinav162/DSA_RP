#include <bits/stdc++.h>
using namespace std;

int k;

void printSubset(int index, vector<int> &resSubset, int sum, vector<int> arr, int n)
{
    if (index == n)
    {
        if (sum % k == 0)
        {
            for (auto it : resSubset)
            {
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }

    // picking element at current idex for our subset (picked condition)
    resSubset.push_back(arr[index]);
    printSubset(index + 1, resSubset, sum + arr[index], arr, n);

    // removing the earlier picked element (not picked condition)
    resSubset.pop_back();
    printSubset(index + 1, resSubset, sum, arr, n);
}

int main()
{
// input output for files
#define TxtIO
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // start code here

    vector<int> arr = {1, 3, 2};
    vector<int> resSubset;
    int sum = 0;
    k = 3;
    printSubset(0, resSubset, sum, arr, arr.size());
    return 0;
}