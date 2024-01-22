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
    deque<int> maxDq;
    deque<int> minDq;


    // process first window of size k
    for (int i = 0; i < k; i++)
    {
        while (!maxDq.empty() && arr[i] >= arr[maxDq.back()])
        {
            maxDq.pop_back();
        }
        maxDq.push_back(i);

        while(!minDq.empty() && arr[i] <= arr[minDq.back()])
        {
            minDq.pop_back();
        }
        minDq.push_back(i);
    }

    // process rest of the windows by removing the elements which are not in the current window and adding the new elements by removing the smaller elements
    for (int i = k; i < arr.size(); i++)
    {
        cout << arr[maxDq.front()] + arr[minDq.front()] << " "; // prints the max of the previous window

        if (!maxDq.empty() && maxDq.front() <= i - k)
        {
            maxDq.pop_front();
        }

        if (!minDq.empty() && minDq.front() <= i - k)
        {
            minDq.pop_front();
        }

        while (!maxDq.empty() && arr[i] >= arr[maxDq.back()])
        {
            maxDq.pop_back();
        }
        maxDq.push_back(i);

        while(!minDq.empty() && arr[i] <= arr[minDq.back()])
        {
            minDq.pop_back();
        }
        minDq.push_back(i);
    }
    cout << arr[maxDq.front()] + arr[minDq.front()] << " "; // prints the max of the last window
    return 0;
}