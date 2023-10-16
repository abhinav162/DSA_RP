#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int n, int i)
{
    if (i >= n / 2)
    {
        return true;
    }

    if (s[i] == s[n - i - 1])
    {
        return isPalindrome(s, n, i + 1);
    }

    return false;
}

string longestPalindromicSubstring(string s)
{
    int n = s.length();
    int maxLen = 0;
    int start = 0;
    int end = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (isPalindrome(s, j - i + 1, i))
            {
                if (j - i + 1 > maxLen)
                {
                    maxLen = j - i + 1;
                    start = i;
                    end = j;
                }
            }
        }
    }

    return s.substr(start, end - start + 1);
}

int main()
{
// input output for files
#define TxtIO
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // start code here
    string s = "abbacaf";

    cout << longestPalindromicSubstring(s);

    return 0;
}