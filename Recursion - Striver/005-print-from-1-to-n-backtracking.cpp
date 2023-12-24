/*
Back Tracking -
*/

#include <bits/stdc++.h>
using namespace std;

void print1toN(int n)
{
    if (n <= 0)
        return;

    print1toN(n - 1);
    cout << n << " ";

    return;
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
    print1toN(n);

    return 0;
}