#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void largestRectangle(vector<int> &h, int &maximaRec)
    {
        int n = h.size();
        vector<int> prevLess(n), nextLess(n);
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && h[st.top()] >= h[i])
            {
                st.pop();
            }

            if (st.empty())
            {
                prevLess[i] = -1;
            }
            else
            {
                prevLess[i] = st.top();
            }

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && h[st.top()] >= h[i])
            {
                st.pop();
            }

            if (st.empty())
            {
                nextLess[i] = n;
            }
            else
            {
                nextLess[i] = st.top();
            }

            st.push(i);
        }

        int maxArea = 0;

        for (int i = 0; i < n; i++)
        {
            int l = h[i];
            int w = (nextLess[i] - prevLess[i] - 1);
            maxArea = max(maxArea, l * w);
        }

        maximaRec = max(maximaRec, maxArea);
    }

    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.size() == 0)
            return 0;

        // convert char to int
        vector<vector<int>> h;
        for (int i = 0; i < matrix.size(); i++)
        {
            vector<int> temp;
            for (int j = 0; j < matrix[i].size(); j++)
            {
                temp.push_back(matrix[i][j] - '0');
            }
            h.push_back(temp);
        }

        int maximalRec = 0;
        largestRectangle(h[0], maximalRec);

        for (int i = 1; i < h.size(); i++)
        {
            for (int j = 0; j < h[i].size(); j++)
            {
                if (h[i][j] == 1)
                {
                    h[i][j] = h[i - 1][j] + 1;
                }
                else
                {
                    h[i][j] = 0;
                }
            }

            largestRectangle(h[i], maximalRec);
        }

        return maximalRec;
    }
};

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                   {'1', '0', '1', '1', '1'},
                                   {'1', '1', '1', '1', '1'},
                                   {'1', '0', '0', '1', '0'}};

    Solution *sol = new Solution();
    cout << sol->maximalRectangle(matrix);
    return 0;
}