/*
Print all subsets of a given set.

Input: {1, 3, 2}
Output: {}, {1}, {3}, {2}, {1, 3}, {1, 2}, {3, 2}, {1, 3, 2}

Input: {1}
Output: {}, {1}

Approach :
    1. We have two choices for each element in the array, either we can pick it or we can leave it.
    2. If we pick it, we add it to our subset and move to the next index.
    3. If we leave it, we move to the next index.
    4. We do this recursively for all the elements in the array.
    5. We print the subset when we reach the end of the array, ie. index == n.
*/

#include <bits/stdc++.h>
using namespace std;

void printSubset(int index, vector<int> &resSubset, vector<int> arr, int n)
{
    if (index == n)
    {
        for(auto it : resSubset)
        {
            cout << it << " ";
        }
        cout << endl;
        return;
    }

    // picking element at current idex for our subset (picked condition)
    resSubset.push_back(arr[index]);
    printSubset(index + 1, resSubset, arr, n);

    // removing the earlier picked element (not picked condition)
    resSubset.pop_back();
    printSubset(index + 1, resSubset, arr, n);
}

int main()
{
// input output for files
#define TxtIO
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here

    vector<int> arr = {8,6,5};
    vector<int> resSubset;
    printSubset(0, resSubset, arr, arr.size());

    return 0;
}