#include <bits/stdc++.h>
using namespace std;

int findRes(int n, int k)
{
    if (k == 0)
        return 1;

    if (k == 1)
        return n;

    int val = findRes(n, k / 2);

    if (k % 2 == 0) // if k is even
        return val * val;

    // if k is odd
    return val * val * n;
}

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    int n = 2;
    int k = -6;

    int res = findRes(n, k);

    if (k < 0)
        cout << 1.0 / res;
    else
        cout << res;

    return 0;
}