#include <bits/stdc++.h>
using namespace std;

void printName(int i, int n)
{
    if (i > n)
    {
        return;
    }

    cout << "Abhinav " << i << endl;
    printName(i + 1, n);
}

int main()
{
// input output for files
#define TxtIO
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // start code here
    printName(1, 5);
    return 0;
}