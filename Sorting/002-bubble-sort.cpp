#include <bits/stdc++.h>
using namespace std;

/*
    - Put the maximum element at the last index of the array using adjacent swaps and then decrement the last index.
    - Optimization -- If no swap is done then the array is already sorted so break the loop, so that outer loop doesn't have to check for rest of the elements. (it will make the time complexity of the best case O(n))
*/
void bubbleSort(vector<int> &arr)
{
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

void bubbleSortRecursive(vector<int> &arr, int n)
{
    if(n == 1)
    {
        return;
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }

    bubbleSortRecursive(arr, n - 1);
}

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    vector<int> arr = {5, 3, 6, 7, 2, 8, 0, 2};

    // bubbleSort(arr);
    bubbleSortRecursive(arr, arr.size());

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}