#include <bits/stdc++.h>
using namespace std;

void transposeMatrix(vector<vector<int>> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr[i].size(); j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }
}

void flipMatrix(vector<vector<int>> &arr)
{
    for (int i = 0; i < arr.size() / 2; ++i)
    {
        swap(arr[i], arr[arr.size() - i - 1]);
    }
}

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    transposeMatrix(arr);
    flipMatrix(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}