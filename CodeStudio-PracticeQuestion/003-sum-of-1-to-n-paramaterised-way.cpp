#include <bits/stdc++.h>
using namespace std;

int sumTillN(int n, int sum)
{
    if (n < 1)
    {
        return sum;
    }

    return sumTillN(n - 1, sum + n);
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

    int sum = 0;
    cout << sumTillN(n, sum);
    return 0;
}