#include <bits/stdc++.h>
using namespace std;

bool comparator(pair<int,int> &a, pair<int,int> &b)
{
    return (a.first * a.first + a.second*a.second) < (b.first * b.first + b.second*b.second);
}

int main() 
{ 
    // input output for files
    freopen("../input.txt","r",stdin); 
    freopen("../output.txt","w",stdout);

    //start code here
    vector<pair<int, int>> cord = {
        {1,3},{-2,2}
    };

    sort(cord.begin(), cord.end(), comparator);

    for(auto i : cord)
    {
        cout << i.first << " " << i.second << endl;
    }
    
    return 0 ; 
}