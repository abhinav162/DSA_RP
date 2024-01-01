#include <bits/stdc++.h>
using namespace std;
bool allCharSame(string s)
{
    char c = s[0];
    for (auto ch : s)
    {
        if (ch != c)
            return false;
    }

    return true;
}
int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    string s = "cccerrrecdcdccedecdcccddeeeddcdcddedccdceeedccecde";
    map<string, int> mp;
    // map<string, int> fm;

    for (int i = 0; i < s.length(); i++)
    {
        for (int j = i + 1; j <= s.length(); j++)
        {
            string sub = s.substr(i, j - i);
            mp[sub]++;

            //// for testing 
            // if (mp[sub] >= 3)
            // {
            //     if (allCharSame(sub))
            //         fm[sub] = mp[sub];
            // }
        }
    }

    int longest = -1;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        // cout << it->first << " " << it->second << endl;
        if (it->second >= 3)
        {
            if (allCharSame(it->first))
            {
                int l = (it->first).length();
                longest = max(longest, l);
            }
        }
    }

    // for (auto it = fm.begin(); it != fm.end(); it++)
    // {
    //     cout << it->first << " " << it->second << endl;
    // }

    cout << longest;
    return 0;
}