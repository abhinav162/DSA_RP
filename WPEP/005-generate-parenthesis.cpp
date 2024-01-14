#include <bits/stdc++.h>
using namespace std;

void generateParenthesis(int n, vector<char> res, int openCnt, int closeCnt)
{
    if (openCnt == n && closeCnt == n)
    {
        for (auto i : res)
        {
            cout << i;
        }
        cout << endl;
        return;
    }

    if (openCnt == n)
    {
        res.push_back(')');
        generateParenthesis(n, res, openCnt, closeCnt + 1);
    }
    else if (openCnt > closeCnt)
    {
        res.push_back('(');
        generateParenthesis(n, res, openCnt + 1, closeCnt);

        res.pop_back();
        res.push_back(')');
        generateParenthesis(n, res, openCnt, closeCnt + 1);
    }
    else
    {
        res.push_back('(');
        generateParenthesis(n, res, openCnt + 1, closeCnt);
    }
}

void generateParenthesis(int n, string res, int openCnt, int closeCnt, vector<string> &finalR)
{
    if (openCnt == n && closeCnt == n)
    {
        finalR.push_back(res);
        return;
    }

    if (openCnt == n)
    {
        res.push_back(')');
        generateParenthesis(n, res, openCnt, closeCnt + 1, finalR);
    }
    else if (openCnt > closeCnt)
    {
        res.push_back('(');
        generateParenthesis(n, res, openCnt + 1, closeCnt, finalR);

        res.pop_back();
        res.push_back(')');
        generateParenthesis(n, res, openCnt, closeCnt + 1, finalR);
    }
    else
    {
        res.push_back('(');
        generateParenthesis(n, res, openCnt + 1, closeCnt, finalR);
    }
}


//// optimal and easy approach
void generateParenthesisOpt(int openCnt, int closeCnt, string temp, vector<string> &res)
{
    if(openCnt == 0 && closeCnt == 0)
    {
        res.push_back(temp);
        return;
    }

    if(openCnt > 0)
    {
        generateParenthesisOpt(openCnt-1, closeCnt+1, temp+"(", res);
    }

    if(closeCnt > 0)
    {
        generateParenthesisOpt(openCnt, closeCnt-1, temp+")", res);
    }
}

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    int n = 3;
    vector<char> res;

    // generateParenthesis(n, res, 0, 0);

    string sres;
    vector<string> finalR;
    // generateParenthesis(n, sres, 0, 0, finalR);
    

    //// optimal and easy approach
    generateParenthesisOpt(n, 0, "", finalR);

    for (auto i : finalR)
    {
        cout << i << endl;
    }
    return 0;
}