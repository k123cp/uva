#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> ans;

int solve(vector<int> cd, int m, int n)
{
    if ( m == 0 ) return 0;
    int num = cd[m-1];
    if ( m == 1 )
        if ( num <= n )
            return num;
        else return 0;
    int subMax = solve(cd, m - 1, n); //solve for array with one fewer element
    if ( num > n ) return subMax; //if does not include last element

    int ma = num + solve(cd, m - 1, n - num); //possible soln including last element
    return max(ma, subMax); //contains cd[m-1] or not
}

int main()
{
    int m;
    while ( cin >> n )
    {
        cin >> m;
        vector<int> cd(m);
        for( int i = 0; i < m; i++ )
            cin >> cd[i];
        int res = solve(cd, m, n);
        //for( int i = 0; i < ans.size(); i++ )
        //    cout << ans[i] << " ";
        cout << "sum:" << res << endl;
        ans.clear();
    }
    return 0;
}
