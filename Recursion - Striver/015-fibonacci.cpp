#include <bits/stdc++.h>
using namespace std;
int fibonacciOptimized(int n)
{
    const int mod = 1e9 + 7;
    if (n <= 1)
        return n;

    int a = 0;
    int b = 1;
    int c;

    for (int i = 2; i <= n; i++)
    {
        c = (a + b) % mod;
        a = b;
        b = c;
    }

    return c;
}

int fibonacci(int n)
{
    if (n <= 1)
        return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}
int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    int n = 5;
    cout << fibonacci(n);
    return 0;
}