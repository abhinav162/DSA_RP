// sort 0 1 2

#include <bits/stdc++.h>
using namespace std;
int main()
{
// input output for files
#define TxtIO
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // start code here
    vector<int> arr = {0, 1, 2, 2, 1, 0};
    int n = arr.size();

    int low = 0, high = n - 1, i = 0;
    while (i <= high)
    {
        if (arr[i] == 0)
        {
            swap(arr[i], arr[low]);
            low++;
            i++;
        }
        else if (arr[i] == 2)
        {
            swap(arr[i], arr[high]);
            high--;
        }
        else
        {
            i++;
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}