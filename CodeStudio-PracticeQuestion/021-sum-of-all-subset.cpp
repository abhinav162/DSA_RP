#include <bits/stdc++.h>
using namespace std;

void findSums(vector<int> &arr, int i, int n, int sum, vector<int> &res)
{
    if(i == n)
    {
        res.push_back(sum);
        return;
    }

    findSums(arr, i + 1, n, sum + arr[i], res);
    findSums(arr, i + 1, n, sum, res);
}

int main() 
{ 
    // input output for files
    freopen("../input.txt","r",stdin); 
    freopen("../output.txt","w",stdout);

    //start code here
    vector<int> arr = {1,2,3};
    int sum = 0;
    vector<int> res;

    findSums(arr, 0, arr.size(), sum, res);

    sort(res.begin(), res.end());

    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0 ; 
}