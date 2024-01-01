#include <bits/stdc++.h>
using namespace std;
int maximumActivities(vector<int> &start, vector<int> &finish)
{
    vector<pair<int, int>> pairs;

    for (int i = 0; i < start.size(); i++)
    {
        pairs.push_back({start[i], finish[i]});
    }

    // sort(pairs.begin(), pairs.end());

    sort(pairs.begin(), pairs.end(), [](pair<int, int> a, pair<int, int> b) { return a.second < b.second; });

    int count = 1;
    int prev = 0;
    int newStart = 1;

    while (newStart < pairs.size())
    {
        if (pairs[newStart].first >= pairs[prev].second)
        {
            count++;
            prev = newStart;
            newStart++;
        }
        else
        {
            newStart++;
        }
    }

    return count;
}

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    vector<int> start = {8, 0, 8, 2, 14, 2, 9, 3, 5, 15};
    vector<int> finish = {20, 17, 13, 3, 19, 8, 13, 15, 20, 20};
    // vector<int> start = {1, 6, 2, 4};
    // vector<int> finish = {2, 7, 5, 8};

    cout << maximumActivities(start, finish) << endl;

    return 0;
}