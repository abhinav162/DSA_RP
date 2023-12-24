// FILEPATH: /workspaces/DSA_RP/Recursion - Striver/009-string-is-palindrome-or-not.cpp
#include <bits/stdc++.h>
using namespace std;

void reverseStr(string &s, int n, int i)
{
    if (i >= n / 2)
    {
        return;
    }

    char temp = s[i];
    s[i] = s[n - i - 1];
    s[n - i - 1] = temp;

    reverseStr(s, n, i + 1);
}

bool isPalindrome(string s)
{
    string temp = s;
    reverseStr(temp, temp.length(), 0);

    if (temp == s)
    {
        return true;
    }
    return false;
}

int main()
{
// input output for files
#define TxtIO
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // start code here
    string s1 = "ababa";

    if (isPalindrome(s1))
    {
        cout << "Palindrome";
    }
    else
    {
        cout << "Not Palindrome";
    }
    return 0;
}