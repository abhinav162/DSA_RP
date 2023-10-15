/*
    Reverse an array using recursion

    Approach: Swap first and last element and then call the function for the remaining array

    Time Complexity: O(n)
    Space Complexity: O(n) for recursive stack
*/

#include <bits/stdc++.h>
using namespace std;

void reverseArr(vector<int> &arr, int n, int i)
{
    if (i >= n / 2)
    {
        return;
    }

    int temp = arr[i];
    arr[i] = arr[n - i - 1];
    arr[n - i - 1] = temp;

    reverseArr(arr, n, i + 1);
}

int main()
{
// input output for files
#define TxtIO
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // start code here
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int n = arr.size();

    reverseArr(arr, n, 0);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}