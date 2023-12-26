#include <bits/stdc++.h>
using namespace std;

bool isThere(vector<int> &arr, int target, int n, int i, vector<int> resArray)
{
    if (i > n)
    {
        return 0;
    }

    if (resArray.size() == 4)
    {
        return accumulate(resArray.begin(), resArray.end(), 0) == target;
    }

    resArray.push_back(arr[i]);
    bool x = isThere(arr, target, n, i + 1, resArray);

    resArray.pop_back();
    bool y = isThere(arr, target, n, i + 1, resArray);

    return x || y;
}

string fourSum(vector<int> arr, int target, int n)
{
    // Write your code here.
    if (n < 4)
    {
        return "No";
    }

    // Sort the array
    sort(arr.begin(), arr.end());

    // two fixed pointer approach
    for (int i = 0; i < n; i++)
    {
        int target2 = target - arr[i];
        for (int j = i + 1; j < n; j++)
        {
            int target3 = target2 - arr[j]; // now we have to look for two elements whose sum is target3
            int start = j + 1;
            int end = n - 1;

            while (start < end)
            {
                int rSum = arr[start] + arr[end];

                if (target3 < rSum)
                {
                    end--;
                }
                else if (target3 > rSum)
                {
                    start++;
                }
                else
                {
                    return "Yes";
                }
            }
        }
    }

    return "No";

    // Recursive approach (TLE)
    // vector<int> resArray;
    // return isThere(arr, target, n, 0, resArray) ? "Yes" : "No";
}

#include <bits/stdc++.h>
using namespace std;
int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    vector<int> arr = {2, 3, 5, 4, 6, 7, 4, 7, 8, 5};
    int target = 15;

    cout << fourSum(arr, target, arr.size());

    return 0;
}