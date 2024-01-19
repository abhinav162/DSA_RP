#include <bits/stdc++.h>
using namespace std;
bool checkPalindrome(string s1, string s2)
{
    string s = s1 + s2;
    int l = 0;
    int r = s.size() - 1;

    while (l < r)
    {
        if (s[l] != s[r])
            return false;
        l++;
        r--;
    }

    return true;
}

int main() 
{ 
    // input output for files
    freopen("../input.txt","r",stdin); 
    freopen("../output.txt","w",stdout);

    //start code here
    vector<string> words = {"a",""};


    // brute force
    vector<vector<int>> ans;

    for(int i = 0; i < words.size(); i++)
    {
        for(int j = 0; j < words.size(); j++)
        {
            if(i != j)
            {
                if(checkPalindrome(words[i], words[j]))
                {
                    ans.push_back({i, j});
                }
            }
        }
    }

    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }

    // optimal approach
    return 0 ; 
}