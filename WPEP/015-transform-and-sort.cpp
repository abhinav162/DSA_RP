/*
QUESTION - trasform each element by applying the following function ax^2 + bx + c and sort the array

Approach - 
1. find the pivot point
2. apply the function on the pivot point
3. apply the function on the left side of the pivot point
4. apply the function on the right side of the pivot point
5. sort the array
*/

#include <bits/stdc++.h>
using namespace std;

int transform(int x, int a, int b, int c)
{
    return a * x * x + b * x + c * x;
}

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    vector<int> arr = {-1, 0, 1, 2, 3, 4};
    int a = -1;
    int b = 2;
    int c = -1;

    int pivot = -b / (2 * a);


    vector<int> res;

    return 0;
}