#include <bits/stdc++.h>
using namespace std;

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    int maxR = -1;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        int x = accumulate(matrix[i].begin(), matrix[i].end(), 0);
        if (x > sum)
        {
            maxR = i;
            sum = x;
        }
    }

    return maxR;
}

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    vector<vector<int>> matrix = {{0, 1, 1, 1},
                                  {0, 0, 1, 1},
                                  {1, 1, 1, 1},
                                  {0, 0, 0, 0}};
    int n = matrix.size();
    int m = matrix[0].size();

    cout << rowWithMax1s(matrix, n, m);

    return 0;
}