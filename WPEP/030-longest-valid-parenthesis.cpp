#include <bits/stdc++.h>
using namespace std;
int longestValidParentheses(string s)
{
    int n = s.size();
    stack<char> st;
    st.push(-1);
    int maxCnt = 0;

    int i = 0;
    while (i < n)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else if (s[i] == ')')
        {
            st.pop();
            if (st.empty())
            {
                st.push(i);
            }
            else
            {
                maxCnt = max(maxCnt, i - st.top());
            }
        }
        i++;
    }

    return maxCnt;
}

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    string s = "()((())()";
    cout << longestValidParentheses(s);

    return 0;
}