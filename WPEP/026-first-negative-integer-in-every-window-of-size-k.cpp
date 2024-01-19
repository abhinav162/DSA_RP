/*
Approach -
    1 - create a q
    2 - initialize two pointers l and r to 0
    3 - iterate over the array from r to n
        3.1 - if arr[i] < 0 push r to q
        3.2 - check window size
            3.2.1 - if window size == k
            3.2.2 - check if q is not empty
                3.2.2.1 - if q is not empty then store arr[q.front()] in ans and if front element of q is equal to l then pop front element of q and increment l (sliding window)
            3.2.3 - if q is empty then store 0 in ans and increment l (sliding window)
    4 - return ans

*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    vector<long long> arr = {-8, 2, 3, -6, 10};
    int k = 2;
    int N = arr.size();

    queue<long long> q;
    vector<long long> ans;
    int l = 0;

    for (int r = 0; r < N; r++)
    {
        if(arr[r] < 0)
        {
            q.push(r); // storing index of negative elements in queue
        }

        if(r-l+1 == k)
        {
            if(!q.empty())
            {
                ans.push_back(arr[q.front()]);
                if(q.front() == l)
                {
                    q.pop();
                }
                l++;
            }
            else
            {
                ans.push_back(0);
                l++;
            }
        }
    }

    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}