#include <bits/stdc++.h>
using namespace std;

void printNto1(int i, int n)
{
    if(i < n)
    {
        return;
    }

    cout << i << endl;

    printNto1(i-1,n);
}

int main() 
{ 
    // input output for files
    #define TxtIO 
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout);

    //start code here
    printNto1(5,1);
    return 0 ; 
}