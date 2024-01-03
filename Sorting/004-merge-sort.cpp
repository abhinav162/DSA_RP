/*
Approach : Time - O(nlogn)
    1. Divide the array into two halves
    2. Sort the left half
    3. Sort the right half
    4. Merge both halves

    Merge function:
        1. Create a temp array
        2. Take two pointers left and right
        3. Compare the elements at left and right pointers
        4. Push the smaller element to temp array
        5. Increment the pointer of the smaller element
        6. Repeat steps 3-5 until any one of the pointer reaches the end
        7. Push the remaining elements to temp array
        8. Copy the temp array to original array

    Merge Sort function:
        1. If low == high then return
        2. Find mid
        3. Sort left half
        4. Sort right half
        5. Merge both halves    
*/

#include <bits/stdc++.h>
using namespace std;
void merge(int arr[], int low, int mid, int high)
{
    vector<int> temp;

    int left = low;
    int right = mid + 1;

    // merge two sorted arrays in temp array
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if any element is left in left array then push it to temp
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    // if any element is left in right array then push it to temp
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // copy temp array to original array
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void mergeSort(int arr[], int low, int high)
{
    if (low == high)
    {
        return;
    }

    int mid = (low + high) / 2;

    mergeSort(arr, low, mid);      // sort left half of array
    mergeSort(arr, mid + 1, high); // sort right half of array
    merge(arr, low, mid, high);    // merge both halves
}

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    vector<int> arr = {2, 13, 4, 1, 3, 6, 28};

    mergeSort(arr.data(), 0, arr.size() - 1);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}