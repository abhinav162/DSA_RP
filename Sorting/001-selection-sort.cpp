#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &arr)
{
    /*
    - Take the minimum element and swap it with the first index element of the array. then increment the first index.
    */

    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minNumIndex = i; // store index of minimum number b/w i -> n-1

        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[minNumIndex])
            {
                minNumIndex = j;
            }
        }
        swap(arr[i], arr[minNumIndex]);
    }
}

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    vector<int> arr = {5, 3, 6, 7, 2, 8, 0, 2};

    selectionSort(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}