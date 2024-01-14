#include <bits/stdc++.h>
using namespace std;

int binarySearchIt(vector<int> &arr, int target)
{
    int start = 0;
    int end = arr.size() - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
        {
            end = mid - 1;
        }
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
    }

    return -1;
}

int binarySearchRecu(vector<int> &arr, int target, int start, int end)
{
    if (start > end)
    {
        return -1;
    }

    int mid = (start + end) / 2;

    if (arr[mid] == target)
    {
        return mid;
    }
    else if (arr[mid] > target)
    {
        return binarySearchRecu(arr, target, start, mid - 1);
    }
    else
    {
        return binarySearchRecu(arr, target, mid + 1, end);
    }
}

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 5;

    cout << binarySearchIt(arr, target) << endl;
    cout << binarySearchRecu(arr, target, 0, arr.size() - 1);
    return 0;
}