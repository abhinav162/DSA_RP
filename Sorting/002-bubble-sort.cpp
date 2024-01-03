#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr)
{
    /*
    - Put the maximum element at the last index of the array using adjacent swaps and then decrement the last index.

    - Optimization -- If no swap is done then the array is already sorted so break the loop, so that outer loop doesn't have to check for rest of the elements. (it will make the time complexity of the best case O(n))
    */

    int n = arr.size();
    for (int i = n - 1; i > 0; i--)
    {
        int didSwap = 0;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                didSwap = 1;
            }
        }

        if (didSwap == 0) // if no swap is done then the array is already sorted so break the loop
        {
            break;
        }
    }
}

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    vector<int> arr = {5, 3, 6, 7, 2, 8, 0, 2};

    bubbleSort(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}