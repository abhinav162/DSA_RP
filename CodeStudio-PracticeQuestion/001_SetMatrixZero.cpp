#include <bits/stdc++.h>
using namespace std;
int main()
{
    /*
    Approach :
    - Take two vectors rowIndex and colIndex to store the index of the rows and columns which have 0.
    - Traverse the matrix and if you find 0 then push the index of that row and column in the respective vectors rowIndex and colIndex.
    - Now traverse the rowIndex and colIndex vectors and make the respective row and column 0.
    */

    // start code here
    vector<vector<int>> matrix = {{7, 19, 3}, {4, 21, 0}};

    int n = matrix.size();
    int m = matrix[0].size();

    vector<pair<int,int>> cord;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(matrix[i][j] == 0)
			{
				cord.push_back({i,j});
			}
		}
	}

    for(int i = 0; i < cord.size(); i++)
    {
        int x = cord[i].first;
        int y = cord[i].second;

        for(int j = 0; j < m; j++)
        {
            matrix[x][j] = 0;
        }

        for(int k = 0; k < n; k++)
        {
            matrix[k][y] = 0;
        }
    }

    // vector<int> rowIndex;
    // vector<int> colIndex;

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         if (matrix[i][j] == 0)
    //         {
    //             rowIndex.push_back(i);
    //             colIndex.push_back(j);
    //         }
    //     }
    // }
    

    // while (rowIndex.size())
    // {
    //     int i = rowIndex[rowIndex.size() - 1];
    //     int j = colIndex[colIndex.size() - 1];

    //     for(int x = 0; x < m; x++)
    //     {
    //         matrix[i][x] = 0;
    //     }

    //     for(int y = 0; y < n; y++)
    //     {
    //         matrix[y][j] = 0;
    //     }

    //     rowIndex.pop_back();
    //     colIndex.pop_back();
    // }

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