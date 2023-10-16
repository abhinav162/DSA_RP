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
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout);

    //start code here
    string s = "abba";
    
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