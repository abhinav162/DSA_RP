#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n)
{
    // Write your code here.
    sort(arr.begin(), arr.end());
    int maxL = 0;
    int length = 1;

    map<int, int> m;

    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }

    for (auto it = m.begin(); it != std::prev(m.end()); it++)
    {
        if (it->first == std::next(it)->first - 1)
        {
            length++;
        }
        else
        {
            if (length > maxL)
                maxL = length;
            length = 1;
        }
    }

    // Check the length after the loop for the last element
    if (length > maxL)
        maxL = length;

    return maxL;
}

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here

    vector<int> arr = {100, 100, 100, 100, 99, 101, 101, 101, 101, 101};

    cout << lengthOfLongestConsecutiveSequence(arr, arr.size());

    return 0;
}