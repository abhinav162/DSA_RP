#include <bits/stdc++.h>
using namespace std;
int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    int n = 10;
    vector<int> dp(n + 1);
    dp[1] = 1;

    int i2 = 1, i3 = 1, i5 = 1;

    for (int i = 2; i < dp.size(); i++)
    {
        dp[i] = min({2*dp[i2] , 3*dp[i3], 5*dp[i5]});

        if(dp[i] == 2*dp[i2])
        {
            i2++;
        }
        if(dp[i] == 3*dp[i3])
        {
            i3++;
        }
        if(dp[i] == 5*dp[i5])
        {
            i5++;
        }
    }

    cout << dp[n];
    return 0;
}