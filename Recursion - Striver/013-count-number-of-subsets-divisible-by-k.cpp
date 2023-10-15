/*
Approach : 
    1. We have two choices for each element in the array, either we can pick it or we can leave it.
    2. If we pick it, we add it to our subset and move to the next index.
    3. If we leave it, we move to the next index.
    4. We do this recursively for all the elements in the array.
    5. Wehen we reach index == n we check if the sum of the subset is divisible by k and sum is not equal to 0(empty set condition), if yes return 1 else return 0. (base condition).
    6. We storet he result of both the recursive calls in variable l and r and return sum of l and r.
*/


#include <bits/stdc++.h>
using namespace std;

int k;

int printSubset(int index, int sum, vector<int> arr, int n)
{
    if (index == n)
    {
        if (sum % k == 0 && sum != 0)
        {
            return 1;
        }
        return 0;
    }

    // picking element at current idex for our subset (picked condition)
    int l = printSubset(index + 1, sum + arr[index], arr, n);

    // removing the earlier picked element (not picked condition)
    int r = printSubset(index + 1, sum, arr, n);

    return l+r;
}

int main()
{
// input output for files
#define TxtIO
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // start code here

    vector<int> arr = {1, 3, 2};
    int sum = 0;
    k = 3;
    int res = printSubset(0, sum, arr, arr.size());

    cout << res;
    return 0;
}