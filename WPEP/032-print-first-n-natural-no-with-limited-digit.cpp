/*
Approach - Level Order Traversal

intuition -
    1. we will use queue to store the numbers
    2. Pop the front element and print it ifit is not zero and decrement n
    3. Push the front element * 10 + 1, front element * 10 + 2, front element * 10 + 3
    4. repeat these till n becomes zero

*/

#include <bits/stdc++.h>
using namespace std;
int main() 
{ 
    // input output for files
    freopen("../input.txt","r",stdin); 
    freopen("../output.txt","w",stdout);

    //start code here
    int n = 10;
    queue<int> q;
    q.push(0);

    while(n > 0)
    {
        int front = q.front();
        q.pop();

        if(front != 0)
        {
            cout << front << endl;
            n--;
        }

        q.push(front * 10 + 1);
        q.push(front * 10 + 2);
        q.push(front * 10 + 3);
    }
    return 0 ; 
}