#include <bits/stdc++.h>
using namespace std;

void printC(int i, int n, int k, vector<int> &temp)
{
    if(i == n)
    {
        if(temp.size() == k)
        {
            for(int i = 0; i < temp.size(); i++)
            {
                cout << temp[i] << " ";
            }
            cout << endl;
        }
        return;
    }

    temp.push_back(i + 1);
    printC(i + 1, n, k, temp);

    temp.pop_back();
    printC(i + 1, n, k, temp);
}

int main() 
{ 
    // input output for files
    freopen("../input.txt","r",stdin); 
    freopen("../output.txt","w",stdout);

    //start code here
    int n, k;
    cin >> n >> k;
    vector<int> temp;

    printC(0, n, k, temp);
    return 0 ; 
}