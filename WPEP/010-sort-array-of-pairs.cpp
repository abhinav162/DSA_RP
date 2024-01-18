#include <bits/stdc++.h>
using namespace std;

bool comparatorOnFirst(pair<int,int> &a, pair<int,int> &b)
{
    return a.first < b.first;
}

bool comparatorOnSec(pair<int,int> &a, pair<int,int> &b)
{
    return a.second < b.second;
}

int main() 
{ 
    // input output for files
    freopen("../input.txt","r",stdin); 
    freopen("../output.txt","w",stdout);

    //start code here
    vector<pair<int, int>> arr = {
        {1,2},
        {3,6},
        {6,4}
    };

    // sort(arr.begin(), arr.end(), comparatorOnFirst);
    sort(arr.begin(), arr.end(), comparatorOnSec);

    for(auto i : arr)
    {
        cout << i.first << " " << i.second << endl;
    }
    return 0 ; 
}