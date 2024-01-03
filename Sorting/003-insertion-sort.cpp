#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &arr)
{
    /*
    - pickup an element and insert it in the correct position in the array.
    */

    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }
}

void insertionSortRecuesive(vector<int> &arr, int i, int n)
{
    if (i == n)
    {
        return;
    }

    int j = i;
    while (j > 0 && arr[j] < arr[j - 1])
    {
        swap(arr[j], arr[j - 1]);
        j--;
    }

    insertionSortRecuesive(arr, i + 1, n);
}

void insertionSortRecuesive2(vector<int> &arr, int i, int j, int n)
{
    if (i == n)
    {
        return;
    }

    if (j > 0 && arr[j - 1] > arr[j])
    {
        swap(arr[j], arr[j - 1]);
        insertionSortRecuesive2(arr, i, j - 1, n);
    }
    else
    {
        insertionSortRecuesive2(arr, i + 1, i + 1, n);
    }
}

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    vector<int> arr = {5, 3, 6, 7, 2, 8, 0, 2};

    // insertionSort(arr);
    // insertionSortRecuesive(arr, 0, arr.size());
    insertionSortRecuesive2(arr, 0, 0, arr.size());

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}