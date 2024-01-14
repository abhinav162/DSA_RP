#include <bits/stdc++.h>
using namespace std;
int subSetS(int i, vector<int> &arr, int n, int sum, int k)
{
    if (i == n)
    {
        if(sum == k)
        {
            return 1;
        }
        return 0;
    }

    int x = subSetS(i + 1, arr, n, sum + arr[i], k);
    int y = subSetS(i + 1, arr, n, sum, k);

    return x + y;
}

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 6;
    int sum = 0;
    cout << subSetS(0, arr, arr.size(), sum, k);
    return 0;
}