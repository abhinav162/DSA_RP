#include <bits/stdc++.h>
using namespace std;
int main() 
{ 
    // input output for files
    freopen("../input.txt","r",stdin); 
    freopen("../output.txt","w",stdout);

    //start code here
    vector<int> arr = {2, 3, 4, 2, 2, 4, 1, 6};
    int maxArea = 12;

    vector<vector<int>> res;

    int i = 0, j = arr.size()-1;
    sort(arr.begin(), arr.end());

    while(i < j)
    {
        int area = arr[i] * arr[j];
        if(area < maxArea)
        {
            res.push_back({arr[i], arr[j]});
            res.push_back({arr[j], arr[i]});
            i++;
        }
        else if(area > maxArea)
        {
            j--;
        }
        else
        {
            res.push_back({arr[i], arr[j]});
            i++;
            j--;
        }
    }

    for(auto i: res)
    {
        for(auto j: i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0 ; 
}