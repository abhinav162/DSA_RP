#include <bits/stdc++.h>
using namespace std;

void printC(int n)
{
    if(n == 0)
    {
        return;
    }

    cout << n << endl;

    printC(n-1);
}

int main() 
{
    // input output for filesṇṇ
    #define TxtIO 
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout);
    
    // start code here
    printC(5);
    
    return 0 ; 
}