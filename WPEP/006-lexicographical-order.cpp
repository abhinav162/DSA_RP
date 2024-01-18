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

void printLexico2(int idx, int n, vector<char> &words, string res)
{
    if(idx == n)
    {
        cout << res << endl;
        return;
    }

    for(int i = idx; i < 2; i++)
    {
        
    }

}

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    vector<char> words = {'a', 'c', 'b'};
    int n = 3;
    sort(words.begin(), words.end());
    printInLexico(n, 0, words, "");

    return 0;
}