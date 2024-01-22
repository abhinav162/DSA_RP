#include <bits/stdc++.h>
using namespace std;
int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    int n = 10;

    queue<string> q;
    q.push("1");

    vector<string> ans;

    for(int count = 0; count < n; count++)
    {
        string front = q.front();
        q.pop();

        ans.push_back(front);
        q.push(front + "0");
        q.push(front + "1");
    }

    for(auto i : ans)
    {
        cout << i << endl;
    }

    return 0;
}