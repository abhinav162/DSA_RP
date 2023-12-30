#include <bits/stdc++.h>
using namespace std;

int k;

void printSubset(int index, vector<int> &resSubset, int sum, vector<int> arr, int n)
{
    if (index == n)
    {
        if (sum % k == 0)
        {
            for (auto it : resSubset)
            {
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }

    // picking element at current idex for our subset (picked condition)
    resSubset.push_back(arr[index]);
    printSubset(index + 1, resSubset, sum + arr[index], arr, n);

    // removing the earlier picked element (not picked condition)
    resSubset.pop_back();
    printSubset(index + 1, resSubset, sum, arr, n);
}

/*
if you want to store the values or want to avoid writing print logic inside recursive function then carry a 2D matrix with call by reference method and do push_back
*/
void storeSubset(int index, vector<int> &arr, int n, int k, int sum, vector<int> &subSet, vector<vector<int>> &finalMat)
{
    if (index == n)
    {
        if (k == sum)
        {
            finalMat.push_back(subSet);
        }
        return;
    }

    subSet.push_back(arr[index]);
    storeSubset(index + 1, arr, n, k, sum + arr[index], subSet, finalMat);
    subSet.pop_back();

    storeSubset(index + 1, arr, n, k, sum, subSet, finalMat);
}

/*
If only one subset is needed then just return a boolean true whenever a subset is found and check if true is returned then return true in main recursion otherwise return false
*/
bool printOnlyOneSubset(int index, vector<int> &arr, int n, int k, int sum, vector<int> &subSet, vector<vector<int>> &finalMat)
{
    if (index == n)
    {
        if (k == sum)
        {
            finalMat.push_back(subSet);
            return true; // subset found so return true
        }
        else
            return false;
    }

    subSet.push_back(arr[index]);
    if (printOnlyOneSubset(index + 1, arr, n, k, sum + arr[index], subSet, finalMat) == true) // checking if subset is found or not
    {
        return true;
    }

    subSet.pop_back();

    if (printOnlyOneSubset(index + 1, arr, n, k, sum, subSet, finalMat) == true) // checking if subset is found or not
    {
        return true;
    }

    return false;
}

int main()
{
    // freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here

    vector<int> arr = {1, 3, 2};
    vector<int> resSubset;
    int sum = 0;
    int k = 3;

    // printSubset(0, resSubset, sum, arr, arr.size());

    vector<vector<int>> finalResMat;
    // storeSubset(0, arr, arr.size(), k, sum, resSubset, finalResMat);

    printOnlyOneSubset(0, arr, arr.size(), k, sum, resSubset, finalResMat);

    for (int i = 0; i < finalResMat.size(); i++)
    {
        for (int j = 0; j < finalResMat[i].size(); j++)
        {
            cout << finalResMat[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}