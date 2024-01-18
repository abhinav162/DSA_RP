#include <bits/stdc++.h>
using namespace std;
int main() 
{ 
    // input output for files
    freopen("../input.txt","r",stdin); 
    freopen("../output.txt","w",stdout);

    //start code here
    vector<int> arr1 = {1,4,6,7};
    vector<int> arr2 = {2,3,5,8};

    vector<int> res;

    int i = 0;
    int j = 0;

    while(i < arr1.size() && j < arr2.size())
    {
        if(arr1[i] < arr2[j])
        {
            res.push_back(arr1[i]);
            i++;
        }
        else
        {
            res.push_back(arr2[j]);
            j++;
        }
    }

    while(i < arr1.size())
    {
        res.push_back(arr1[i]);
        i++;
    }

    while( j < arr2.size())
    {
        res.push_back(arr2[j]);
        j++;
    }

    for(int i : res)
    {
        cout << i << " " ;
    }
    return 0 ; 
}