#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <utility>

using namespace std;

int main()
{
    int a;

    while ( cin >> a )
    {
        int n = 1; long long prod = -10000000000;
        vector<long long> v;
        v.push_back(a);
        while ( cin >> a && a != -999999 )
        {
            n++;
            v.push_back(a);
        }
        vector<vector<long long>> memo( n+1, vector<long long>( n ) );
        //memo[len][pos] product of sequence of length len starting from v[pos]
        for( int i = 0; i < n; i++ ) //initialise the base case (all seq length 1)
        {
            memo[1][i] = v[i];
            prod = max(prod, v[i]);
        }

        for( int pos = 0; pos < n; pos++ )//calculate seq length > 1 
        {
            for( int len = 2; len <= n; len++ )
            {
                if ( len + pos > n ) break;
                memo[len][pos] = memo[len-1][pos] * memo[1][pos+len-1];
                prod = max(prod, memo[len][pos]);
            }
        }
        cout << prod << endl;
    }
    return 0;
}
