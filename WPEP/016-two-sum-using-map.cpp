/*
    Two Sum Problem using Map
    
    Approach - O(n)
    1. create a map
    2. iterate over the array
    3. find the rem = target - arr[i] // this is the number we need to find in the map
    4. if the rem is present in the map then we have found the pair and we return the index of the rem and the current index
    5. else we add the arr[i] to the map with its index as value
*/

#include <bits/stdc++.h>
using namespace std;
int main() 
{ 
    // input output for files
    freopen("../input.txt","r",stdin); 
    freopen("../output.txt","w",stdout);

    //start code here
    vector<int> arr = {4,3,6,5,7,3,4};
    int target = 7;

    map<int, int> mp;

    vector<int> res(2, -1);

    for(int i = 0; i < arr.size(); i++)
    {
        int rem = target - arr[i];
        if(mp.find(rem) != mp.end())
        {
            res[0] = mp[rem];
            res[1] = i;
            break;
        }
        else
        {
            mp[arr[i]] = i;
        }
    }

    for(int i : res)
    {
        cout << i << " " ;
    }

    return 0 ; 
}