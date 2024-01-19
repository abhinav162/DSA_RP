#include <bits/stdc++.h>
using namespace std;
int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    unordered_map<int, int> mp;

    // if the size of the array is 0 then we return 0
    if(nums.size() == 0)
        return 0;

    for (auto i : nums)
    {
        mp[i] = 1;
    }

    int ans = 0;

    for (auto i : nums)
    {
        // checking if i - 1 is present in the map or not, if present then we do not need to check for i as it will be already checked 
        if (mp.find(i - 1) != mp.end())
        {
            continue;
        }

        // if i - 1 is not present in the map then we check for the consecutive numbers
        int len = 0, current = i; // current is the current number we are checking for and if we find it then we increment the length by 1 and check for the next number i.e. current + 1 till we find the number which is not present in the map
        while (mp.find(current) != mp.end()) 
        {
            len++;
            current++;
        }
        ans = max(ans, len);
    }

    cout << ans;
    return 0;
}