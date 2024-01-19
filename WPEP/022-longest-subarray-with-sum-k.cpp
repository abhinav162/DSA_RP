#include <bits/stdc++.h>
using namespace std;
int main() 
{ 
    // input output for files
    freopen("../input.txt","r",stdin); 
    freopen("../output.txt","w",stdout);

    //start code here
    vector<int> arr = {-1, 2, 3};
    int k = 6;

    unordered_map<int, int> mp;
    vector<long long> prefix;

    for(int i = 0; i < arr.size(); i++)
    {
        prefix.push_back(arr[i]);
        if(i != 0)
        {
            prefix[i] += prefix[i - 1];
        }
    }

    int ans = 0;
    mp[0] = -1;

    for(int j = 0; j < prefix.size(); j++)
    {
        if(mp.find(prefix[j] - k) != mp.end())
        {
            ans = max(ans, j - mp[prefix[j] - k]);
        }
        if(mp.find(prefix[j]) == mp.end())
        {
            mp[prefix[j]] = j;
        }
    }

    cout << ans;
    return 0 ; 
}