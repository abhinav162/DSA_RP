#include <bits/stdc++.h>
using namespace std;

void printInLexico(int n, int i, vector<char> &words, string res)
{
    if (i == n)
    {
        return;
    }

    res += words[i];
    cout << res << endl;
    printInLexico(n, i + 1, words, res);

    res.pop_back();
    printInLexico(n, i + 1, words, res);
}

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    vector<char> words = {'a', 'b', 'c'};
    int n = 3;

    printInLexico(n, 0, words, "");

    return 0;
}