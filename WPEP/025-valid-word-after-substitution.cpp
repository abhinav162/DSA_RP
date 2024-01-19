/*
Approach - Using Stack -
    1 - create a stack
    2 - iterate over the string
        2.1 - if s[i] == 'a' || s[i] == 'b' then push s[i] to stack
        2.2 - if s[i] == 'c' then check if stack is not empty and top element of stack is equal to 'b' then pop top element of stack and check if stack is not empty and top element of stack is equal to 'a' then pop top element of stack else return false
    3 - return true if stack is empty else return false

    Time Complexity - O(n)
    Space Complexity - O(n)
*/

#include <bits/stdc++.h>
using namespace std;
bool isValid(string s)
{
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'a' || s[i] == 'b')
        {
            st.push(s[i]);
        }

        if (s[i] == 'c')
        {
            if (!st.empty() && st.top() == 'b')
            {
                st.pop();
                if (!st.empty() && st.top() == 'a')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }

    return st.empty();
}

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    string s = "aabcbc";

    cout << isValid(s);

    return 0;
}