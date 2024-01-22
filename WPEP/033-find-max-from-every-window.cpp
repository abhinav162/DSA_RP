#include <bits/stdc++.h>
using namespace std;
int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    vector<int> arr = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int k = 4;
    deque<int> dq;


    // process first window of size k
    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && arr[i] >= arr[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    // process rest of the windows by removing the elements which are not in the current window and adding the new elements by removing the smaller elements
    for (int i = k; i < arr.size(); i++)
    {
        cout << arr[dq.front()] << " "; // prints the max of the previous window

        if (!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_front();
        }

        while (!dq.empty() && arr[i] >= arr[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout << arr[dq.front()] << " "; // prints the max of the last window
    return 0;
}