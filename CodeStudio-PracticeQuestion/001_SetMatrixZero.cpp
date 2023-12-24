#include <bits/stdc++.h>
using namespace std;
int main()
{
// input output for files
#define TxtIO
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // start code here
    vector<vector<int>> matrix = {{7, 19, 3}, {4, 21, 0}};

    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> rowIndex;
    vector<int> colIndex;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                rowIndex.push_back(i);
                colIndex.push_back(j);
            }
        }
    }

    while (rowIndex.size())
    {
        int i = rowIndex[rowIndex.size() - 1];
        int j = colIndex[colIndex.size() - 1];

        for(int x = 0; x < m; x++)
        {
            matrix[i][x] = 0;
        }

        for(int y = 0; y < n; y++)
        {
            matrix[y][j] = 0;
        }

        rowIndex.pop_back();
        colIndex.pop_back();
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}