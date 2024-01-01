#include <bits/stdc++.h>
using namespace std;

int LongestSubsetWithZeroSum(vector<int> arr)
{
    int Max = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        int length = 1;
        int sum = arr[i];

        if (sum == 0)
        {
            Max = max(Max, length);
        }

        for (int j = i + 1; j < arr.size(); j++)
        {
            sum += arr[j];
            length++;

            if (sum == 0)
            {
                Max = max(Max, length);
            }
        }
    }

    return Max;
}

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here

    vector<int> arr = {1, 3, -1, 4, -4};
    cout << LongestSubsetWithZeroSum(arr) << endl;
    return 0;
}