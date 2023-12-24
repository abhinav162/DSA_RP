#include <bits/stdc++.h>
using namespace std;

int sumTillN(int n)
{
    if (n < 1)
    {
        return 0;
    }

    return n + sumTillN(n - 1);
}

int main()
{
// input output for files
#define TxtIO
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // start code here
    int n;
    cin >> n;

    cout << sumTillN(n);
    return 0;
}