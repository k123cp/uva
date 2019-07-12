#include <iostream>
#include <vector>
#include <set>
#include <iomanip>
#include <algorithm>

using namespace std;

int main()
{
    int k, n;
    vector<int> ks, S;
    vector<vector<int>> sets;

    while (1)
    {
        cin >> k;
        if ( k == 0 )
            break;
        for( int i = 0; i < k; i++ )
        {
            cin >> n;
            S.push_back(n);
        }
        sets.push_back(S);
        S.clear();
    }
    for( int i = 0; i < sets.size(); i++ )
    {
        k = sets[i].size();
        for( int a = 0; a < k - 5; a++ )
            for( int b = a + 1; b < k - 4; b++ )
                for( int c = b + 1; c < k - 3; c++ )
                    for( int d = c + 1; d < k - 2; d++ )
                        for( int e = d + 1; e < k - 1; e++ )
                            for( int f = e + 1; f < k; f++ )
                                cout << sets[i][a] << " " << sets[i][b] << " "
                                << sets[i][c] << " " << sets[i][d] << " " << sets[i][e]
                                << " " << sets[i][f] << '\n';
        if ( i < sets.size() - 1 )
            cout << '\n';
    }
    return 0;
}
