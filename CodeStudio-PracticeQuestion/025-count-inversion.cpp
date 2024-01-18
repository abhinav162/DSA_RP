#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>

int merge(long long *arr, int low, int mid, int high)
{
    int left = low;
    int right = mid + 1;

    vector<int> temp;

    int count = 0;
    while (left <= mid && right <= high)
    {
        if (arr[left] > arr[right])
        {
            count += mid - left + 1; // count inversions here only when arr[left] > arr[right] then all the elements from left to mid will be greater than arr[right]

            temp.push_back(arr[right]);
            right++;
        }
        else
        {
            temp.push_back(arr[left]);
            left++;
        }
    }

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

    return count;
}

int ms(long long *arr, int low, int high)
{
    int count = 0;
    if (low >= high)
    {
        return count;
    }


    int mid = (low + high) / 2;
    count += ms(arr, low, mid);
    count += ms(arr, mid + 1, high);
    count += merge(arr, low, mid, high);

    return count;
}

long long getInversions(long long *arr, int n)
{
    // Write your code here.
    int count = 0;

    //// O(n^2) solution brute force approach
    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = i+1; j < n; j++)
    //     {
    //         if(arr[i] > arr[j])
    //         {
    //             count++;
    //         }
    //     }
    // }

    //// O(nlogn) solution using merge sort approach
    count = ms(arr, 0, n - 1);  
    return count;
}

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here

    int n;
    cin >> n;

    long long *arr = new long long[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << getInversions(arr, n);

    return 0;
}