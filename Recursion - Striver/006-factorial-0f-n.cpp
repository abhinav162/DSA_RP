#include <bits/stdc++.h>
using namespace std;

int fact(int n)
{
    if (n == 0)
    {
        return 1;
    }

    return n * fact(n - 1);
}

int main()
{
// input output for files
#define TxtIO
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n = 5;
    // start code here
    cout << fact(n);
    return 0;
}