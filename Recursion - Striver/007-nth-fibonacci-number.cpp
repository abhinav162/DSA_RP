#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n)
{
    if(n <= 1)
    {
        return n;
    }

    return fibonacci(n-2) + fibonacci(n-1);
}

int main()
{
    // input output for files
    #define TxtIO
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // start code here

    cout << fibonacci(5);

    return 0;
}