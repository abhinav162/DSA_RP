// Approach :
/*
    1. Create a stack
    2. Iterate over the string
    3. If the current character is opening bracket then push it into the stack
    4. If the current character is closing bracket then check if the stack is empty or not
    5. If the stack is empty then return false
    6. If the stack is not empty then check if the top of the stack is the opening bracket of the current character
    7. If the top of the stack is the opening bracket of the current character then pop the top of the stack
    8. If the top of the stack is not the opening bracket of the current character then return false
    9. After iterating over the string, if the stack is empty then return true else return false
*/

#include <bits/stdc++.h>
using namespace std;
bool isValid(string s)
{
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            st.push(s[i]);
        }
        else if (!st.empty() && s[i] == ')' && st.top() == '(')
        {
            st.pop();
        }
        else if (!st.empty() && s[i] == ']' && st.top() == '[')
        {
            st.pop();
        }
        else if (!st.empty() && s[i] == '}' && st.top() == '{')
        {
            st.pop();
        }
        else
        {
            return false;
        }
    }

    if (st.empty())
    {
        return true;
    }
    return false;
}

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here

    string s = "]";
    cout << isValid(s);
    return 0;
}