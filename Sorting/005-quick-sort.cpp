#include <bits/stdc++.h>
using namespace std;

/*
Approach :
    1. Take first element as pivot
    2. Take two pointers i and j
    3. i will start from left and j will start from right
    4. i will find element greater than pivot and j will find element smaller than pivot
    5. if i and j are not crossed then swap them
    6. repeat 4 and 5 until i and j are crossed
    7. swap pivot with j as j is the correct position of pivot
    8. now pivot is at correct position, so sort left and right part of pivot
    9. repeat 1 to 8 until array is sorted, i.e. while left < right
*/

int partitionIndex(vector<int> &arr, int left, int right)
{
    int pivot = arr[left];
    int i = left;
    int j = right;

    while (i < j)
    {
        while (arr[i] <= pivot && i <= right - 1) // findig element greater than pivot from left
        {
            i++;
        }

        while (arr[j] > pivot && j > left) // finding element smaller than or equal pivot from right
        {
            j--;
        }

        if (i < j) // if i and j are not crossed then swap them as they are not in correct position
        {
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[left], arr[j]); // swap pivot with j as j is the correct position of pivot

    return j; // return j as it is the correct position of pivot
}

void quickSort(vector<int> &arr, int left, int right)
{
    if (left > right)
    {
        return;
    }

    if (left < right)
    {
        int pIndex = partitionIndex(arr, left, right); // get partition index

        quickSort(arr, left, pIndex - 1);  // sort left part
        quickSort(arr, pIndex + 1, right); // sort right part
    }
}

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    vector<int> arr = {4, 2, 5, 6, 4, 7, 4};

    quickSort(arr, 0, arr.size() - 1);

    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}