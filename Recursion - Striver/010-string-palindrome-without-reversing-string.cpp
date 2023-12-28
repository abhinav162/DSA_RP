/*
Approach : 
    1. We compare the first and last character of the string.
    2. If they are equal, we move to the next character.
    3. If they are not equal, we return false.
    4. We do this recursively for all the characters in the string.
    5. If we reach the end of the string, we return true.
*/

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int n, int i)
{
    if(i >= n/2)
    {
        return true;
    }

    if(s[i] == s[n-i-1])
    {
        return isPalindrome(s,n,i+1);
    }

    return false;
}
int main()
{
    // input output for files
    #define TxtIO
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);

    //start code here

    string s = "ababa";
    
    if(isPalindrome(s,s.length(),0))
    {
        cout << "Palindrome";
    }
    else
    {
        cout << "Not Palindrome";
    }

    return 0 ;
}