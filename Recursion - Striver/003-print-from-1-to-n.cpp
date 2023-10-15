#include <bits/stdc++.h>
using namespace std;

void printN(int i, int n)
{
    if (i > n)
    {
        return;
    }

    cout << i << endl;

    printN(i + 1, n);
}

int main()
{
// input output for files
#define TxtIO
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // start code here
    printN(1, 10);
    return 0;
}