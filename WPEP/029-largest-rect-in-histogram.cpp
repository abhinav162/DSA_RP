/*
Approach - 1
    Brut Force Approach - O(n^2)
    for each building find the area of rectangle that can be formed with that building as the smallest building and return the maximum area

Approach - 2 - Optimal Approach - O(n)

Intuition:
    for each building we need to find the previous smaller building and the next smaller building
    then we can find the area of the rectangle with that building as the smallest building
    and return the maximum area

Algorithm:
    1. we will use two arrays prevLess and nextLess to store the index of the previous smaller building and the next smaller building
    2. we will use a stack to find the previous smaller building
        1. we will traverse the array from left to right
        2. if the stack is empty then we will push the current index in the stack
        3. if the stack is not empty then we will check if the current building is greater than the building at the top of the stack
            1. if the current building is greater than the building at the top of the stack then we will push the current index in the stack
            2. if the current building is not greater than the building at the top of the stack then we will pop the stack till the stack is not empty and the building at the top of the stack is greater than the current building
                1. if the stack becomes empty then we will push the current index in the stack
                2. if the stack is not empty then we will push the current index in the stack
    3. we will empty the stack
    4. Do the same thing as above but this time we will traverse the array from right to left
    5. now we have the previous smaller building and the next smaller building for each building
    6. we will find the area of the rectangle with each building as the smallest building and return the maximum area

    Time Complexity - O(n)
    Space Complexity - O(n)
*/

#include <bits/stdc++.h>
using namespace std;

// Optimal Approach - O(n)
int largestRectangleArea(vector<int> &h)
{
    int n = h.size();
    vector<int> prevLess(n), nextLess(n);
    stack<int> st;

    // for previous less
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && h[st.top()] >= h[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            prevLess[i] = -1; // -1 means that there is no previous less element (because array start from 0 and we can't have index -1))
        }
        else
        {
            prevLess[i] = st.top();
        }

        st.push(i);
    }

    while (!st.empty())
        st.pop();

    // for next less
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && h[st.top()] >= h[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            nextLess[i] = n;
        }
        else
        {
            nextLess[i] = st.top();
        }

        st.push(i);
    }

    int maxArea = 0;

    for (int i = 0; i < n; i++)
    {
        int a = h[i] * (nextLess[i] - prevLess[i] - 1);
        maxArea = max(maxArea, a);
    }

    return maxArea;
}

int buildingGreaterThan(vector<int>, int);
// Brut Force Approach - O(n^2)
int largestRectangleAreaBrut(vector<int> h)
{
    int totalBuildings = h.size() - 1;

    int maxArea = INT_MIN;

    for (int i = 0; i <= totalBuildings; i++)
    {
        int rarea = h[i] * buildingGreaterThan(h, i);

        if (rarea > maxArea)
            maxArea = rarea;
    }

    return maxArea;
}

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    vector<int> histogram = {2, 1, 5, 6, 2, 3};
    cout << largestRectangleArea(histogram);
    return 0;
}

// helper function for brut force approach to find the number of buildings greater than the current building
int buildingGreaterThan(vector<int> h, int index)
{
    int totalBuildings = h.size() - 1;
    int count = 0;

    for (int i = index; i >= 0; i--)
    {
        if (h[i] >= h[index])
            count++;
        else
            break;
    }

    for (int i = index + 1; i <= totalBuildings; i++)
    {
        if (h[i] >= h[index])
            count++;
        else
            break;
    }

    if (count > 0)
        return count;
    else
        return 1;
}