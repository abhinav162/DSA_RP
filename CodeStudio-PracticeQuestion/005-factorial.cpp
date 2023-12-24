#include <bits/stdc++.h>
using namespace std;

int factorial(int n) // functional way
{
    if (n < 1)
    {
        return 1;
    }

    return n * factorial(n - 1);
}

int factorial2(int n, int prod) // parameterised way
{
    if (n < 1)
    {
        return prod;
    }

    return factorial2(n - 1, prod * n);
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
    cout << factorial(n);
    cout << endl;
    int prod = 1;
    cout << factorial2(n, prod);
    return 0;
}