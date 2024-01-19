#include <bits/stdc++.h>
using namespace std;

// NOT WORKING FOR ALL TEST CASES
vector<int> nextGreaterElements(vector<int> &nums)
{
    vector<int> ans;
    stack<int> s;
    stack<int> s2;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        s.push(nums[i]);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (nums[i] < s.top())
        {
            ans.push_back(s.top());
        }
        else if (!s.empty())
        {
            while (!s.empty() && s.top() <= nums[i])
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
            // s2.push(nums[i]);
        }
        else if (!s2.empty())
        {
            while (!s2.empty() && s2.top() <= nums[i])
            {
                s2.pop();
            }
            if (s2.empty())
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(s2.top());
            }
        }
        else
        {
            ans.push_back(-1);
        }
        s.push(nums[i]);
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    vector<int> nums = {1, 2, 1};
    vector<int> ans = nextGreaterElements(nums);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}