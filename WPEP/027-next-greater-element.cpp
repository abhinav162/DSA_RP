/*
    Approach -
        1 - create a stack
        2 - iterate over the array from n-1 to 0
            2.1 - if stack is empty then push -1 to ans
            2.2 - if stack is not empty and top element of stack is greater than arr[i] then push top element of stack to ans
            2.3 - if stack is not empty and top element of stack is less than or equal to arr[i] then pop top element of stack until stack is empty or top element of stack is greater than arr[i] then push top element of stack to ans
        3 - reverse ans
        4 - return ans
*/

#include <bits/stdc++.h>
using namespace std;
vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    vector<long long> ans;
    stack<long long> s;

    for (int i = n - 1; i >= 0; i--)
    {
        if (s.empty())
        {
            ans.push_back(-1);
        }
        else if (!s.empty() && s.top() > arr[i])
        {
            ans.push_back(s.top());
        }
        else if (!s.empty() && s.top() <= arr[i])
        {
            while (!s.empty() && s.top() <= arr[i])
            {
                s.pop();
            }
            if (s.empty())
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(s.top());
            }
        }
        s.push(arr[i]);
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    // input output for filesṇ
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    vector<long long> arr = {1, 3, 2, 4};
    int n = arr.size();

    vector<long long> ans = nextLargerElement(arr, n);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}